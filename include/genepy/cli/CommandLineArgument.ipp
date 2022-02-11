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
 * @file CommandLineArgument.ipp
 * @author Erwan
 * @date 16/12/2021
 */

#ifndef GENEPY_COMMANDLINEARGUMENT_IPP
#define GENEPY_COMMANDLINEARGUMENT_IPP

namespace genepy {

template <typename T>
T CommandLineArgument::getValue() const
{
    return value_.get<T>();
}

} // namespace genepy

#endif // GENEPY_COMMANDLINEARGUMENT_IPP
