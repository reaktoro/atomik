// Atomik is a library that implements basic chemical concepts such as elements, substances, and reactions.
//
// Copyright (C) 2018-2019 Allan Leal and Reaktoro Contributors
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this library. If not, see <http://www.gnu.org/licenses/>.

#pragma once

// C++ includes
#include <sstream>
#include <string>

namespace Atomik {
namespace internal {

template <typename Arg>
auto stringfy(std::stringstream& ss, const std::string& sep, const Arg& item)
{
    ss << item;
}

template <typename Arg, typename... Args>
auto stringfy(std::stringstream& ss, const std::string& sep, const Arg& item, Args... items) -> void
{
    ss << item << sep;
    stringfy(ss, sep, items...);
}

} // namespace internal

/// Concatenate the arguments into a string using a given separator string.
template <typename... Args>
auto stringfy(const std::string& sep, Args... items) -> std::string
{
    std::stringstream ss;
    internal::stringfy(ss, sep, items...);
    return ss.str();
}

/// Concatenate the arguments into a string without any separator string.
template <typename... Args>
auto str(Args... items) -> std::string
{
    return stringfy("", items...);
}

} // namespace Atomik
