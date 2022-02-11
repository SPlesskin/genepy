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

option(GENEPY_USE_DOXYGEN "Use Doxygen to produce code documentation" OFF)

if(GENEPY_USE_DOXYGEN)
    find_package(Doxygen)

    if(DOXYGEN_FOUND)
        # Variables used in the Doxygen configuration file
        set(GENEPY_DOXYGEN_PROJECT_BRIEF "A C++ general-purpose library")
        set(GENEPY_DOXYGEN_OUTPUT_DIR "\"${CMAKE_CURRENT_BINARY_DIR}\"")
        set(GENEPY_DOXYGEN_INPUT_DIRS "\"${CMAKE_CURRENT_SOURCE_DIR}\" \\
                             \"${CMAKE_SOURCE_DIR}/include\" \\
                             \"${CMAKE_SOURCE_DIR}/src\" \\
                             \"${CMAKE_SOURCE_DIR}/app\"")

        configure_file(Doxyfile.in Doxyfile @ONLY)

        add_custom_target(doc
                          COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
                          WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                          COMMENT "Generating documentation..."
                          VERBATIM)
    else()
        message(STATUS "Doxygen not found, documentation won't be generated")
    endif()
endif()
