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

// Forward declarations
class StringList;

/// A type used as a collection of chemical elements.
class Elements
{
public:
    /// Construct a default Elements object.
    Elements();

    /// Construct an Elements object with given data.
    explicit Elements(std::vector<Element> elements);

    /// Return the internal collection of Element objects.
    auto data() const -> const std::vector<Element>&;

    /// Return the number of chemical elements in the collection.
    auto size() const -> std::size_t;

    /// Return the Element object with given index.
    auto operator[](std::size_t index) const -> const Element&;

    /// Return the index of the first chemical element with given name.
    auto indexWithName(std::string name) const -> std::size_t;

    /// Return the index of the first chemical element with given symbol.
    auto indexWithSymbol(std::string symbol) const -> std::size_t;

    /// Return the first chemical element with given name.
    /// @throw std::runtime_error When there is no element with given name.
    auto getWithName(std::string name) const -> Element;

    /// Return the first chemical element with given symbol.
    /// @throw std::runtime_error When there is no element with given symbol.
    auto getWithSymbol(std::string symbol) const -> Element;

    /// Return the chemical elements with given symbols.
    auto withSymbols(const StringList& symbols) const -> Elements;

    /// Return the chemical elements with given names.
    auto withNames(const StringList& names) const -> Elements;

    /// Return the chemical elements with a given tag.
    auto withTag(std::string tag) const -> Elements;

    /// Return the chemical elements with given tags.
    auto withTags(const StringList& tags) const -> Elements;

    /// Append a new element to the list of elements.
    auto append(Element element) -> void;

    /// Return begin const iterator of this Elements instance
    inline auto begin() const { return data().begin(); }

    /// Return begin iterator of this Elements instance
    inline auto begin() { return data().begin(); }

    /// Return end const iterator of this Elements instance
    inline auto end() const { return data().end(); }

    /// Return end iterator of this Elements instance
    inline auto end() { return data().end(); }

    /// Return all chemical elements from the periodic table.
    static auto PeriodicTable() -> Elements;

private:
    /// The chemical elements stored in the database.
    std::vector<Element> m_elements;
};

} // namespace Atomik
