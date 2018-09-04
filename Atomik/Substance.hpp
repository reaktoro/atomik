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
#include <Atomik/ChemicalFormula.hpp>
#include <Atomik/Element.hpp>
#include <Atomik/ElementDatabase.hpp>

namespace Atomik {

/// A type used to represent a chemical substance.
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
/// from an internal ElementDatabase object with default state. This database object is
/// initialized with all existing chemical elements in the periodic table. The example below
/// shows how to use a customized database of elements when constructing substances. It assumes
/// two elements `Aa` and `Bb` have been defined an appended to the database of elements.
/// The substance has chemical formula `AaBb2`.
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// ElementDatabase elements;
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

    /// Construct a Substance object with a given chemical formula.
    /// A default database of chemical elements is used to construct the elements composing the substance.
    /// @param formula The chemical formula of the substance (e.g., `H2O`, `CaCO3`, `CO3--`, `CO3-2`).
    Substance(std::string formula);

    /// Construct a Substance object with a given chemical formula.
    /// @param formula The chemical formula of the substance (e.g., `H2O`, `CaCO3`, `CO3--`, `CO3-2`).
    /// @param elementdb The user-defined database of chemical elements.
    Substance(std::string formula, const ElementDatabase& elementdb);

    /// Set the unique identifier (uid) of the substance.
    /// The uid of a substance exists to differentiate substances with same name and formula
    /// but existing under different aggregate states. For example, the uid of substance carbon
    /// dioxide, with name `CARBON-DIOXIDE` and formula `CO2`, could be set to `CO2(aq)` and `CO2(g)`
    /// to distinguish carbon dioxide in an aqueous state (aq) and in a gaseous state (g).
    /// @param uid The uid of the substance (e.g., `CO2(aq)`, `CaCO3(calcite)`)
    auto uid(std::string uid) -> Substance&;

    /// Return the unique identifier (uid) of the substance.
    /// @return The uid of the substance if provided, otherwise, its chemical formula.
    auto uid() const -> std::string;

    /// Set the name of the substance.
    /// @param name The name of the substance (e.g., `WATER`, `CARBON-DIOXIDE`, `CALCIUM-CARBONATE`)
    auto name(std::string name) -> Substance&;

    /// Return the name of the substance.
    /// @return The name of the substance if provided, otherwise, its chemical formula.
    auto name() const -> std::string;

    /// Return the chemical formula of the substance.
    auto formula() const -> const ChemicalFormula&;

    /// Return the elements of the substance and their coefficients.
    auto elements() const -> const std::vector<std::pair<Element, double>>&;

    /// Return the electric charge of the substance.
    auto charge() const -> double;

    /// Return the molar mass of the substance (in unit of kg/mol).
    auto molarMass() const -> double;

    /// Return the coefficient of an element in the substance.
    auto coefficient(std::string symbol) const -> double;

private:
    /// The unique identifier of the substance.
    std::string m_uid;

    /// The name of the substance.
    std::string m_name;

    /// The chemical formula of the substance.
    ChemicalFormula m_formula;

    /// The elements of the substance and their coefficients.
    std::vector<std::pair<Element, double>> m_elements;

    /// The molar mass of the substance (in unit of kg/mol).
    double m_molarmass;
};

/// Compare two Substance objects for less than
auto operator<(const Substance& lhs, const Substance& rhs) -> bool;

/// Compare two Substance objects for equality
auto operator==(const Substance& lhs, const Substance& rhs) -> bool;

} // namespace Atomik
