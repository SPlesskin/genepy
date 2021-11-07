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
 * @file LogLevel.h
 * @author Erwan
 * @date 30/09/2020
 */

#ifndef GENEPY_LOGLEVEL_H
#define GENEPY_LOGLEVEL_H

namespace genepy {

/**
 * @brief Possible severity levels for log messages.
 * @ingroup log
 */
enum class LogLevel {
    kTrace, ///< The _trace_ level.
    kDebug, ///< The _debug_ level.
    kInfo,  ///< The _info_ level.
    kWarn,  ///< The _warn_ level.
    kError, ///< The _error_ level.
    kFatal  ///< The _fatal_ level.
};

} // namespace genepy

#endif // GENEPY_LOGLEVEL_H
