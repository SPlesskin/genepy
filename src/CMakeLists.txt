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

# List the source files
# =====================
set(GENEPY_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

configure_file(${GENEPY_RESOURCE_DIR}/cpp/version.cpp.in "${CMAKE_CURRENT_SOURCE_DIR}/version.cpp" @ONLY)

file(GLOB_RECURSE GENEPY_LIBRARY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE GENEPY_LIBRARY_HEADERS ${GENEPY_INCLUDE_DIR}/*.h
                                         ${GENEPY_INCLUDE_DIR}/*.ipp
                                         "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
                                         "${CMAKE_CURRENT_SOURCE_DIR}/*.ipp")

# Build the library
# =================
set(GENEPY_LIBRARY ${GENEPY_PROJECT_NAME_L})

# Although ignored, the headers are listed below so that they show up in IDEs.
add_library(${GENEPY_LIBRARY} SHARED ${GENEPY_LIBRARY_SOURCES} ${GENEPY_LIBRARY_HEADERS})

target_compile_definitions(${GENEPY_LIBRARY} PRIVATE GENEPY_LIBRARY)

# https://foonathan.net/2018/10/cmake-warnings
target_include_directories(${GENEPY_LIBRARY}
                           PRIVATE ${GENEPY_INCLUDE_DIR}
                           SYSTEM INTERFACE $<BUILD_INTERFACE:${GENEPY_INCLUDE_DIR}>
                                            $<INSTALL_INTERFACE:${GENEPY_INCLUDE_INSTALL_DIR}>)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(spdlog REQUIRED CONFIG)

target_link_libraries(${GENEPY_LIBRARY}
                      PUBLIC Qt5::Core Qt5::Widgets
                      PRIVATE ${GENEPY_COMPILER_CONFIGURATION} spdlog::spdlog)

# Install binary and header files
# ===============================
# Note: the EXPORT option adds this library/target to the export set.
install(TARGETS ${GENEPY_LIBRARY}
        EXPORT ${GENEPY_EXPORT_SET}
        LIBRARY DESTINATION ${GENEPY_LIBRARY_INSTALL_DIR}
        ARCHIVE DESTINATION ${GENEPY_LIBRARY_INSTALL_DIR}
        RUNTIME DESTINATION ${GENEPY_RUNTIME_INSTALL_DIR}
        INCLUDES DESTINATION ${GENEPY_INCLUDE_INSTALL_DIR})

install(DIRECTORY ${GENEPY_INCLUDE_DIR}/${GENEPY_PROJECT_NAME_L}
        DESTINATION ${GENEPY_INCLUDE_INSTALL_DIR})

set(GENEPY_LIBRARY ${GENEPY_LIBRARY} PARENT_SCOPE)
