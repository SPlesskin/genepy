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

#include "TestProgressBar.h"

void TestProgressBar::testUpdate()
{
    QProcess process;
    process.start(QStringLiteral("./progressbar_test_helper"), QStringList{});

    QVERIFY(process.waitForFinished(5000));
    QCOMPARE(process.exitStatus(), QProcess::NormalExit);
    QCOMPARE(process.exitCode(), 0);

    const QString output = process.readAll();

#ifdef Q_OS_WIN
    const auto expectedOutput = QStringLiteral("\r[====                ] 1/5 20%"
                                               "\r[========            ] 2/5 40%"
                                               "\r[============        ] 3/5 60%"
                                               "\r[================    ] 4/5 80%"
                                               "\r[====================] 5/5 100%\r\n");
#else
    const auto expectedOutput = QStringLiteral("\r[====                ] 1/5 20%"
                                               "\r[========            ] 2/5 40%"
                                               "\r[============        ] 3/5 60%"
                                               "\r[================    ] 4/5 80%"
                                               "\r[====================] 5/5 100%\n");
#endif

    QCOMPARE(output, expectedOutput);
}

QTEST_APPLESS_MAIN(TestProgressBar)
