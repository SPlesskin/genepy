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

if(BUILD_TESTING)
    file(GLOB_RECURSE GENEPY_TEST_SOURCES src/Test*.cpp)
    file(GLOB_RECURSE GENEPY_TEST_HEADERS src/Test*.h)

    find_package(Qt5 REQUIRED COMPONENTS Test)

    foreach(_file ${GENEPY_TEST_SOURCES})
        get_filename_component(_dir ${_file} DIRECTORY)
        get_filename_component(_name ${_file} NAME_WE)

        # List the source files of the current test
        file(GLOB_RECURSE _sources "${_dir}/${_name}.*")

        add_executable(${_name} ${_sources})
        target_link_libraries(${_name} PRIVATE common Qt5::Test ${GENEPY_LIBRARY})

        add_test(NAME ${_name} COMMAND ${_name})
    endforeach()
endif()
