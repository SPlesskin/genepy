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

if(BUILD_TESTING)
    file(GLOB_RECURSE GENEPY_TEST_SOURCES src/Test*.cpp)
    file(GLOB_RECURSE GENEPY_TEST_HEADERS src/Test*.h)

    file(GLOB_RECURSE GENEPY_TEST_HELPER_SOURCES src/*_helper.cpp)

    file(GLOB_RECURSE GENEPY_TEST_COMMON_SOURCES src/*.cpp)
    file(GLOB_RECURSE GENEPY_TEST_COMMON_HEADERS src/*.h)
    list(REMOVE_ITEM GENEPY_TEST_COMMON_SOURCES ${GENEPY_TEST_SOURCES}
                                                ${GENEPY_TEST_HELPER_SOURCES})
    list(REMOVE_ITEM GENEPY_TEST_COMMON_HEADERS ${GENEPY_TEST_HEADERS})

    # Compile the test helpers
    # ========================
    foreach(_file ${GENEPY_TEST_HELPER_SOURCES})
        get_filename_component(_helper_name ${_file} NAME_WE)

        set(_helper_sources ${_file} ${GENEPY_TEST_COMMON_SOURCES} ${GENEPY_TEST_COMMON_HEADERS})

        add_executable(${_helper_name} ${_helper_sources})
        target_link_libraries(${_helper_name} PRIVATE ${GENEPY_COMPILER_CONFIGURATION}
                                                      ${GENEPY_LIBRARY})
    endforeach()

    # Compile the tests
    # =================
    find_package(Qt5 REQUIRED COMPONENTS Test)

    add_definitions(-DGENEPY_TEST_MODULE)

    foreach(_file ${GENEPY_TEST_SOURCES})
        get_filename_component(_test_name ${_file} NAME_WE)

        file(GLOB_RECURSE _test_sources src/${_test_name}.*)
        list(APPEND _test_sources ${GENEPY_TEST_COMMON_SOURCES} ${GENEPY_TEST_COMMON_HEADERS})

        add_executable(${_test_name} ${_test_sources})
        target_link_libraries(${_test_name} PRIVATE ${GENEPY_COMPILER_CONFIGURATION} Qt5::Test
                                                    ${GENEPY_LIBRARY})

        add_test(NAME ${_test_name} COMMAND ${_test_name}
                 WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    endforeach()
endif()
