# Genepy - A C++ General-Purpose Library
# Copyright (C) 2020, 2021  Erwan Grâce <erwan.grace@outlook.fr>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.7)

if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.15)
    cmake_policy(SET CMP0092 NEW) # Silence MSVC warning D9025
endif()

project(Genepy VERSION 0.4.0 LANGUAGES CXX)

# Set a default build type if none was specified
include(cmake/GenepyBuildType.cmake)

# Define global parameters
include(cmake/GenepyParams.cmake)

# Utility CMake functions
include(cmake/GenepyUtils.cmake)

# Configure external tools
include(cmake/GenepyExternalTools.cmake)

# Set compiler flags
include(cmake/GenepyCompiler.cmake)

include(CTest)

add_subdirectory(src)
add_subdirectory(test)

# Install CMake configuration files
include(cmake/GenepyInstallConfig.cmake)

# Configure the package generators
include(cmake/GenepyPackage.cmake)
