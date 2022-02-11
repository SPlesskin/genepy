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

#ifndef TESTCLASSLOGGER_H
#define TESTCLASSLOGGER_H

#include <QtTest/QtTest>

#include <genepy/log/logging_macros.h>

class TestClassLogger : public QObject {

    Q_OBJECT

private:
    GENEPY_DECLARE_CLASS_LOGGER(logger)

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testInitialize();
    void testMacros_data();
    void testMacros();
};

#endif // TESTCLASSLOGGER_H
