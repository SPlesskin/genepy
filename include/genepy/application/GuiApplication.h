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
 * @file GuiApplication.h
 * @author Erwan
 * @date 14/11/2021
 */

#ifndef GENEPY_GUIAPPLICATION_H
#define GENEPY_GUIAPPLICATION_H

#include <QtWidgets/QApplication>

#include <genepy/application/ApplicationPreferenceDirectory.h>
#include <genepy/genepy_global.h>

class QVersionNumber;

namespace genepy {

/**
 * @brief Provides a GUI application.
 * @ingroup application
 */
class GENEPY_EXPORT GuiApplication : public QApplication {
public:
    /**
     * @brief Constructor.
     * @param name the name of this application
     * @param version the version number of this application
     * @param argc the number of command-line arguments
     * @param argv the command-line arguments
     */
    GuiApplication(const QString& name, const QVersionNumber& version, int& argc, char** argv);

    /// @brief Returns the preference directory of this application.
    ApplicationPreferenceDirectory getPreferenceDirectory() const;

private:
    const ApplicationPreferenceDirectory preferenceDirectory_;
};

} // namespace genepy

#endif // GENEPY_GUIAPPLICATION_H
