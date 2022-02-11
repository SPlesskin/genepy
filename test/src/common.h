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

#ifndef COMMON_H
#define COMMON_H

#include <QtCore/QDir>

#include <genepy/application/ApplicationInformation.h>

#ifdef Q_CC_GNU
#define EXTRACT_ARGC_ARGV(command)                                                                 \
    const auto arguments = QString{command}.simplified().split(" ");                               \
    int argc = arguments.size();                                                                   \
    char** argv = new char*[argc + 1];                                                             \
    for (auto i = 0; i < argc; ++i) {                                                              \
        argv[i] = new char[arguments[i].size() + 1];                                               \
        strcpy(argv[i], arguments[i].toLocal8Bit().constData());                                   \
    }                                                                                              \
    argv[argc] = nullptr; // argv[argc] shall be a null pointer.
#else                     // GCC doesn't support strcpy_s() and friends.
#define EXTRACT_ARGC_ARGV(command)                                                                 \
    const auto arguments = QString{command}.simplified().split(" ");                               \
    int argc = arguments.size();                                                                   \
    char** argv = new char*[argc + 1];                                                             \
    for (auto i = 0; i < argc; ++i) {                                                              \
        argv[i] = new char[arguments[i].size() + 1];                                               \
        strcpy_s(argv[i], arguments[i].size() + 1, arguments[i].toLocal8Bit().constData());        \
    }                                                                                              \
    argv[argc] = nullptr;
#endif

namespace common {

extern const QString kApplicationName;
extern const QVersionNumber kApplicationVersion;
extern const QString kApplicationDescription;
extern const genepy::ApplicationInformation kApplicationInformation;
extern const QString kApplicationPreferenceDirectoryPath;
extern QDir kLogDirectory;
extern const QString kLogFileName;

extern QString readFileLine(const QString& filePath, int lineNo);

} // namespace common

#endif // COMMON_H
