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
 * @file version.h
 * @author Erwan
 * @date 10/09/2020
 */

#ifndef GENEPY_VERSION_H
#define GENEPY_VERSION_H

#include <QtCore/QVersionNumber>

#include <genepy/genepy_global.h>

/// Main namespace of this library.
namespace genepy {

/// Version number of this library.
GENEPY_EXPORT extern const QVersionNumber kVersion;

/// Build datetime of the current version of this library.
GENEPY_EXPORT extern const QDateTime kVersionBuildDatetime;

} // namespace genepy

#endif // GENEPY_VERSION_H
