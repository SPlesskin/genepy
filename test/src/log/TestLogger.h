/* Genepy - A General-Purpose Library
 * Copyright (C) 2020  Erwan Grâce <erwan.grace@outlook.fr>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef TESTLOGGER_H
#define TESTLOGGER_H

#include <QtTest/QtTest>

class TestLogger : public QObject {

    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testInitialize();
    void testLog_data();
    void testLog();

private:
    QDir workingDir_;
    QString logFilePath_;
};

#endif // TESTLOGGER_H
