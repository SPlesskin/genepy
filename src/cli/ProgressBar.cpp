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
 * @file ProgressBar.cpp
 * @author Erwan
 * @date 11/04/2021
 */

#include <genepy/cli/ProgressBar.h>

#include <iostream>

namespace {

const auto kCompletionChar = '=';
const auto kCompletionCharWidth = 5; // i.e., 5%

} // namespace

namespace genepy {

ProgressBar::ProgressBar(int totalStepCount) : totalStepCount_{totalStepCount}, currentStepCount_{0}
{
}

void ProgressBar::update()
{
    if (currentStepCount_ == totalStepCount_) {
        return;
    }

    ++currentStepCount_;

    const auto percentage = static_cast<std::size_t>((100 * currentStepCount_) / totalStepCount_);

    // The output buffer is flushed so that its content is displayed immediately.
    std::cout << "\r[" << std::string(percentage / kCompletionCharWidth, kCompletionChar)
              << std::string(100 / kCompletionCharWidth - percentage / kCompletionCharWidth, ' ')
              << "] " << currentStepCount_ << '/' << totalStepCount_ << ' ' << percentage << '%'
              << std::flush;

    if (percentage == 100) {
        std::cout << std::endl;
    }
}

} // namespace genepy
