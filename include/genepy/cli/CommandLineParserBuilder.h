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
 * @file CommandLineParserBuilder.h
 * @author Erwan
 * @date 05/12/2021
 */

#ifndef GENEPY_COMMANDLINEPARSERBUILDER_H
#define GENEPY_COMMANDLINEPARSERBUILDER_H

#include <genepy/cli/CommandLineParser.h>

namespace genepy {

/**
 * @brief A builder class to construct genepy::CommandLineParser objects.
 * @ingroup cli
 */
class GENEPY_EXPORT CommandLineParserBuilder {
public:
    /**
     * @brief Constructor.
     * @param application a console application
     */
    explicit CommandLineParserBuilder(const ConsoleApplication& application);

    /// Conversion operator to a genepy::CommandLineParser instance.
    operator CommandLineParser() const;

    /**
     * @brief Adds a mandatory argument to the implicit command-line interface.
     * @param name the name of the argument
     * @param description a description of the argument
     * @param syntax the syntax for the argument
     * @sa
     * https://docs.microsoft.com/en-us/windows-server/administration/windows-commands/command-line-syntax-key
     */
    CommandLineParserBuilder& addArgument(const QString& name, const QString& description,
                                          const QString& syntax);

    /**
     * @brief Adds an optional argument to the implicit command-line interface.
     * @param names the short and/or long name(s) of the option
     * @param description a description of the option
     * @param valueName the name of the expected value (if needed)
     * @note The `valueName` parameter is used, among others, for the documentation of the option in
     * the help.
     */
    CommandLineParserBuilder& addOption(const QStringList& names, const QString& description,
                                        const QString& valueName = QString{});

private:
    CommandLineParser parser_;
};

} // namespace genepy

#endif // GENEPY_COMMANDLINEPARSERBUILDER_H
