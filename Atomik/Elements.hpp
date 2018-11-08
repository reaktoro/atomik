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
#include <list>
#include <string>
#include <unordered_map>

// Atomik includes
#include <Atomik/Element.hpp>

namespace Atomik {

/// A type used as a database of chemical elements.
class Elements
{
public:
    /// Construct a default Elements object.
    Elements();

    /// Return the element attributes for a given element symbol.
    /// @param symbol The symbol of the chemical element (e.g., H, O, C, Ca, Na)
    /// @return A non-empty Element object if symbol is found, otherwise, an empty object.
    auto operator()(std::string symbol) const -> Element;

    /// Return all elements stored in the database.
    auto data() const -> std::list<Element>;

    /// Clear the database removing all stored elements.
    auto clear() -> void;

    /// Append a new custom element into the database.
    auto append(const ElementData& element) -> void;

    /// Remove an existing element from the database.
    /// @param symbol The symbol of the chemical element (e.g., H, O, C, Ca, Na)
    auto remove(std::string symbol) -> void;

private:
    /// The chemical elements stored in the database.
    std::unordered_map<std::string, Element> m_elements;
};

} // namespace Atomik
