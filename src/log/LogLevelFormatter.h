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
 * @file LogLevelFormatter.h
 * @author Erwan
 * @date 09/10/2020
 */

#ifndef GENEPY_LOGLEVELFORMATTER_H
#define GENEPY_LOGLEVELFORMATTER_H

#include <spdlog/pattern_formatter.h>

namespace genepy {

class LogLevelFormatter : public spdlog::custom_flag_formatter {
public:
    static const char kLogLevelFlag_;

    virtual void format(const spdlog::details::log_msg& msg, const std::tm& tm_time,
                        spdlog::memory_buf_t& dest) override;

    virtual std::unique_ptr<custom_flag_formatter> clone() const override;
};

} // namespace genepy

#endif // GENEPY_LOGLEVELFORMATTER_H
