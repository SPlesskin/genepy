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
 * @file ConsoleApplication.cpp
 * @author Erwan
 * @date 11/11/2021
 */

#include <genepy/application/ConsoleApplication.h>

#include <QtCore/QVersionNumber>

#include <genepy/application/ApplicationInformation.h>

namespace genepy {

ConsoleApplication::ConsoleApplication(const ApplicationInformation& information, int& argc,
                                       char** argv)
    : QCoreApplication{argc, argv},
      description_{information.description},
      preferenceDirectory_{information.name, information.version}
{
    setApplicationName(information.name);
    setApplicationVersion(information.version.toString());
}

QString ConsoleApplication::getDescription() const { return description_; }

ApplicationPreferenceDirectory ConsoleApplication::getPreferenceDirectory() const
{
    return preferenceDirectory_;
}

} // namespace genepy
