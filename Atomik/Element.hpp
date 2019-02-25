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
#include <set>
#include <string>

namespace Atomik {

/// A type used to define attributes of chemical elements.
struct ElementAttributes
{
    /// The symbol of the chemical element (e.g., "H", "O", "C", "Na").
    std::string symbol;

    /// The name of the chemical element (e.g., "Hydrogen", "Oxygen").
    std::string name;

    /// The atomic number of the chemical element.
    std::size_t atomicNumber;

    /// The atomic weight (or molar mass) of the chemical element (in unit of kg/mol).
    double atomicWeight;

    /// The electronegativity of the chemical element.
    double electronegativity;

    /// The tags of the chemical element.
    std::set<std::string> tags;
};

/// A type used to define a chemical element and its attributes.
class Element
{
public:
    /// Construct a default Element object.
    Element();

    /// Construct an Element object with given attributes.
    Element(ElementAttributes attributes);

    /// Return the symbol of the chemical element (e.g., "H", "O", "C", "Na").
    auto symbol() const -> std::string;

    /// Return the name of the chemical element (e.g., "Hydrogen", "Oxygen").
    auto name() const -> std::string;

    /// Return the atomic number of the chemical element.
    auto atomicNumber() const -> std::size_t;

    /// Return the atomic weight of the chemical element (in unit of kg/mol).
    auto atomicWeight() const -> double;

    /// Return the electronegativity of the chemical element.
    auto electronegativity() const -> double;

    /// Return the tags of the chemical element.
    auto tags() const -> const std::set<std::string>&;

    /// Return the molar mass of the chemical element (in unit of kg/mol).
    auto molarMass() const -> double;

    /// Return the attributes of the chemical element.
    auto attributes() const -> ElementAttributes;

    /// Return a duplicate of this Element object with given symbol.
    auto withSymbol(std::string symbol) const -> Element;

    /// Return a duplicate of this Element object with given name.
    auto withName(std::string name) const -> Element;

    /// Return a duplicate of this Element object with given atomic number.
    auto withAtomicNumber(std::size_t atomicNumber) const -> Element;

    /// Return a duplicate of this Element object with given atomic weight.
    auto withAtomicWeight(double atomicWeight) const -> Element;

    /// Return a duplicate of this Element object with given electronegativity.
    auto withElectronegativity(double electronegativity) const -> Element;

    /// Return a duplicate of this Element object with given tags.
    auto withTags(std::set<std::string> tags) const -> Element;

private:
    struct Impl;

    std::shared_ptr<Impl> pimpl;
};

/// Compare two Element objects for less than.
auto operator<(const Element& lhs, const Element& rhs) -> bool;

/// Compare two Element objects for equality.
auto operator==(const Element& lhs, const Element& rhs) -> bool;

} // namespace Atomik
