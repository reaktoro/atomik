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
#include <vector>

// Atomik includes
#include <Atomik/Element.hpp>

namespace Atomik {

/// A type used as a database of chemical elements.
class Elements
{
public:
    /// Construct a default Elements object.
    Elements();

    /// Construct an Elements object with given data.
    explicit Elements(std::vector<Element> elements);

    /// Return the first Element object with a given symbol.
    /// @param symbol An element symbol such as `H`, `O`, `C`, `Ca`, `Na`.
    /// @return The Element object with given symbol if found.
    /// @throw std::out_of_range In case there is no Element object with given symbol.
    auto operator()(std::string symbol) const -> const Element&;

    /// Return the number of chemical elements in the collection.
    auto size() const -> std::size_t;

    /// Return the index of a chemical element with given symbol.
    auto index(std::string symbol) const -> std::size_t;

    /// Return the index of a chemical element with given symbol.
    auto indexWithSymbol(std::string symbol) const -> std::size_t;

    /// Return the index of a chemical element with given name.
    auto indexWithName(std::string name) const -> std::size_t;

    /// Return the chemical elements with a given tag.
    auto withTag(std::string tag) const -> Elements;

    /// Return the internal collection of Element objects.
    auto data() const -> const std::vector<Element>&;

private:
    /// The chemical elements stored in the database.
    std::vector<Element> m_elements;
};

// Methods to enable for range loops
inline auto begin(const Elements& elements) { return elements.data().begin(); }
inline auto begin(Elements& elements) { return elements.data().begin(); }
inline auto end(const Elements& elements) { return elements.data().end(); }
inline auto end(Elements& elements) { return elements.data().end(); }

} // namespace Atomik
