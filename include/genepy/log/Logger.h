/* Genepy - A General-Purpose Library
 * Copyright (C) 2020, 2021  Erwan Grâce <erwan.grace@outlook.fr>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * @file Logger.h
 * @author Erwan
 * @date 28/09/2020
 */

#ifndef GENEPY_LOGGER_H
#define GENEPY_LOGGER_H

#include <memory>

#include <QtCore/QVersionNumber>

#include <genepy/genepy_global.h>
#include <genepy/log/LogLevel.h>

namespace genepy {

class LoggerImpl;

/**
 * @defgroup log Log
 */

/**
 * @brief Provides an object to record events in a file.
 * @ingroup log
 */
class Logger {
public:
    /**
     * @brief Initializes this class.
     * @param appName the name of an application
     * @param appVersion the version number of the aforementioned application
     */
    GENEPY_EXPORT static void initialize(const QString& appName, const QVersionNumber& appVersion);

    /**
     * @brief Constructor.
     * @param name name of the logger
     */
    GENEPY_EXPORT explicit Logger(const QString& name);

    /// Destructor.
    GENEPY_EXPORT ~Logger();

    /**
     * @brief Writes a message to the log file.
     * @param level the severity level associated with the message
     * @param message the message to write
     */
    GENEPY_EXPORT void log(LogLevel level, const QString& message, bool flush = false) const;

private:
    std::unique_ptr<LoggerImpl> impl_;
};

} // namespace genepy

#endif // GENEPY_LOGGER_H
