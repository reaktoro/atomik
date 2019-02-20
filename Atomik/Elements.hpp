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

    /// Construct an Elements object with given collection of Element objects.
    Elements(const std::list<Element>& data);

    /// Return the element attributes for a given element symbol.
    /// @param symbol The symbol of the chemical element (e.g., H, O, C, Ca, Na)
    /// @return A non-empty Element object if symbol is found, otherwise, an empty object.
    auto operator()(std::string symbol) const -> Element;

    /// Return all elements in the container.
    auto data() const -> std::list<Element>;

    /// Return the number of chemical elements in the container.
    auto size() const -> std::size_t;

    /// Return a copy of this Elements object with only the chemical elements with a given attribute.
    /// @param attribute Either the symbol, name, or a tag of the chemical element(s) to be filtered.
    auto filter(std::string attribute) const -> Elements;

    /// Return a copy of this Elements object without chemical elements with a given attribute.
    /// @param attribute Either the symbol, name, or a tag of the chemical element(s) to be removed.
    auto remove(std::string attribute) const -> Elements;

private:
    /// The chemical elements stored in the database.
    std::unordered_map<std::string, Element> m_elements;
};

} // namespace Atomik
