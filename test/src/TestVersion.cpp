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

#include "TestVersion.h"

#include <genepy/version.h>

void TestVersion::testVersion()
{
    const auto segments = genepy::kVersion.segments();

    QCOMPARE(segments.size(), 3);
    QVERIFY(std::all_of(std::cbegin(segments), std::cend(segments), [](int n) { return n >= 0; }) &&
            std::any_of(std::cbegin(segments), std::cend(segments), [](int n) { return n >= 1; }));
}

void TestVersion::testVersionBuildDatetime() { QVERIFY(genepy::kVersionBuildDatetime.isValid()); }

QTEST_APPLESS_MAIN(TestVersion)
