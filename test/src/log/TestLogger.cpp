/* Genepy - A General-Purpose Library
 * Copyright (C) 2020, 2021  Erwan Grâce <erwan.grace@outlook.fr>
 *
 * This file is part of Genepy.
 *
 * Genepy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Genepy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Genepy.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <genepy/log/Logger.h>

#include "../common.h"
#include "TestLogger.h"

namespace {

const auto kLoggerName = QStringLiteral("TestLogger");

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
    const char* argument = "./test";

    int argc = 1;
    char** argv = new char*[argc + 1];
    argv[0] = new char[strlen(argument) + 1];
#ifndef Q_CC_GNU
    strcpy_s(argv[0], strlen(argument) + 1, argument);
#else
    strcpy(argv[0], argument);
#endif
    argv[1] = nullptr;

    application_ = std::make_unique<genepy::ConsoleApplication>(
        common::kDummyApplicationName, common::kDummyApplicationVersion, argc, argv);

    expectedLogDir_.setPath(application_->getPreferenceDirectory().path() + "/log");
    expectedLogFileName_ = common::kDummyApplicationName.toLower() + ".log";
}

void TestLogger::cleanupTestCase()
{
    if (application_->getPreferenceDirectory().exists()) {
        if (!application_->getPreferenceDirectory().removeRecursively()) {
            qWarning() << "Can't delete directory" << application_->getPreferenceDirectory().path();
        }
    }
}

void TestLogger::testInitialize()
{
    QVERIFY(!expectedLogDir_.exists());

    // Create a logger and try to log a message
    genepy::Logger logger{kLoggerName};
    logger.log(genepy::LogLevel::kInfo, "Message", true);

    // Check that the log folder doesn't exist
    QVERIFY(!expectedLogDir_.exists());

    genepy::Logger::initialize(application_.get());

    // Verify that the log folder is available this time
    QVERIFY(expectedLogDir_.exists());
    QVERIFY(expectedLogDir_.exists(expectedLogFileName_));
}

void TestLogger::testLog_data()
{
    QTest::addColumn<int>("lineNo");
    QTest::addColumn<QString>("expectedLinePattern");

    genepy::Logger logger{kLoggerName};

    auto lineNo = 1;
    auto patternPrefix = QStringLiteral("^\\d{2}/\\d{2}/\\d{4} \\d{2}:\\d{2}:\\d{2}\\.\\d{3}");

    {
        const auto message = QStringLiteral("Trace message");

        logger.log(genepy::LogLevel::kTrace, message, true);

#ifdef QT_DEBUG
        QTest::newRow("trace message")
            << lineNo++
            << QString{patternPrefix + " TRACE \\[" + kLoggerName + "\\] " + message + '$'};
#endif
    }

    {
        const auto message = QStringLiteral("Debug message");

        logger.log(genepy::LogLevel::kDebug, message, true);

#ifdef QT_DEBUG
        QTest::newRow("debug message")
            << lineNo++
            << QString{patternPrefix + " DEBUG \\[" + kLoggerName + "\\] " + message + '$'};
#endif
    }

    {
        const auto message = QStringLiteral("Info message");

        logger.log(genepy::LogLevel::kInfo, message, true);

        QTest::newRow("info message")
            << lineNo++
            << QString{patternPrefix + " INFO\\s{2}\\[" + kLoggerName + "\\] " + message + '$'};
    }

    {
        const auto message = QStringLiteral("Warn message");

        logger.log(genepy::LogLevel::kWarn, message, true);

        QTest::newRow("warn message")
            << lineNo++
            << QString{patternPrefix + " WARN\\s{2}\\[" + kLoggerName + "\\] " + message + '$'};
    }

    {
        const auto message = QStringLiteral("Error message");

        logger.log(genepy::LogLevel::kError, message, true);

        QTest::newRow("error message")
            << lineNo++
            << QString{patternPrefix + " ERROR \\[" + kLoggerName + "\\] " + message + '$'};
    }

    {
        const auto message = QStringLiteral("Fatal message");

        logger.log(genepy::LogLevel::kFatal, message, true);

        QTest::newRow("fatal message")
            << lineNo++
            << QString{patternPrefix + " FATAL \\[" + kLoggerName + "\\] " + message + '$'};
    }
}

void TestLogger::testLog()
{
    QFETCH(int, lineNo);
    QFETCH(QString, expectedLinePattern);

    const auto line = readLine(expectedLogDir_.path() + '/' + expectedLogFileName_, lineNo);

    qDebug() << QString{"Line %1: %2"}.arg(lineNo).arg(line);

    QVERIFY(QRegExp{expectedLinePattern}.exactMatch(line));
}

QTEST_APPLESS_MAIN(TestLogger)
