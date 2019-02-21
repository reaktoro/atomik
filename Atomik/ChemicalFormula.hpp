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
#include <Atomik/Elements.hpp>

namespace Atomik {

/// A type used to represent a chemical formula.
/// The chemical formula of a formula can be represented by a string with the following formats:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// ChemicalFormula formula01("H2O");
/// ChemicalFormula formula02("CaCl2");
/// ChemicalFormula formula03("MgCO3");
/// ChemicalFormula formula04("(CaMg)(CO3)2");
/// ChemicalFormula formula05("Fe3Al2Si3O12");
/// ChemicalFormula formula06("Na+");
/// ChemicalFormula formula07("Ca++");
/// ChemicalFormula formula08("Fe+++");
/// ChemicalFormula formula09("Fe+3");
/// ChemicalFormula formula10("CO3--");
/// ChemicalFormula formula11("CO3-2");
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// There are two ways of specifying the electric charge of the substance:
///   1. as a suffix containing as many symbols `+` and `-` as there are charges (e.g., `Fe+++`, `Ca++`, `CO3--`); or
///   2. as a suffix containing the symbol `+` or `-` followed by the number of charges (e.g., `Fe+3`, `Ca+2`, `Na+`)
/// Note that number 1 is optional for the second formart.
/// In both formats, the symbol `+` is used for positively charged substances, and `-` for negatively charged ones.
class ChemicalFormula
{
public:
    /// Construct a ChemicalFormula object.
    /// @param formula A string such as `H2O`, `CaCO3`, `(CaMg)(CO3)2`.
    explicit ChemicalFormula(std::string formula);

    /// Construct a ChemicalFormula object with custom database of elements.
    /// @param formula A string such as `H2O`, `CaCO3`, `(CaMg)(CO3)2`.
    /// @param edb A database of elements if the default one is not applicable..
    ChemicalFormula(std::string formula, const Elements& edb);

    /// Return the elements in the chemical formula and their coefficients.
    auto elements() const -> const Elements&;

    /// Return the elements in the chemical formula and their coefficients.
    auto coefficients() const -> const std::vector<double>&;

    /// Return the coefficient of an element symbol in the chemical formula.
    auto coefficient(std::string symbol) const -> double;

    /// Return the electric charge of the chemical formula.
    auto charge() const -> double;

    /// Return the molar mass of the chemical formula (in kg/mol).
    auto molarMass() const -> double;

    /// Return the chemical formula as a string.
    auto str() const -> std::string;

    /// Convert this ChemicalFormula object into a string.
    operator std::string() const;

    /// Parse a chemical formula.
    /// This method only requires that element names follow the convention
    /// that its first letter is uppercase and all others in lowercase.
    /// Thus, even chemical formulas such as `AaBbb` or `(Aa2Bbb4)Cc6` are supported.
    /// @param formula A string such as `H2O`, `CaCO3`, `(CaMg)(CO3)2`.
    /// @return An unordered map such as `{ {"Ca", 1}, {"C", 1}, {"O", 3} }` for `CaCO3`.
    static auto parse(std::string formula) -> std::unordered_map<std::string, double>;

private:
    /// The chemical formula as a string.
    std::string m_formula;

    /// The elements in the chemical formula.
    Elements m_elements;

    /// The coefficients of the elements in the chemical formula such a {1, 2} for CO2.
    std::vector<double> m_coefficients;

    /// The molar mass of the chemical formula (in kg/mol).
    double m_molar_mass;

    /// The electrical charge of the chemical formula.
    double m_charge;
};

/// Compare two ChemicalFormula objects for less than
auto operator<(const ChemicalFormula& lhs, const ChemicalFormula& rhs) -> bool;

/// Compare two ChemicalFormula objects for equality
auto operator==(const ChemicalFormula& lhs, const ChemicalFormula& rhs) -> bool;

/// Return true if two chemical formulas have the same charge and elemental composition (e.g., `Ca++` and `Ca+2`).
auto equivalent(const ChemicalFormula& lhs, const ChemicalFormula& rhs) -> bool;

} // namespace Atomik
