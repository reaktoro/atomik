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
#include <valarray>
#include <vector>

namespace Atomik {

/// A type used to represent the chemical formula of a substance.
/// The chemical formula of a substance follows the convention
/// that its first letter is uppercase and all others in lowercase.
/// Thus, even chemical formulas such as `AaBbb` or `(Aa2Bbb4)Cc6` are supported.
/// Below are some examples of chemical formulas of interest:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// using namespace Atomik;
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
/// Above we see some formulas for substances with electric charge.
/// There are two ways of specifying the electric charge in the formula:
///   1. as a suffix containing as many symbols `+` and `-` as there are charges (e.g., `Fe+++`, `Ca++`, `CO3--`); or
///   2. as a suffix containing the symbol `+` or `-` followed by the number of charges (e.g., `Fe+3`, `Ca+2`, `Na+`)
/// Note that the number 1 is optional for the second format (e.g., `Na+` and `Na+1` are equivalent).
/// In both formats (1) and (2), the symbol `+` is used for positively charged substances, and `-` for negatively charged ones.
class ChemicalFormula
{
public:
    /// Construct a default ChemicalFormula object.
    ChemicalFormula();

    /// Construct a ChemicalFormula object.
    /// @param formula A string such as `H2O`, `CaCO3`, `(CaMg)(CO3)2`.
    ChemicalFormula(const char* formula);

    /// Construct a ChemicalFormula object.
    /// @param formula A string such as `H2O`, `CaCO3`, `(CaMg)(CO3)2`.
    ChemicalFormula(std::string formula);

    /// Return the symbols of the elements in the chemical formula.
    auto symbols() const -> const std::vector<std::string>&;

    /// Return the coefficients of the elements in the chemical formula.
    auto coefficients() const -> const std::valarray<double>&;

    /// Return the coefficient of an element in the chemical formula.
    /// @param symbol The symbol of the element.
    auto coefficient(std::string symbol) const -> double;

    /// Return the electric charge of the chemical formula.
    auto charge() const -> double;

    /// Return the chemical formula as a string.
    auto str() const -> std::string;

    /// Convert this ChemicalFormula object into a string.
    explicit operator std::string() const;

private:
    /// The chemical formula as a string.
    std::string m_formula;

    /// The symbols of the elements in the chemical formula such a {"C", "O"} for CO2.
    std::vector<std::string> m_symbols;

    /// The coefficients of the elements in the chemical formula such a {1, 2} for CO2.
    std::valarray<double> m_coefficients;

    /// The electric charge of the chemical formula.
    double m_charge;
};

/// Compare two ChemicalFormula objects for less than
auto operator<(const ChemicalFormula& lhs, const ChemicalFormula& rhs) -> bool;

/// Compare two ChemicalFormula objects for equality
auto operator==(const ChemicalFormula& lhs, const ChemicalFormula& rhs) -> bool;

/// Return true if two chemical formulas are equivalent.
/// Equivalency is defined as two formulas with the same elemental composition.
/// For example, `Ca++` and `Ca+2`; and `CaCO3` and `Ca(CO3)`.
auto equivalent(const ChemicalFormula& lhs, const ChemicalFormula& rhs) -> bool;

} // namespace Atomik
