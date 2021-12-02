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

#ifndef COMMON_H
#define COMMON_H

#include <QtCore/QVersionNumber>

#include <genepy/application/ApplicationInformation.h>

namespace common {

extern const QString kDummyApplicationName;
extern const QVersionNumber kDummyApplicationVersion;
extern const QString kDummyApplicationDescription;

extern const genepy::ApplicationInformation kDummyApplicationInformation;

extern const QString kDummyApplicationPreferenceDirectoryPath;

} // namespace common

#endif // COMMON_H