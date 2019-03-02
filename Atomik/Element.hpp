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
#include <memory>
#include <string>
#include <vector>

namespace Atomik {

/// A type used to define attributes of elements.
struct ElementAttributes
{
    /// The symbol of the element (e.g., "H", "O", "C", "Na").
    std::string symbol;

    /// The name of the element (e.g., "Hydrogen", "Oxygen").
    std::string name;

    /// The atomic number of the element.
    std::size_t atomicNumber;

    /// The atomic weight (or molar mass) of the element (in unit of kg/mol).
    double atomicWeight;

    /// The electronegativity of the element.
    double electronegativity;

    /// The tags of the element.
    std::vector<std::string> tags;
};

/// A type used to define a element and its attributes.
class Element
{
public:
    /// Construct a default Element object.
    Element();

    /// Construct an Element object with given attributes.
    Element(const ElementAttributes& attributes);

    /// Return a duplicate of this Element object with replaced symbol attribute.
    auto replaceSymbol(const std::string& symbol) const -> Element;

    /// Return a duplicate of this Element object with replaced name attribute.
    auto replaceName(const std::string& name) const -> Element;

    /// Return a duplicate of this Element object with replaced atomic number attribute.
    auto replaceAtomicNumber(std::size_t atomicNumber) const -> Element;

    /// Return a duplicate of this Element object with replaced atomic weight attribute.
    auto replaceAtomicWeight(double atomicWeight) const -> Element;

    /// Return a duplicate of this Element object with replaced electronegativity attribute.
    auto replaceElectronegativity(double electronegativity) const -> Element;

    /// Return a duplicate of this Element object with replaced tags attribute.
    auto replaceTags(std::vector<std::string> tags) const -> Element;

    /// Return the symbol of the element (e.g., "H", "O", "C", "Na").
    auto symbol() const -> std::string;

    /// Return the name of the element (e.g., "Hydrogen", "Oxygen").
    auto name() const -> std::string;

    /// Return the atomic number of the element.
    auto atomicNumber() const -> std::size_t;

    /// Return the atomic weight of the element (in unit of kg/mol).
    auto atomicWeight() const -> double;

    /// Return the electronegativity of the element.
    auto electronegativity() const -> double;

    /// Return the tags of the element.
    auto tags() const -> const std::vector<std::string>&;

    /// Return the molar mass of the element (in unit of kg/mol).
    auto molarMass() const -> double;

    /// Return true if the element has a given tag.
    auto hasTag(const std::string& tag) const -> bool;

private:
    struct Impl;

    std::shared_ptr<Impl> pimpl;
};

/// Compare two Element objects for less than.
auto operator<(const Element& lhs, const Element& rhs) -> bool;

/// Compare two Element objects for equality.
auto operator==(const Element& lhs, const Element& rhs) -> bool;

} // namespace Atomik
