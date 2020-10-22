/* Genepy - A General-Purpose Library
 * Copyright (C) 2020  Erwan Grâce <erwan.grace@outlook.fr>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "TestLogger.h"

#include <genepy/log/Logger.h>

namespace {

const auto kAppName = QStringLiteral("TestLogger");
const auto kAppVersion = QVersionNumber{1, 2, 3};

QString readLine(const QString& filePath, int lineNo)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return QString{};
    }

    QTextStream stream{&file};
    auto i = 1;
    while (!stream.atEnd()) {
        const auto line = stream.readLine();
        if (i++ == lineNo) {
            return line;
        }
    }

    return QString{};
}

} // namespace

void TestLogger::initTestCase()
{
    // Create a logger and try to log a message...
    genepy::Logger logger{"TestLogger"};
    logger.log(genepy::LogLevel::kInfo, "Some test message", true);

    // Check that the log file doesn't exist
    workingDir_.setPath(QDir::homePath() + "/." + kAppName.toLower());

    QVERIFY(!workingDir_.exists());

    logFilePath_ = kAppVersion.toString() + "/log/" + kAppName.toLower() + ".log";

    QVERIFY(!workingDir_.exists(logFilePath_)); // Obvious
}

void TestLogger::cleanupTestCase() { QVERIFY(workingDir_.removeRecursively()); }

void TestLogger::testInitialize()
{
    genepy::Logger::initialize(kAppName, kAppVersion);

    // Verify that the log file is available this time
    QVERIFY(workingDir_.exists());
    QVERIFY(workingDir_.exists(logFilePath_));
}

void TestLogger::testLog_data()
{
    QTest::addColumn<int>("lineNo");
    QTest::addColumn<QString>("expectedLinePattern");

    genepy::Logger logger{"TestLogger"};

    auto lineNo = 1;
    auto patternPrefix = QStringLiteral("^\\d{2}/\\d{2}/\\d{4} \\d{2}:\\d{2}:\\d{2}\\.\\d{3}");

    {
        const auto message = QStringLiteral("Some trace message");

        logger.log(genepy::LogLevel::kTrace, message, true);

#ifdef QT_DEBUG
        QTest::newRow("trace message")
            << lineNo++ << QString{patternPrefix + " TRACE \\[TestLogger\\] " + message + '$'};
#endif
    }

    {
        const auto message = QStringLiteral("Some debug message");

        logger.log(genepy::LogLevel::kDebug, message, true);

#ifdef QT_DEBUG
        QTest::newRow("debug message")
            << lineNo++ << QString{patternPrefix + " DEBUG \\[TestLogger\\] " + message + '$'};
#endif
    }

    {
        const auto message = QStringLiteral("Some info message");

        logger.log(genepy::LogLevel::kInfo, message, true);

        QTest::newRow("info message")
            << lineNo++ << QString{patternPrefix + " INFO\\s{2}\\[TestLogger\\] " + message + '$'};
    }

    {
        const auto message = QStringLiteral("Some warn message");

        logger.log(genepy::LogLevel::kWarn, message, true);

        QTest::newRow("warn message")
            << lineNo++ << QString{patternPrefix + " WARN\\s{2}\\[TestLogger\\] " + message + '$'};
    }

    {
        const auto message = QStringLiteral("Some error message");

        logger.log(genepy::LogLevel::kError, message, true);

        QTest::newRow("error message")
            << lineNo++ << QString{patternPrefix + " ERROR \\[TestLogger\\] " + message + '$'};
    }

    {
        const auto message = QStringLiteral("Some fatal message");

        logger.log(genepy::LogLevel::kFatal, message, true);

        QTest::newRow("fatal message")
            << lineNo++ << QString{patternPrefix + " FATAL \\[TestLogger\\] " + message + '$'};
    }
}

void TestLogger::testLog()
{
    QFETCH(int, lineNo);
    QFETCH(QString, expectedLinePattern);

    const auto line = readLine(workingDir_.path() + '/' + logFilePath_, lineNo);

    qDebug() << QString{"Line %1: %2"}.arg(lineNo).arg(line);

    QVERIFY(QRegExp{expectedLinePattern}.exactMatch(line));
}

QTEST_MAIN(TestLogger)
