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

#include <genepy/exception/exception_macros.h>

#include "TestException.h"

void TestException::testMacro()
{
    try {
        GENEPY_THROW_EXCEPTION_IF(false, "Test")
        QVERIFY(true);
    }
    catch (const std::exception& e) {
        QVERIFY(false);
        Q_UNUSED(e)
    }

    try {
        GENEPY_THROW_EXCEPTION_IF(true, "Test")
        QVERIFY(false);
    }
    catch (const std::exception& e) {
        QVERIFY(true);
        QCOMPARE(QString{e.what()}, QStringLiteral("Exception TestException.cpp:36: Test"));
    }
}

QTEST_MAIN(TestException)
