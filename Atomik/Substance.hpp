// Atomik is a library that implements basic chemical concepts such as elements, substances, and reactions.
//
// Copyright (C) 2014-2019 Allan Leal and Atomik Contributors
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
#include <any>
#include <memory>
#include <set>
#include <string>
#include <vector>

namespace Atomik {

// Forward declarations
class ChemicalFormula;
class Elements;

/// A type used to define basic attributes of chemical substances.
struct SubstanceAttributes
{
    /// The chemical formula of the substance such as `H2O`, `O2`, `H+`.
    std::string formula;

    /// The name of the substance such as `H2O(aq)`, `O2(g)`, `H+(aq)`.
    std::string name;

    /// The tags of the substance such as `organic`, `mineral`.
    std::vector<std::string> tags;
};

/// A type used to represent a chemical substance and its attributes.
/// The following examples demonstrate how different water substances can be created:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// Substance water1("H2O");
/// Substance water2("H2O").name("WATER");
/// Substance water3("H2O").name("WATER").uid("H2O(aq)");
/// Substance water4("H2O").name("WATER").uid("H2O(g)");
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// Substance `water1` is initialized with its name and unique identifier (uid) equal
/// to its formula, `H2O`. Substance `water2` also has its uid set to `H2O` by default,
/// but its name is modified to `WATER`. For substances `water3` and `water4`, both their
/// names and uid have been specified. In this case, the uid is used to distinguish these
/// two water substances, with same formula and name, based on their aggregate states,
/// with suffix (aq) denoting an aqueous state, and suffix (g) a gaseous state.
///
/// By default, the chemical elements of the previous four water substances were obtained
/// from an internal Elements object with default state. This database object is
/// initialized with all existing chemical elements in the periodic table. The example below
/// shows how to use a customized database of elements when constructing substances. It assumes
/// two elements `Aa` and `Bb` have been defined an appended to the database of elements.
/// The substance has chemical formula `AaBb2`.
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// Elements elements;
/// elements.append({"Aa"});
/// elements.append({"Bb"});
///
/// Substance substance("AaBb2", elements);
///
/// std::cout << substance.coefficient("Aa") == 1 << std::endl;
/// std::cout << substance.coefficient("Bb") == 2 << std::endl;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Substance
{
public:
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

    /// Construct a Substance object with given attributes.
    /// A default database of chemical elements is used to construct the elements composing the substance.
    /// @param attributes The basic attributes of the substance.
    Substance(SubstanceAttributes attributes);

    /// Construct a Substance object with given attributes using custom database of elements.
    /// @param attributes The basic attributes of the substance.
    /// @param db The database of chemical elements (if the default is insufficient).
    Substance(SubstanceAttributes attributes, const Elements& db);

    /// Return a duplicate of this Substance object with replaced formula attribute.
    auto replaceFormula(const std::string& formula) -> Substance;

    /// Return a duplicate of this Substance object with replaced formula attribute using custom database of elements.
    auto replaceFormula(const std::string& formula, const Elements& db) -> Substance;

    /// Return a duplicate of this Substance object with replaced name attribute.
    auto replaceName(const std::string& name) -> Substance;

    /// Return a duplicate of this Substance object with replaced tags attribute.
    auto replaceTags(std::vector<std::string> tags) -> Substance;

    /// Return the name of the substance if provided, otherwise, its formula.
    auto name() const -> std::string;

    /// Return the chemical formula of the substance.
    auto formula() const -> const ChemicalFormula&;

    /// Return the tags of the substance (e.g., `organic`, `mineral`).
    auto tags() const -> const std::vector<std::string>&;

    /// Return the elements of the substance.
    auto elements() const -> const Elements&;

    /// Return the symbols of the elements in the substance.
    auto symbols() const -> const std::vector<std::string>&;

    /// Return the coefficients of the elements in the substance.
    auto coefficients() const -> const std::valarray<double>&;

    /// Return the coefficient of an element symbol in the substance.
    auto coefficient(const std::string& symbol) const -> double;

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
