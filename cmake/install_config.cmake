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

include(CMakePackageConfigHelpers)

# Install the export set
install(EXPORT ${GENEPY_EXPORT_SET}
        NAMESPACE ${GENEPY_PROJECT_NAME_L}::
        DESTINATION ${GENEPY_INSTALL_CMAKE_DIR})

# Create the Config.cmake and ConfigVersion.cmake files
# =====================================================
set(config_cmake_in ${GENEPY_RESOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in)
set(GENEPY_CMAKE_CONFIG_FILE ${GENEPY_OUTPUT_DIR}/${GENEPY_INSTALL_CMAKE_DIR}/${PROJECT_NAME}Config.cmake)
configure_package_config_file(${config_cmake_in} ${GENEPY_CMAKE_CONFIG_FILE}
                              INSTALL_DESTINATION ${GENEPY_INSTALL_CMAKE_DIR})

set(GENEPY_CMAKE_VERSION_FILE ${GENEPY_OUTPUT_DIR}/${GENEPY_INSTALL_CMAKE_DIR}/${PROJECT_NAME}ConfigVersion.cmake)
write_basic_package_version_file(${GENEPY_CMAKE_VERSION_FILE}
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMajorVersion)

# Install the above configuration files
install(FILES ${GENEPY_CMAKE_CONFIG_FILE}
              ${GENEPY_CMAKE_VERSION_FILE}
        DESTINATION ${GENEPY_INSTALL_CMAKE_DIR})
