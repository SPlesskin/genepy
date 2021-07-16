# Genepy - A C++ General-Purpose Library
# Copyright (C) 2020, 2021  Erwan Grâce <erwan.grace@outlook.fr>
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

cmake_minimum_required(VERSION 3.7)

project(GenepyExternal)

include(ExternalProject)

if(NOT GENEPY_EXTERNAL_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(GENEPY_EXTERNAL_BUILD_TYPE Release CACHE STRING "Choose the type of build.")
    # Set the possible values of build type for the CMake GUI
    set_property(CACHE GENEPY_EXTERNAL_BUILD_TYPE PROPERTY STRINGS Debug Release MinSizeRel RelWithDebInfo)
endif()

set(GENEPY_EXTERNAL_BUILD_EXAMPLES OFF)
set(GENEPY_EXTERNAL_BUILD_SHARED OFF)
set(GENEPY_EXTERNAL_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/external")
set(GENEPY_EXTERNAL_BUILD_TESTS OFF)

include(spdlog/GenepyExternalSpdlog.cmake)
