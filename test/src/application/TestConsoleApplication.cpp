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

#include "TestConsoleApplication.h"

#include <genepy/application/ConsoleApplication.h>

#include "../common.h"

void TestConsoleApplication::initTestCase()
{
    expectedPreferenceDir_ = QDir{common::kDummyApplicationPreferenceDirectoryPath};

    if (expectedPreferenceDir_.exists()) {
        expectedPreferenceDir_.removeRecursively();
    }
}

void TestConsoleApplication::cleanupTestCase()
{
    if (expectedPreferenceDir_.exists()) {
        expectedPreferenceDir_.removeRecursively();
    }
}

void TestConsoleApplication::testConstructor()
{
    QVERIFY(!expectedPreferenceDir_.exists());

    EXTRACT_ARGC_ARGV("./test")

    const genepy::ConsoleApplication app{common::kDummyApplicationInformation, argc, argv};

    QCOMPARE(genepy::ConsoleApplication::applicationName(), common::kDummyApplicationName);
    QCOMPARE(genepy::ConsoleApplication::applicationVersion(),
             common::kDummyApplicationVersion.toString());
    QCOMPARE(app.getDescription(), common::kDummyApplicationDescription);

    const auto preferenceDir = app.getPreferenceDirectory();

    QVERIFY(preferenceDir.exists());
    QCOMPARE(preferenceDir.path(), expectedPreferenceDir_.path());
}

QTEST_APPLESS_MAIN(TestConsoleApplication)
