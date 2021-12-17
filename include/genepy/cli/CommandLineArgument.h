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
 * @file CommandLineArgument.h
 * @author Erwan
 * @date 10/12/2021
 */

#ifndef GENEPY_COMMANDLINEARGUMENT_H
#define GENEPY_COMMANDLINEARGUMENT_H

#include <genepy/cli/CommandLineArgumentValue.h>

namespace genepy {

/**
 * @brief Represents a mandatory argument of a command-line interface.
 * @ingroup cli
 */
class GENEPY_EXPORT CommandLineArgument {
public:
    /**
     * @brief Constructor.
     * @param name the name of this argument
     */
    explicit CommandLineArgument(const QString& name);

    /// Returns the name of this argument.
    QString getName() const;

    /**
     * @brief Returns the value of this argument.
     * @tparam T the type of the returned value
     */
    template <typename T>
    T getValue() const;

    /**
     * @brief Sets the value of this argument.
     * @param value the value to set
     */
    void setValue(const QString& value);

private:
    const QString name_;
    CommandLineArgumentValue value_;
};

} // namespace genepy

#include <genepy/cli/CommandLineArgument.ipp>

#endif // GENEPY_COMMANDLINEARGUMENT_H
