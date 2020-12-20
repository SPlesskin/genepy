# Genepy - A C++ General-Purpose Library
# Copyright (C) 2020  Erwan Grâce <erwan.grace@outlook.fr>
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

include(GNUInstallDirs)
include(CTest)

string(TOLOWER ${PROJECT_NAME} GENEPY_PROJECT_NAME_L)

set(GENEPY_RESOURCE_DIR "${CMAKE_SOURCE_DIR}/resources")

# Define the search path for CMake modules (but not only)
list(APPEND CMAKE_MODULE_PATH "${GENEPY_RESOURCE_DIR}/nsis")

# Locate the external dependencies
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/external/build/external")

# Set the locations of the compiled artifacts
# ===========================================
set(GENEPY_OUTPUT_DIR "${CMAKE_BINARY_DIR}/dist/${CMAKE_BUILD_TYPE}")

if(UNIX)
    set(GENEPY_INSTALL_BIN_DIR ${CMAKE_INSTALL_BINDIR}/${GENEPY_PROJECT_NAME_L})
    set(GENEPY_INSTALL_LIB_DIR ${CMAKE_INSTALL_LIBDIR}/${GENEPY_PROJECT_NAME_L})
else()
    set(GENEPY_INSTALL_BIN_DIR ${CMAKE_INSTALL_BINDIR})
    set(GENEPY_INSTALL_LIB_DIR ${CMAKE_INSTALL_LIBDIR})
endif()

set(GENEPY_INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_INCLUDEDIR})

if(UNIX)
    set(GENEPY_INSTALL_CMAKE_DIR ${GENEPY_INSTALL_LIB_DIR}/cmake)
else()
    set(GENEPY_INSTALL_CMAKE_DIR ${GENEPY_INSTALL_LIB_DIR}/cmake/${GENEPY_PROJECT_NAME_L})
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${GENEPY_OUTPUT_DIR}/${GENEPY_INSTALL_BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${GENEPY_OUTPUT_DIR}/${GENEPY_INSTALL_LIB_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# Set the RPATH
# =============
# https://gitlab.kitware.com/cmake/community/wikis/doc/cmake/RPATH-handling
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
# Note: $ORIGIN resolves to the directory containing the executables.
set(CMAKE_INSTALL_RPATH "$ORIGIN;$ORIGIN/../${GENEPY_INSTALL_LIB_DIR};$ORIGIN/../../${GENEPY_INSTALL_LIB_DIR}")

# Define the export set which holds the targets to export
set(GENEPY_EXPORT_SET ${PROJECT_NAME}Targets)
