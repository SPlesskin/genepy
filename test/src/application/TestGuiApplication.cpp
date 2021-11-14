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

#include <genepy/application/GuiApplication.h>

#include "../common.h"
#include "TestGuiApplication.h"

void TestGuiApplication::testConstructor()
{
    const auto expectedPreferenceDir = QDir{common::kDummyApplicationPreferenceDirectoryPath};

    QVERIFY(!expectedPreferenceDir.exists());

    const char* argument = "./test";

    int argc = 1;
    char** argv = new char*[argc + 1];
    argv[0] = new char[strlen(argument) + 1];
    strcpy(argv[0], argument);
    argv[1] = nullptr;

    genepy::GuiApplication app{common::kDummyApplicationName, common::kDummyApplicationVersion,
                               argc, argv};

    QCOMPARE(genepy::GuiApplication::applicationName(), common::kDummyApplicationName);
    QCOMPARE(genepy::GuiApplication::applicationVersion(),
             common::kDummyApplicationVersion.toString());

    auto preferenceDir = app.getPreferenceDirectory();

    QVERIFY(preferenceDir.exists());
    QCOMPARE(preferenceDir.path(), expectedPreferenceDir.path());

    // Clean-up the test function
    preferenceDir.cdUp();
    if (!preferenceDir.removeRecursively()) {
        qDebug() << "Can't remove directory" << preferenceDir.path();
    }
}

QTEST_APPLESS_MAIN(TestGuiApplication)
