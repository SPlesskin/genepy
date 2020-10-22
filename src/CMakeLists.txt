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

# List the source files
# =====================
# Pass library version to the source code
set(version_cpp_in "${GENEPY_RESOURCE_DIR}/cpp/version.cpp.in")
set(version_cpp "${CMAKE_CURRENT_SOURCE_DIR}/version.cpp")
configure_file(${version_cpp_in} ${version_cpp} @ONLY)

file(GLOB_RECURSE GENEPY_LIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

set(GENEPY_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

file(GLOB_RECURSE GENEPY_LIB_HEADERS ${GENEPY_INCLUDE_DIR}/*.h "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

# Build the library
# =================
set(GENEPY_LIB ${GENEPY_PROJECT_NAME_L})

# Although ignored, the headers are listed below so that they show up in IDEs.
add_library(${GENEPY_LIB} SHARED ${GENEPY_LIB_SOURCES} ${GENEPY_LIB_HEADERS})

target_compile_definitions(${GENEPY_LIB} PRIVATE GENEPY_LIBRARY)

# https://foonathan.net/2018/10/cmake-warnings
target_include_directories(${GENEPY_LIB}
                           PRIVATE ${GENEPY_INCLUDE_DIR}
                           SYSTEM INTERFACE $<BUILD_INTERFACE:${GENEPY_INCLUDE_DIR}>
                                            $<INSTALL_INTERFACE:${GENEPY_INSTALL_INCLUDE_DIR}>)

find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(spdlog REQUIRED CONFIG)

target_link_libraries(${GENEPY_LIB}
                      PUBLIC Qt5::Core
                      PRIVATE common spdlog::spdlog)

# Install binary and header files
# ===============================
# Note: the EXPORT option adds this library/target to the export set.
install(TARGETS ${GENEPY_LIB}
        EXPORT ${GENEPY_EXPORT_SET}
        LIBRARY DESTINATION ${GENEPY_INSTALL_LIB_DIR}
        ARCHIVE DESTINATION ${GENEPY_INSTALL_LIB_DIR}
        RUNTIME DESTINATION ${GENEPY_INSTALL_BIN_DIR}
        INCLUDES DESTINATION ${GENEPY_INSTALL_INCLUDE_DIR})

install(DIRECTORY ${GENEPY_INCLUDE_DIR}/${GENEPY_PROJECT_NAME_L}
        DESTINATION ${GENEPY_INSTALL_INCLUDE_DIR})

set(GENEPY_LIB ${GENEPY_LIB} PARENT_SCOPE)
