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

function(genepy_find_qt_include_dir result)
    find_package(Qt5 REQUIRED COMPONENTS Core)
    list(GET Qt5Core_INCLUDE_DIRS 0 result)

    # Remove unnecessary path separators (e.g., the trailing one)
    file(TO_CMAKE_PATH "${result}" result)

    set(result ${result} PARENT_SCOPE)
endfunction()
