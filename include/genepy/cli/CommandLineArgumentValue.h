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
 * @file CommandLineArgumentValue.h
 * @author Erwan
 * @date 10/12/2021
 */

#ifndef GENEPY_COMMANDLINEARGUMENTVALUE_H
#define GENEPY_COMMANDLINEARGUMENTVALUE_H

#include <QtCore/QString>

#include <genepy/exception/exception_macros.h>
#include <genepy/genepy_global.h>

namespace genepy {

/**
 * @brief Represents the value of a command-line argument.
 * @ingroup cli
 */
class GENEPY_EXPORT CommandLineArgumentValue {
public:
    /// Constructor.
    CommandLineArgumentValue();

    /**
     * @brief Returns this value as a given type.
     * @tparam T the returned type
     * @throw genepy::Exception if this value can't be converted to the above type
     */
    template <typename T>
    T get() const;

    /**
     * @brief Sets this value.
     * @param value the value to set
     */
    void set(const QString& value);

private:
    QString value_;
};

} // namespace genepy

#include <genepy/cli/CommandLineArgumentValue.ipp>

#endif // GENEPY_COMMANDLINEARGUMENTVALUE_H
