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

#include "TestLocalLogger.h"

#include <genepy/application/ConsoleApplication.h>
#include <genepy/log/logging_macros.h>

#include "../common.h"

void TestLocalLogger::initTestCase()
{
    // On Windows 10, QDir::removeRecursively() fails to erase non-empty folders. So, we call it
    // here to secure the deletion before executing the tests.
    QVERIFY(common::kLogDirectory.removeRecursively());
}

void TestLocalLogger::cleanupTestCase()
{
    if (!common::kLogDirectory.removeRecursively()) {
        qWarning() << "Can't delete directory" << common::kLogDirectory.path();
    }
}

void TestLocalLogger::testInitialize()
{
    EXTRACT_ARGC_ARGV("./myapplication")

    genepy::ConsoleApplication app{common::kApplicationInformation, argc, argv};

    genepy::Logger::initialize(&app);

    QVERIFY(common::kLogDirectory.exists());
    QVERIFY(common::kLogDirectory.exists(common::kLogFileName));
    QVERIFY(QFile{common::kLogDirectory.filePath(common::kLogFileName)}.size() == 0);
}

void TestLocalLogger::testMacros_data()
{
    QTest::addColumn<int>("lineNo");
    QTest::addColumn<QString>("expectedLinePattern");

    const auto loggerName = QStringLiteral("TestLocalLogger");

    GENEPY_DEFINE_LOCAL_LOGGER(logger, loggerName)

    auto lineNo = 1;
    const auto patternPrefix =
        QStringLiteral("^\\d{2}/\\d{2}/\\d{4} \\d{2}:\\d{2}:\\d{2}\\.\\d{3}");

    {
        const auto message = QStringLiteral("Trace message");

        GENEPY_LOG_TRACE(logger, message)

#ifdef QT_DEBUG
        QTest::newRow("trace message")
            << lineNo++
            << QString{patternPrefix + " TRACE \\[" + loggerName + "\\] " + message + '$'};
#endif
    }

    {
        const auto message = QStringLiteral("Debug message");

        GENEPY_LOG_DEBUG(logger, message)

#ifdef QT_DEBUG
        QTest::newRow("debug message")
            << lineNo++
            << QString{patternPrefix + " DEBUG \\[" + loggerName + "\\] " + message + '$'};
#endif
    }

    {
        const auto message = QStringLiteral("Info message");

        GENEPY_LOG_INFO(logger, message)

        QTest::newRow("info message")
            << lineNo++
            << QString{patternPrefix + " INFO\\s{2}\\[" + loggerName + "\\] " + message + '$'};
    }

    {
        const auto message = QStringLiteral("Warn message");

        GENEPY_LOG_WARN(logger, message)

        QTest::newRow("warn message")
            << lineNo++
            << QString{patternPrefix + " WARN\\s{2}\\[" + loggerName + "\\] " + message + '$'};
    }

    {
        const auto message = QStringLiteral("Error message");

        GENEPY_LOG_ERROR(logger, message)

        QTest::newRow("error message")
            << lineNo++
            << QString{patternPrefix + " ERROR \\[" + loggerName + "\\] " + message + '$'};
    }

    {
        const auto message = QStringLiteral("Fatal message");

        GENEPY_LOG_FATAL(logger, message)

        QTest::newRow("fatal message")
            << lineNo++
            << QString{patternPrefix + " FATAL \\[" + loggerName + "\\] " + message + '$'};
    }
}

void TestLocalLogger::testMacros()
{
    QFETCH(int, lineNo);
    QFETCH(QString, expectedLinePattern);

    const auto line =
        common::readFileLine(common::kLogDirectory.filePath(common::kLogFileName), lineNo);

    qDebug() << QString{"Line %1: %2"}.arg(lineNo).arg(line);

    QVERIFY(QRegExp{expectedLinePattern}.exactMatch(line));
}

QTEST_APPLESS_MAIN(TestLocalLogger)
