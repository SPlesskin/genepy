# Genepy - A C++ General-Purpose Library
# Copyright (C) 2020-2022  Erwan Grâce <erwan.grace@outlook.fr>
#
# This file is part of Genepy.
#
# Genepy is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Genepy is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Genepy.  If not, see <https://www.gnu.org/licenses/>.

set(GENEPY_DEFAULT_BUILD_TYPE Release)
if(EXISTS "${PROJECT_SOURCE_DIR}/.git")
    set(GENEPY_DEFAULT_BUILD_TYPE Debug)
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${GENEPY_DEFAULT_BUILD_TYPE}' as none was specified.")
    set(CMAKE_BUILD_TYPE ${GENEPY_DEFAULT_BUILD_TYPE} CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for the CMake GUI
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Debug Release MinSizeRel RelWithDebInfo)
endif()
