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
 * @file CommandLineArgumentValue.ipp
 * @author Erwan
 * @date 16/12/2021
 */

#ifndef GENEPY_COMMANDLINEARGUMENTVALUE_IPP
#define GENEPY_COMMANDLINEARGUMENTVALUE_IPP

namespace genepy {

template <typename T>
T CommandLineArgumentValue::get() const
{
    return T{value_};
}

template <>
inline int CommandLineArgumentValue::get() const
{
    bool ok;
    const auto result = value_.toInt(&ok);

    GENEPY_THROW_EXCEPTION_IF(!ok, "Failed to convert the string \"" << value_
                                                                     << "\" to an integer")

    return result;
}

} // namespace genepy

#endif // GENEPY_COMMANDLINEARGUMENTVALUE_IPP
