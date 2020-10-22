/* Genepy - A General-Purpose Library
 * Copyright (C) 2020  Erwan Grâce <erwan.grace@outlook.fr>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>

#include <genepy/exception/exception_macros.h>

namespace {

int divide(int numerator, int denominator)
{
    GENEPY_THROW_EXCEPTION_IF(denominator == 0, "Division by zero!")

    return numerator / denominator;
}

} // namespace

int main(int argc, char** argv)
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    auto numerator = 0;
    auto denominator = 0;

    std::cout << "Numerator: ";
    std::cin >> numerator;

    std::cout << "Denominator: ";
    std::cin >> denominator;

    try {
        std::cout << numerator << '/' << denominator << " = " << divide(numerator, denominator)
                  << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
