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

#include "TestGuiApplication.h"

#include <genepy/application/GuiApplication.h>

#include "../common.h"

void TestGuiApplication::initTestCase()
{
    expectedPreferenceDir_ = QDir{common::kDummyApplicationPreferenceDirectoryPath};

    if (expectedPreferenceDir_.exists()) {
        expectedPreferenceDir_.removeRecursively();
    }
}

void TestGuiApplication::cleanupTestCase()
{
    if (expectedPreferenceDir_.exists()) {
        expectedPreferenceDir_.removeRecursively();
    }
}

void TestGuiApplication::testConstructor()
{
    QVERIFY(!expectedPreferenceDir_.exists());

    EXTRACT_ARGC_ARGV("./test")

    const genepy::GuiApplication app{common::kDummyApplicationInformation, argc, argv};

    QCOMPARE(genepy::GuiApplication::applicationName(), common::kDummyApplicationName);
    QCOMPARE(genepy::GuiApplication::applicationVersion(),
             common::kDummyApplicationVersion.toString());
    QCOMPARE(app.getDescription(), common::kDummyApplicationDescription);

    const auto preferenceDir = app.getPreferenceDirectory();

    QVERIFY(preferenceDir.exists());
    QCOMPARE(preferenceDir.path(), expectedPreferenceDir_.path());
}

QTEST_APPLESS_MAIN(TestGuiApplication)
