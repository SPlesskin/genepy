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

#include "TestApplicationPreferenceDirectory.h"

#include <genepy/application/ApplicationPreferenceDirectory.h>

#include "../common.h"

void TestApplicationPreferenceDirectory::initTestCase()
{
    expectedDir_ = QDir{common::kApplicationPreferenceDirectoryPath};

    QVERIFY(expectedDir_.removeRecursively());
}

void TestApplicationPreferenceDirectory::cleanupTestCase() { expectedDir_.removeRecursively(); }

void TestApplicationPreferenceDirectory::testConstructor()
{
    try {
        const auto dir = genepy::ApplicationPreferenceDirectory{common::kApplicationName,
                                                                common::kApplicationVersion};

        QVERIFY(dir.exists());
        QCOMPARE(dir.path(), expectedDir_.path());
    }
    catch (const std::exception& e) {
        QVERIFY(false);

        Q_UNUSED(e)
    }
}

QTEST_APPLESS_MAIN(TestApplicationPreferenceDirectory)
