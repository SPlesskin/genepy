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

/**
 * @file ApplicationPreferenceDirectory.cpp
 * @author Erwan
 * @date 12/11/2021
 */

#include <QtCore/QVersionNumber>

#include <genepy/application/ApplicationPreferenceDirectory.h>
#include <genepy/exception/exception_macros.h>

namespace {

QDir createDir(const QString& applicationName, const QVersionNumber& applicationVersion)
{
    const auto dir = QDir{QDir::homePath() + "/." + applicationName.toLower() + '/' +
                          applicationVersion.toString()};

    GENEPY_THROW_EXCEPTION_IF(!dir.mkpath("."), "Can't create directory " << dir.path())

    return dir;
}

} // namespace

namespace genepy {

ApplicationPreferenceDirectory::ApplicationPreferenceDirectory(
    const QString& applicationName, const QVersionNumber& applicationVersion)
    : QDir{createDir(applicationName, applicationVersion)}
{
}

} // namespace genepy