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

include(CMakePackageConfigHelpers)

# Install the export set
install(EXPORT ${GENEPY_EXPORT_SET}
        NAMESPACE ${GENEPY_PROJECT_NAME_L}::
        DESTINATION ${GENEPY_CMAKE_INSTALL_DIR})

# Create CMake configuration files
# ================================
set(GENEPY_CMAKE_CONFIG_FILE ${GENEPY_OUTPUT_DIR}/${GENEPY_CMAKE_INSTALL_DIR}/${PROJECT_NAME}Config.cmake)
configure_package_config_file(${GENEPY_RESOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in ${GENEPY_CMAKE_CONFIG_FILE}
                              INSTALL_DESTINATION ${GENEPY_CMAKE_INSTALL_DIR})

set(GENEPY_CMAKE_VERSION_FILE ${GENEPY_OUTPUT_DIR}/${GENEPY_CMAKE_INSTALL_DIR}/${PROJECT_NAME}ConfigVersion.cmake)
write_basic_package_version_file(${GENEPY_CMAKE_VERSION_FILE} VERSION ${PROJECT_VERSION}
                                                              COMPATIBILITY SameMajorVersion)

# Install the above created files
install(FILES ${GENEPY_CMAKE_CONFIG_FILE} ${GENEPY_CMAKE_VERSION_FILE}
        DESTINATION ${GENEPY_CMAKE_INSTALL_DIR})
