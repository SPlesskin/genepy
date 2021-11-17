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
 * @file ApplicationPreferenceDirectory.h
 * @author Erwan
 * @date 12/11/2021
 */

#ifndef GENEPY_APPLICATIONPREFERENCEDIRECTORY_H
#define GENEPY_APPLICATIONPREFERENCEDIRECTORY_H

#include <QtCore/QDir>

#include <genepy/genepy_global.h>

class QVersionNumber;

namespace genepy {

/**
 * @brief Provides the preference directory associated with an application.
 *
 * It is located in an user's home folder and stores the user's preferences (e.g., the application
 * settings and log files).
 *
 * @ingroup application
 */
class GENEPY_EXPORT ApplicationPreferenceDirectory : public QDir {
public:
    /**
     * @brief Constructor.
     * @param applicationName the name of the related application
     * @param applicationVersion the version number of the related application
     * @throw genepy::Exception if this directory can't be created
     */
    ApplicationPreferenceDirectory(const QString& applicationName,
                                   const QVersionNumber& applicationVersion);
};

} // namespace genepy

#endif // GENEPY_APPLICATIONPREFERENCEDIRECTORY_H
