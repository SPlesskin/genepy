/* Genepy - A General-Purpose Library
 * Copyright (C) 2020-2022  Erwan Grâce <erwan.grace@outlook.fr>
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

#include "TestCommandLineParser.h"

#include <genepy/application/ConsoleApplication.h>
#include <genepy/cli/CommandLineParserBuilder.h>

#include "../common.h"

namespace {

const auto kProgramInvocation = QStringLiteral("./commandlineparser_test_helper");

#ifdef Q_OS_WIN
const char kHelpInformation[] = "Usage: .\\commandlineparser_test_helper [options] <path>\r\n"
                                "This is my application.\r\n\r\n"
                                "Options:\r\n"
                                "  -?, -h, --help  Displays help on commandline options.\r\n"
                                "  --help-all      Displays help including Qt specific options.\r\n"
                                "  -v, --version   Displays version information.\r\n\r\n"
                                "Arguments:\r\n"
                                "  path            A directory path.\r\n";
#else
const char kHelpInformation[] = "Usage: ./commandlineparser_test_helper [options] <path>\n"
                                "This is my application.\n\n"
                                "Options:\n"
                                "  -h, --help     Displays this help.\n"
                                "  -v, --version  Displays version information.\n\n"
                                "Arguments:\n"
                                "  path           A directory path.\n";
#endif

} // namespace

void TestCommandLineParser::testStandardOptions_data()
{
    QTest::addColumn<QStringList>("arguments");
    QTest::addColumn<QString>("expectedOutput");

    {
#ifdef Q_OS_WIN
        const auto expectedOutput =
            common::kApplicationName + ' ' + common::kApplicationVersion.toString() + "\r\n";
#else
        const auto expectedOutput =
            common::kApplicationName + ' ' + common::kApplicationVersion.toString() + '\n';
#endif

        QTest::newRow("version option") << QStringList{QStringLiteral("-v")} << expectedOutput;
    }

    QTest::newRow("help option") << QStringList{QStringLiteral("-h")} << kHelpInformation;
}

void TestCommandLineParser::testStandardOptions()
{
    QFETCH(QStringList, arguments);
    QFETCH(QString, expectedOutput);

    QProcess process;
    process.start(kProgramInvocation, arguments);

    QVERIFY(process.waitForFinished(5000));
    QCOMPARE(process.exitStatus(), QProcess::NormalExit);
    QCOMPARE(process.exitCode(), 0);

    const QString output = process.readAll();

    QCOMPARE(output, expectedOutput);
}

void TestCommandLineParser::testMandatoryArgument()
{
    {
        EXTRACT_ARGC_ARGV("./myapplication .")

        const genepy::ConsoleApplication app{common::kApplicationInformation, argc, argv};

        genepy::CommandLineParser parser = genepy::CommandLineParser::create(app).addArgument(
            QStringLiteral("path"), QStringLiteral("A directory path."), QStringLiteral("<path>"));

        parser.doParsing();

        QCOMPARE(parser.getArgumentValue<QString>(QStringLiteral("path")), QStringLiteral("."));
        QCOMPARE(parser.getArgumentValue<QDir>(QStringLiteral("path")), QDir{QStringLiteral(".")});
    }

    {
        QProcess process;
        process.start(kProgramInvocation, QStringList{});

        QVERIFY(process.waitForFinished(5000));
        QCOMPARE(process.exitStatus(), QProcess::NormalExit);
        QCOMPARE(process.exitCode(), 1);

        const QString output = process.readAll();

#ifdef Q_OS_WIN
        const auto expectedOutput =
            QString{"Incorrect number of arguments passed (expected 1, got 0).\r\n\r\n"} +
            kHelpInformation;
#else
        const auto expectedOutput =
            QString{"Incorrect number of arguments passed (expected 1, got 0).\n\n"} +
            kHelpInformation;
#endif

        QCOMPARE(output, expectedOutput);
    }
}

void TestCommandLineParser::testBooleanOption()
{
    const auto names = QStringList{QStringLiteral("q"), QStringLiteral("quiet")};
    const auto description = QStringLiteral("Do not output any message.");

    {
        EXTRACT_ARGC_ARGV("./myapplication")

        const genepy::ConsoleApplication app{common::kApplicationInformation, argc, argv};

        genepy::CommandLineParser parser =
            genepy::CommandLineParser::create(app).addOption(names, description);

        parser.doParsing();

        QVERIFY(!parser.isOptionPresent(QStringLiteral("q")));
        QVERIFY(!parser.isOptionPresent(QStringLiteral("quiet")));
    }

    {
        EXTRACT_ARGC_ARGV("./myapplication -q")

        const genepy::ConsoleApplication app{common::kApplicationInformation, argc, argv};

        genepy::CommandLineParser parser =
            genepy::CommandLineParser::create(app).addOption(names, description);

        parser.doParsing();

        QVERIFY(parser.isOptionPresent(QStringLiteral("q")));
        QVERIFY(parser.isOptionPresent(QStringLiteral("quiet")));
    }
}

void TestCommandLineParser::testValueOption()
{
    const auto names = QStringList{QStringLiteral("l"), QStringLiteral("log-level")};
    const auto description = QStringLiteral("Set the log output verbosity.");
    const auto valueName = QStringLiteral("level");

    {
        EXTRACT_ARGC_ARGV("./myapplication")

        const genepy::ConsoleApplication app{common::kApplicationInformation, argc, argv};

        genepy::CommandLineParser parser =
            genepy::CommandLineParser::create(app).addOption(names, description, valueName);

        parser.doParsing();

        QVERIFY(!parser.isOptionPresent(QStringLiteral("l")));
        QVERIFY(!parser.isOptionPresent(QStringLiteral("log-level")));
        QVERIFY(parser.getOptionValue<QString>(QStringLiteral("l")).isEmpty());
        QVERIFY(parser.getOptionValue<QString>(QStringLiteral("log-level")).isEmpty());
    }

    {
        EXTRACT_ARGC_ARGV("./myapplication -l debug")

        const genepy::ConsoleApplication app{common::kApplicationInformation, argc, argv};

        genepy::CommandLineParser parser =
            genepy::CommandLineParser::create(app).addOption(names, description, valueName);

        parser.doParsing();

        QVERIFY(parser.isOptionPresent(QStringLiteral("l")));
        QVERIFY(parser.isOptionPresent(QStringLiteral("log-level")));
        QCOMPARE(parser.getOptionValue<QString>(QStringLiteral("l")), QStringLiteral("debug"));
        QCOMPARE(parser.getOptionValue<QString>(QStringLiteral("log-level")),
                 QStringLiteral("debug"));
    }
}

QTEST_APPLESS_MAIN(TestCommandLineParser)
