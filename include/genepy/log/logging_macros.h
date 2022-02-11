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
 * @file logging_macros.h
 * @author Erwan
 * @date 11/09/2020
 */

#ifndef GENEPY_LOGGING_MACROS_H
#define GENEPY_LOGGING_MACROS_H

#include <QtCore/QTextStream>

#include <genepy/log/Logger.h>

namespace genepy {

#ifdef GENEPY_TEST_MODULE
const auto kFlush = true;
#else
const auto kFlush = false;
#endif

} // namespace genepy

/**
 * @ingroup log
 * @{
 */

/**
 * @def GENEPY_DEFINE_LOCAL_LOGGER(varname, name)
 * @hideinitializer
 * @brief Defines a logger which can be used locally in a function.
 */
#define GENEPY_DEFINE_LOCAL_LOGGER(varname, name) static const genepy::Logger varname{name};

/**
 * @def GENEPY_DECLARE_CLASS_LOGGER(varname)
 * @hideinitializer
 * @brief Declares a logger in a class.
 *
 * Actually, this macro declares a function which returns a reference to a static logger. Thus, the
 * logger will be instantiated only when the function is first called.
 */
#define GENEPY_DECLARE_CLASS_LOGGER(varname) static const genepy::Logger& varname();

/**
 * @def GENEPY_DEFINE_CLASS_LOGGER(varname, name)
 * @hideinitializer
 * @brief Defines a logger in a class.
 */
#define GENEPY_DEFINE_CLASS_LOGGER(varname, name)                                                  \
    const genepy::Logger& varname()                                                                \
    {                                                                                              \
        GENEPY_DEFINE_LOCAL_LOGGER(logger, name)                                                   \
                                                                                                   \
        return logger;                                                                             \
    }

/**
 * @def GENEPY_LOG_TRACE(varname, message)
 * @hideinitializer
 * @brief Writes a _trace_ message to the log.
 */
#define GENEPY_LOG_TRACE(varname, message)                                                         \
    {                                                                                              \
        auto str = QString{};                                                                      \
        QTextStream stream{&str};                                                                  \
        stream << message;                                                                         \
        varname.log(genepy::LogLevel::kTrace, str, genepy::kFlush);                                \
    }

/**
 * @def GENEPY_LOG_DEBUG(varname, message)
 * @hideinitializer
 * @brief Writes a _debug_ message to the log.
 */
#define GENEPY_LOG_DEBUG(varname, message)                                                         \
    {                                                                                              \
        auto str = QString{};                                                                      \
        QTextStream stream{&str};                                                                  \
        stream << message;                                                                         \
        varname.log(genepy::LogLevel::kDebug, str, genepy::kFlush);                                \
    }

/**
 * @def GENEPY_LOG_INFO(varname, message)
 * @hideinitializer
 * @brief Writes an _info_ message to the log.
 */
#define GENEPY_LOG_INFO(varname, message)                                                          \
    {                                                                                              \
        auto str = QString{};                                                                      \
        QTextStream stream{&str};                                                                  \
        stream << message;                                                                         \
        varname.log(genepy::LogLevel::kInfo, str, genepy::kFlush);                                 \
    }

/**
 * @def GENEPY_LOG_WARN(varname, message)
 * @hideinitializer
 * @brief Writes a _warn_ message to the log.
 */
#define GENEPY_LOG_WARN(varname, message)                                                          \
    {                                                                                              \
        auto str = QString{};                                                                      \
        QTextStream stream{&str};                                                                  \
        stream << message;                                                                         \
        varname.log(genepy::LogLevel::kWarn, str, genepy::kFlush);                                 \
    }

/**
 * @def GENEPY_LOG_ERROR(varname, message)
 * @hideinitializer
 * @brief Writes an _error_ message to the log.
 */
#define GENEPY_LOG_ERROR(varname, message)                                                         \
    {                                                                                              \
        auto str = QString{};                                                                      \
        QTextStream stream{&str};                                                                  \
        stream << message;                                                                         \
        varname.log(genepy::LogLevel::kError, str, genepy::kFlush);                                \
    }

/**
 * @def GENEPY_LOG_FATAL(varname, message)
 * @hideinitializer
 * @brief Writes a _fatal_ message to the log.
 */
#define GENEPY_LOG_FATAL(varname, message)                                                         \
    {                                                                                              \
        auto str = QString{};                                                                      \
        QTextStream stream{&str};                                                                  \
        stream << message;                                                                         \
        varname.log(genepy::LogLevel::kFatal, str, genepy::kFlush);                                \
    }

/** @} */

#endif // GENEPY_LOGGING_MACROS_H
