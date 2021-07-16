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
 * @file exception_macros.h
 * @author Erwan
 * @date 10/09/2020
 */

#ifndef GENEPY_EXCEPTION_MACROS_H
#define GENEPY_EXCEPTION_MACROS_H

#include <QtCore/QTextStream>

#include <genepy/exception/Exception.h>

#ifdef Q_OS_WIN
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#else
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

/**
 * @def GENEPY_THROW_EXCEPTION_IF(condition, cause)
 * @hideinitializer
 * @brief This macro throws an exception if the given condition is true.
 * @ingroup exception
 *
 * Example:
 * ~~~{.cpp}
 * int division(int a, int b)
 * {
 *      GENEPY_THROW_EXCEPTION_IF(b == 0, "Division by zero!")
 *
 *      return a / b;
 * }
 * ~~~
 */
#define GENEPY_THROW_EXCEPTION_IF(condition, cause)                                                \
    if (condition) {                                                                               \
        auto str = QString{};                                                                      \
        QTextStream stream{&str};                                                                  \
        stream << cause;                                                                           \
        throw genepy::Exception{__FILENAME__, __LINE__, str};                                      \
    }

#endif // GENEPY_EXCEPTION_MACROS_H
