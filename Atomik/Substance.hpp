// Atomik is a library that implements basic chemical concepts such as elements, substances, and reactions.
//
// Copyright (C) 2018-2019 Allan Leal and Reaktoro Contributors
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
#include <unordered_map>

// Atomik includes

namespace Atomik {

// Forward declarations
class Elements;
class SubstanceElements;
class SubstanceFormula;

/// A type used to represent a chemical substance and its attributes.
class Substance
{
public:
    /// A type used to represent the arguments to construct a Substance object.
    struct Args
    {
        /// The name of the substance such as `H2O(aq)`, `O2(g)`, `H+(aq)`.
        const std::string& name;

        /// The chemical formula of the substance such as `H2O`, `O2`, `H+`.
        const SubstanceFormula& formula;

        /// The elements of the substance.
        const SubstanceElements& elements;

        /// The type of the substance such as `aqueous`, `gaseous`, `liquid`, "mineral", etc..
        const std::string& type;

        /// The tags of the substance such as `organic`, `mineral`.
        const std::vector<std::string>& tags;
    };

    /// Construct a default Substance object.
    Substance();

    /// Construct a Substance object with given chemical formula.
    /// A default database of chemical elements is used to construct the elements composing the substance.
    /// @param formula The formula of the substance (e.g., `H2O`, `CaCO3`, `CO3--`, `CO3-2`).
    Substance(const std::string& formula);

    /// Construct a Substance object with given chemical formula using custom database of elements.
    /// @param formula The formula of the substance (e.g., `H2O`, `CaCO3`, `CO3--`, `CO3-2`).
    /// @param db The database of chemical elements (if the default is insufficient).
    Substance(const std::string& formula, const Elements& db);

    /// Construct a Substance object with given data.
    /// @param args The arguments to construct the substance.
    Substance(const Args& args);

    /// Return a duplicate of this Substance object with replaced formula attribute.
    auto replaceFormula(const std::string& formula) -> Substance;

    /// Return a duplicate of this Substance object with replaced formula attribute using custom database of elements.
    auto replaceFormula(const std::string& formula, const Elements& db) -> Substance;

    /// Return a duplicate of this Substance object with replaced name attribute.
    auto replaceName(const std::string& name) -> Substance;

    /// Return a duplicate of this Substance object with replaced tags attribute.
    auto replaceTags(std::vector<std::string> tags) -> Substance;

    /// Return the name of the substance if provided, otherwise, its formula.
    auto name() const -> const std::string&;

    /// Return the chemical formula of the substance.
    auto formula() const -> const SubstanceFormula&;

    /// Return the elements of the substance.
    auto elements() const -> const SubstanceElements&;

    /// Return the tags of the substance (e.g., `organic`, `mineral`).
    auto tags() const -> const std::vector<std::string>&;

    /// Return the electric charge of the substance.
    auto charge() const -> double;

    /// Return the molar mass of the substance (in unit of kg/mol).
    auto molarMass() const -> double;

    /// Return true if the substance has a given tag.
    auto hasTag(const std::string& tag) const -> bool;

private:
    struct Impl;

    std::shared_ptr<Impl> pimpl;
};

/// Compare two Substance objects for less than
auto operator<(const Substance& lhs, const Substance& rhs) -> bool;

/// Compare two Substance objects for equality
auto operator==(const Substance& lhs, const Substance& rhs) -> bool;

} // namespace Atomik
