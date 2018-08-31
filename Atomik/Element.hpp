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

namespace Atomik {

/// A type used to define a chemical element attributes.
struct ElementData
{
    /// The symbol of the chemical element (e.g., "H", "O", "C", "Na").
    std::string symbol;

    /// The name of the chemical element (e.g., "Hydrogen", "Oxygen").
    std::string name;

    /// The atomic number of the chemical element.
    std::size_t atomic_number;

    /// The atomic weight (or molar mass) of the chemical element (in unit of kg/mol).
    double atomic_weight;

    /// The electronegativity of the chemical element.
    double electronegativity;
};

/// A type used to define a chemical element and its attributes.
class Element
{
public:
    /// Construct a default Element object.
    Element() {}

    /// Construct an Element object with given data.
    Element(const ElementData& data) : data(data) {}

    /// Set the symbol of the chemical element (e.g., "H", "O", "C", "Na").
    auto symbol(std::string value) -> void { data.symbol = value; };

    /// Return the symbol of the chemical element (e.g., "H", "O", "C", "Na").
    auto symbol() const -> std::string { return data.symbol; };

    /// Set the name of the chemical element (e.g., "Hydrogen", "Oxygen").
    auto name(std::string value) -> void { data.name = value; };

    /// Return the name of the chemical element (e.g., "Hydrogen", "Oxygen").
    auto name() const -> std::string { return data.name; };

    /// Set the atomic number of the chemical element.
    auto atomicNumber(std::size_t value) -> void { data.atomic_number = value; };

    /// Return the atomic number of the chemical element.
    auto atomicNumber() const -> std::size_t { return data.atomic_number; };

    /// Set the atomic weight (or molar mass) of the chemical element (in unit of kg/mol).
    auto atomicWeight(double value) -> void { data.atomic_weight = value; };

    /// Return the atomic weight (or molar mass) of the chemical element (in unit of kg/mol).
    auto atomicWeight() const -> double { return data.atomic_weight; };

    /// Set the electronegativity of the chemical element.
    auto electronegativity(double value) -> void { data.electronegativity = value; };

    /// Return the electronegativity of the chemical element.
    auto electronegativity() const -> double { return data.electronegativity; };

private:
    /// The chemical element data.
    ElementData data;
};

/// Compare two Element objects for less than.
auto operator<(const Element& lhs, const Element& rhs) -> bool;

/// Compare two Element objects for equality.
auto operator==(const Element& lhs, const Element& rhs) -> bool;

} // namespace Atomik
