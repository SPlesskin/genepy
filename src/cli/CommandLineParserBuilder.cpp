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
 * @file CommandLineParserBuilder.cpp
 * @author Erwan
 * @date 05/12/2021
 */

#include <genepy/cli/CommandLineParserBuilder.h>

#include <QtCore/QCommandLineParser>

namespace genepy {

CommandLineParserBuilder::CommandLineParserBuilder(const ConsoleApplication& application)
    : parser_{application}
{
}

CommandLineParserBuilder::operator CommandLineParser() const { return std::move(parser_); }

CommandLineParserBuilder& CommandLineParserBuilder::addArgument(const QString& name,
                                                                const QString& description,
                                                                const QString& syntax)
{
    // Check that the name of the argument to add isn't used
    for (const auto& argument : parser_.arguments_) {
        Q_ASSERT(name != argument->getName());
    }

    parser_.parser_->addPositionalArgument(name, description, syntax);
    parser_.arguments_ << QSharedPointer<CommandLineArgument>::create(name);

    return *this;
}

CommandLineParserBuilder& CommandLineParserBuilder::addOption(const QStringList& names,
                                                              const QString& description,
                                                              const QString& valueName)
{
    // Check that the names of the option to add aren't used
    for (const auto& option : parser_.options_) {
        for (const auto& name : names) {
            Q_ASSERT(!option->getNames().contains(name));
        }
    }

    parser_.parser_->addOption(QCommandLineOption{names, description, valueName});
    parser_.options_ << QSharedPointer<CommandLineOption>::create(names);

    return *this;
}

} // namespace genepy
