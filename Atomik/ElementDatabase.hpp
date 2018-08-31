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
#include <unordered_map>

// Atomik includes
#include <Atomik/Element.hpp>

namespace Atomik {

/// A type used as a database of chemical elements.
class ElementDatabase
{
public:
    /// Construct a default Elements object.
    ElementDatabase();

    /// Return all elements stored in the database of elements.
    auto elements() const -> const std::unordered_map<std::string, Element>&;

    /// Return an Element object with given symbol, or empty object if symbol not known.
    auto get(std::string symbol) const -> Element;

    /// Append a new custom element into the database of elements.
    auto append(const Element& element) -> void;

    /// Remove an existing element from the database of elements.
    auto remove(std::string symbol) -> void;

private:
    /// The chemical elements stored in the database.
    std::unordered_map<std::string, Element> m_elements;
};

} // namespace Atomik
