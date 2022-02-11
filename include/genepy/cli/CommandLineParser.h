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
 * @file CommandLineParser.h
 * @author Erwan
 * @date 03/12/2021
 */

#ifndef GENEPY_COMMANDLINEPARSER_H
#define GENEPY_COMMANDLINEPARSER_H

#include <QtCore/QCommandLineOption>
#include <QtCore/QSharedPointer>
#include <QtCore/QVector>

#include <genepy/cli/CommandLineArgument.h>
#include <genepy/cli/CommandLineOption.h>

class QCommandLineParser;

namespace genepy {

class CommandLineParserBuilder;
class ConsoleApplication;

/**
 * @brief Provides a means to retrieve command-line arguments.
 * @ingroup cli
 */
class GENEPY_EXPORT CommandLineParser {
public:
    /**
     * @brief Returns a builder entity to create a custom command-line parser.
     * @param application a console application
     */
    static CommandLineParserBuilder create(const ConsoleApplication& application);

    /// Performs the command-line parsing.
    void doParsing();

    /**
     * @brief Returns the value of an argument.
     * @param name the name of the argument
     * @tparam T the type of the returned value
     */
    template <typename T>
    T getArgumentValue(const QString& name) const;

    /**
     * @brief Checks whether an option was present in the command line.
     * @param name one of the option's names
     * @return `true` if the option was present, `false` otherwise
     */
    bool isOptionPresent(const QString& name) const;

    /**
     * @brief Returns the value of an option.
     * @param name one of the option's names
     * @tparam T the type of the returned value
     */
    template <typename T>
    T getOptionValue(const QString& name) const;

private:
    friend class CommandLineParserBuilder;

    explicit CommandLineParser(const ConsoleApplication& application);

    // Since the QCommandLineParser class has its copy constructor disabled, this attribute is
    // defined as a shared pointer. Thus, the object to which it belongs can be copied safely.
    const QSharedPointer<QCommandLineParser> parser_;

    // Standard options
    const QCommandLineOption helpOption_;
    const QCommandLineOption versionOption_;

    // Mandatory arguments
    QVector<QSharedPointer<CommandLineArgument>> arguments_;

    // Custom optional arguments
    QVector<QSharedPointer<CommandLineOption>> options_;
};

} // namespace genepy

#include <genepy/cli/CommandLineParser.ipp>

#endif // GENEPY_COMMANDLINEPARSER_H
