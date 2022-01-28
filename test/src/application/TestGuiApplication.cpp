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
    expectedPreferenceDir_ = std::make_unique<genepy::ApplicationPreferenceDirectory>(
        common::kApplicationName, common::kApplicationVersion);
}

void TestGuiApplication::cleanupTestCase() { expectedPreferenceDir_->removeRecursively(); }

void TestGuiApplication::testConstructor()
{
    EXTRACT_ARGC_ARGV("./myapplication")

    const genepy::GuiApplication app{common::kApplicationInformation, argc, argv};

    QCOMPARE(genepy::GuiApplication::applicationName(), common::kApplicationName);
    QCOMPARE(genepy::GuiApplication::applicationVersion(), common::kApplicationVersion.toString());
    QCOMPARE(app.getDescription(), common::kApplicationDescription);
    QCOMPARE(app.getPreferenceDirectory(), *expectedPreferenceDir_);
}

QTEST_APPLESS_MAIN(TestGuiApplication)
