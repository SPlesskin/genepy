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

/**
 * @file genepy_global.h
 * @author Erwan
 * @date 09/09/2020
 */

#ifndef GENEPY_GLOBAL_H
#define GENEPY_GLOBAL_H

#include <QtCore/QtGlobal>

/**
 * @def GENEPY_EXPORT
 * @hideinitializer
 * @brief Enables to export or import symbols contained in this library.
 */
#ifdef GENEPY_LIBRARY
#define GENEPY_EXPORT Q_DECL_EXPORT
#else
#define GENEPY_EXPORT Q_DECL_IMPORT
#endif

#endif // GENEPY_GLOBAL_H
