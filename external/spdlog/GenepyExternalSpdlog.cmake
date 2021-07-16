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

set(GENEPY_EXTERNAL_SPDLOG_PREFIX spdlog)
set(GENEPY_EXTERNAL_SPDLOG_URL "${CMAKE_SOURCE_DIR}/spdlog/spdlog-1.7.0.tar.gz")
set(GENEPY_EXTERNAL_SPDLOG_URL_MD5 2e1c0c45920a3536366d2232963bc24a)

ExternalProject_Add(${GENEPY_EXTERNAL_SPDLOG_PREFIX}
    PREFIX ${GENEPY_EXTERNAL_SPDLOG_PREFIX}
    #--Download step--------------
    URL ${GENEPY_EXTERNAL_SPDLOG_URL}
    URL_MD5 ${GENEPY_EXTERNAL_SPDLOG_URL_MD5}
    #--Configure step-------------
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=${GENEPY_EXTERNAL_BUILD_TYPE}
               -DSPDLOG_BUILD_EXAMPLE=${GENEPY_EXTERNAL_BUILD_EXAMPLES}
               -DSPDLOG_BUILD_SHARED=${GENEPY_EXTERNAL_BUILD_SHARED}
               -DCMAKE_INSTALL_PREFIX=${GENEPY_EXTERNAL_INSTALL_PREFIX}
               -DSPDLOG_BUILD_TESTS=${GENEPY_EXTERNAL_BUILD_TESTS}
               -DCMAKE_POSITION_INDEPENDENT_CODE=ON
    #--Output logging-------------
    LOG_DOWNLOAD 1
    LOG_CONFIGURE 0
    LOG_BUILD 0
    LOG_INSTALL 1)
