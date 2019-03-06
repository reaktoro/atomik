// Atomik is a library that implements basic chemical concepts such as elements, substances, and reactions.
//
// Copyright (C) 2014-2019 Allan Leal and Atomik Contributors
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
#include <string>

// Atomik includes
#include <Atomik/Algorithms.hpp>

namespace Atomik {

/// Return a function that checks whether an item has a given name.
inline auto withName(const std::string& name)
{
    return [&](auto&& item) { return item.name() == name; };
}

/// Return a function that checks whether an item has a given symbol.
inline auto withSymbol(const std::string& symbol)
{
    return [&](auto&& item) { return item.symbol() == symbol; };
}

/// Return a function that checks whether an item has given symbols.
inline auto withSymbols(const std::vector<std::string>& symbols)
{
    return [&](auto&& item) { return contained(item.symbols(), symbols); };
}

/// Return a function that checks whether an item has a given formula.
inline auto withFormula(const std::string& formula)
{
    return [&](auto&& item) { return item.formula() == formula; };
}

/// Return a function that checks whether an item has a given tag.
inline auto withTag(const std::string& tag)
{
    return [&](auto&& item) { return contains(item.tags(), tag); };
}

/// Return a function that checks whether an item has given tags.
inline auto withTags(const std::vector<std::string>& tags)
{
    return [&](auto&& item) { return contained(tags, item.tags()); };
}

} // namespace Atomik
