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
 * @file CommandLineParser.cpp
 * @author Erwan
 * @date 03/12/2021
 */

#include <QtCore/QCommandLineParser>

#include <genepy/application/ConsoleApplication.h>
#include <genepy/cli/CommandLineParserBuilder.h>

namespace genepy {

CommandLineParserBuilder CommandLineParser::create(const genepy::ConsoleApplication& application)
{
    return CommandLineParserBuilder{application};
}

void CommandLineParser::doParsing()
{
    auto displayErrorMessage = [this](const QString& message) {
        printf("%s\n\n", qPrintable(message));
        parser_->showHelp(1);
    };

    if (!parser_->parse(ConsoleApplication::arguments())) {
        displayErrorMessage(parser_->errorText());
    }

    /********************************************
     * Process the standard options
     ********************************************/
    if (parser_->isSet(helpOption_)) {
        parser_->showHelp();
    }

    if (parser_->isSet(versionOption_)) {
        parser_->showVersion();
    }

    /********************************************
     * Process the mandatory arguments
     ********************************************/
    const auto arguments = parser_->positionalArguments();
    if (arguments.size() != arguments_.size()) {
        displayErrorMessage(QString("Incorrect number of arguments passed (expected %1, got %2).")
                                .arg(arguments_.size())
                                .arg(arguments.size()));
    }

    for (auto i = 0; i < arguments.size(); ++i) {
        arguments_[i]->setValue(arguments[i]);
    }

    /********************************************
     * Process the custom options
     ********************************************/
    for (auto i = 0; i < options_.size(); ++i) {
        if (std::any_of(
                std::cbegin(options_[i]->getNames()), std::cend(options_[i]->getNames()),
                [this](const QString& name) { return parser_->optionNames().contains(name); })) {
            options_[i]->setPresent();
            options_[i]->setValue(parser_->value(options_[i]->getNames().first()));
        }
    }
}

bool CommandLineParser::isOptionPresent(const QString& name) const
{
    for (auto i = 0; i < options_.size(); ++i) {
        if (options_[i]->getNames().contains(name)) {
            return options_[i]->isPresent();
        }
    }

    Q_UNREACHABLE();
}

CommandLineParser::CommandLineParser(const genepy::ConsoleApplication& application)
    : parser_{new QCommandLineParser},
      helpOption_{parser_->addHelpOption()},
      versionOption_{parser_->addVersionOption()}
{
    parser_->setApplicationDescription(application.getDescription());
    parser_->setSingleDashWordOptionMode(QCommandLineParser::ParseAsCompactedShortOptions);
}

} // namespace genepy
