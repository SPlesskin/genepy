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
 * @file Exception.cpp
 * @author Erwan
 * @date 10/09/2020
 */

#include <genepy/exception/Exception.h>

namespace {

const auto kMessagePrefix = QStringLiteral("Exception ");

} // namespace

namespace genepy {

Exception::Exception(const char* file, int line, const QString& cause)
    : message_{kMessagePrefix + file + ':' + QString::number(line) + ": " + cause},
      messageData_{message_.toLocal8Bit()}
{
}

const char* Exception::what() const noexcept { return messageData_.constData(); }

} // namespace genepy
