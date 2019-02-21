// Atomik is a library for parsing chemical formulas.
//
// Copyright (C) 2018 Allan Leal
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
#include <functional>

namespace Atomik {

/// Return a function that checks with an item has a given name.
auto withName(std::string name)
{
    return [](auto&& item) { return item.name() == name; };
}

/// Return a function that checks with an item has a given symbol.
auto withSymbol(std::string symbol)
{
    return [](auto&& item) { return item.symbol() == symbol; };
}

/// Return a function that checks with an item has a given formula.
auto withFormula(std::string formula)
{
    return [](auto&& item) { return item.formula() == formula; };
}

/// Return a function that checks with an item has a given tag.
auto withTag(std::string tag)
{
    return [](auto&& item) { return item.tags().count(tag); };
}

/// Return a function that checks with an item has a given tag.
auto tagged(std::string tag)
{
    return withTag(tag);
}

/// Return a function that checks with an item has a given tag.
auto nottagged(std::string tag)
{
    return [](auto&& item) { return item.tags().count(tag) == 0; };
}

} // namespace Atomik
