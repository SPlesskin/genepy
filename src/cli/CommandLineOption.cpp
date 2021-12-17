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
 * @file CommandLineOption.cpp
 * @author Erwan
 * @date 17/12/2021
 */

#include <genepy/cli/CommandLineOption.h>

namespace genepy {

CommandLineOption::CommandLineOption(const QStringList& names) : names_{names}, present_{false} {}

QStringList CommandLineOption::getNames() const { return names_; }

bool CommandLineOption::isPresent() const { return present_; }

void CommandLineOption::setPresent() { present_ = true; }

void CommandLineOption::setValue(const QString& value) { value_.set(value); }

} // namespace genepy