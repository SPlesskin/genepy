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
 * @file LogLevelFormatter.cpp
 * @author Erwan
 * @date 09/10/2020
 */

#include "LogLevelFormatter.h"

#include <QtGlobal>

namespace genepy {

const char LogLevelFormatter::kLogLevelFlag_{'*'};

void LogLevelFormatter::format(const spdlog::details::log_msg& msg, const std::tm& tm_time,
                               spdlog::memory_buf_t& dest)
{
    Q_UNUSED(tm_time)

    const auto str = [&msg]() -> std::string {
        switch (msg.level) {
            case spdlog::level::trace:
                return "TRACE";
            case spdlog::level::debug:
                return "DEBUG";
            case spdlog::level::info:
                return "INFO ";
            case spdlog::level::warn:
                return "WARN ";
            case spdlog::level::err:
                return "ERROR";
            case spdlog::level::critical:
                return "FATAL";
            default:
                Q_UNREACHABLE();
        }
    }();

    dest.append(str.data(), str.data() + str.size());
}

std::unique_ptr<spdlog::custom_flag_formatter> LogLevelFormatter::clone() const
{
    return spdlog::details::make_unique<LogLevelFormatter>();
}

} // namespace genepy
