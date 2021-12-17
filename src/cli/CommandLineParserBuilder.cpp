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

#include <QtCore/QCommandLineParser>

#include <genepy/cli/CommandLineParserBuilder.h>

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
    parser_.parser_->addPositionalArgument(name, description, syntax);
    parser_.arguments_ << CommandLineArgument{name};

    return *this;
}

CommandLineParserBuilder& CommandLineParserBuilder::addOption(const QStringList& names,
                                                              const QString& description,
                                                              const QString& valueName)
{
    parser_.parser_->addOption(QCommandLineOption{names, description, valueName});
    parser_.options_ << CommandLineOption{names};

    return *this;
}

} // namespace genepy
