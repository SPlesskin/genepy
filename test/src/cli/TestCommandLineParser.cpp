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

#include "TestCommandLineParser.h"

#include <genepy/application/ConsoleApplication.h>
#include <genepy/cli/CommandLineParserBuilder.h>

#include "../common.h"

namespace {

const auto kProgramInvocation = QStringLiteral("./commandlineparser_test_helper");

const char kHelpInformation[] = "Usage: ./commandlineparser_test_helper [options] <argument>\n"
                                "This is a dummy application.\n\n"
                                "Options:\n"
                                "  -h, --help     Displays this help.\n"
                                "  -v, --version  Displays version information.\n\n"
                                "Arguments:\n"
                                "  argument       A mandatory argument.\n";

} // namespace

void TestCommandLineParser::cleanupTestCase()
{
    auto dir = QDir{common::kDummyApplicationPreferenceDirectoryPath};

    if (dir.exists()) {
        dir.removeRecursively();
    }
}

void TestCommandLineParser::testStandardOptions_data()
{
    QTest::addColumn<QString>("option");
    QTest::addColumn<QString>("expectedOutput");

    {
        const auto expectedOutput = common::kDummyApplicationName + ' ' +
                                    common::kDummyApplicationVersion.toString() + '\n';

        QTest::newRow("version option") << QStringLiteral("-v") << expectedOutput;
    }

    QTest::newRow("help option") << QStringLiteral("-h") << kHelpInformation;
}

void TestCommandLineParser::testStandardOptions()
{
    QFETCH(QString, option);
    QFETCH(QString, expectedOutput);

    QProcess process;
    process.start(kProgramInvocation, QStringList{} << option);

    QVERIFY(process.waitForFinished(5000));
    QCOMPARE(process.exitStatus(), QProcess::NormalExit);
    QCOMPARE(process.exitCode(), 0);

    const QString output = process.readAll();

    QCOMPARE(output, expectedOutput);
}

void TestCommandLineParser::testMandatoryArgument()
{
    EXTRACT_ARGC_ARGV("./test .")

    const genepy::ConsoleApplication app{common::kDummyApplicationInformation, argc, argv};

    genepy::CommandLineParser parser = genepy::CommandLineParser::create(app).addArgument(
        QStringLiteral("path"), QStringLiteral("A directory path."), QStringLiteral("<path>"));

    parser.doParsing();

    QCOMPARE(parser.getArgumentValue<QString>(QStringLiteral("path")), QStringLiteral("."));
    QCOMPARE(parser.getArgumentValue<QDir>(QStringLiteral("path")), QDir{QStringLiteral(".")});
}

void TestCommandLineParser::testMissingMandatoryArgument()
{
    QProcess process;
    process.start(kProgramInvocation);

    QVERIFY(process.waitForFinished(5000));
    QCOMPARE(process.exitStatus(), QProcess::NormalExit);
    QCOMPARE(process.exitCode(), 1);

    const QString output = process.readAll();

    const auto expectedOutput =
        QString{"Incorrect number of arguments passed (expected 1, got 0).\n\n"} + kHelpInformation;

    QCOMPARE(output, expectedOutput);
}

void TestCommandLineParser::testBooleanOption()
{
    {
        EXTRACT_ARGC_ARGV("./test")

        const genepy::ConsoleApplication app{common::kDummyApplicationInformation, argc, argv};

        genepy::CommandLineParser parser = genepy::CommandLineParser::create(app).addOption(
            QStringList{} << QStringLiteral("b") << QStringLiteral("boolean"),
            QStringLiteral("A boolean option."));

        parser.doParsing();

        QVERIFY(!parser.isOptionPresent(QStringLiteral("b")));
        QVERIFY(!parser.isOptionPresent(QStringLiteral("boolean")));
    }

    {
        EXTRACT_ARGC_ARGV("./test -b")

        const genepy::ConsoleApplication app{common::kDummyApplicationInformation, argc, argv};

        genepy::CommandLineParser parser = genepy::CommandLineParser::create(app).addOption(
            QStringList{} << QStringLiteral("b") << QStringLiteral("boolean"),
            QStringLiteral("A boolean option."));

        parser.doParsing();

        QVERIFY(parser.isOptionPresent(QStringLiteral("b")));
        QVERIFY(parser.isOptionPresent(QStringLiteral("boolean")));
    }
}

void TestCommandLineParser::testValueOption()
{
    {
        EXTRACT_ARGC_ARGV("./test")

        const genepy::ConsoleApplication app{common::kDummyApplicationInformation, argc, argv};

        genepy::CommandLineParser parser = genepy::CommandLineParser::create(app).addOption(
            QStringList{} << QStringLiteral("o") << QStringLiteral("option"),
            QStringLiteral("A value option."), QStringLiteral("value"));

        parser.doParsing();

        QVERIFY(!parser.isOptionPresent(QStringLiteral("o")));
        QVERIFY(parser.getOptionValue<QString>(QStringLiteral("o")).isEmpty());
    }

    {
        EXTRACT_ARGC_ARGV("./test -o=foo")

        const genepy::ConsoleApplication app{common::kDummyApplicationInformation, argc, argv};

        genepy::CommandLineParser parser = genepy::CommandLineParser::create(app).addOption(
            QStringList{} << QStringLiteral("o") << QStringLiteral("option"),
            QStringLiteral("A value option."), QStringLiteral("value"));

        parser.doParsing();

        QVERIFY(parser.isOptionPresent(QStringLiteral("o")));
        QCOMPARE(parser.getOptionValue<QString>(QStringLiteral("o")), QStringLiteral("foo"));
    }
}

QTEST_APPLESS_MAIN(TestCommandLineParser)
