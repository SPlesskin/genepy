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
 * @file CommandLineOption.h
 * @author Erwan
 * @date 17/12/2021
 */

#ifndef GENEPY_COMMANDLINEOPTION_H
#define GENEPY_COMMANDLINEOPTION_H

#include <QtCore/QStringList>

#include <genepy/cli/CommandLineArgumentValue.h>

namespace genepy {

/**
 * @brief Represents an optional argument of a command-line interface.
 * @ingroup cli
 */
class GENEPY_EXPORT CommandLineOption {
public:
    /**
     * @brief Constructor.
     * @param names the short and/or long name(s) of this option
     */
    explicit CommandLineOption(const QStringList& names);

    /// Returns the names of this option.
    QStringList getNames() const;

    /// Checks whether this option was present in the command line.
    bool isPresent() const;

    /// Indicates that this option was present in the command line.
    void setPresent();

    /**
     * @brief Returns the value of this option.
     * @tparam T the type of the returned value
     */
    template <typename T>
    T getValue() const;

    /**
     * @brief Sets the value of this option.
     * @param value the value to set
     */
    void setValue(const QString& value);

private:
    const QStringList names_;
    bool present_;
    CommandLineArgumentValue value_;
};

} // namespace genepy

#include <genepy/cli/CommandLineOption.ipp>

#endif // GENEPY_COMMANDLINEOPTION_H
