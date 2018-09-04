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
#include <map>

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
    /// Construct a default ChemicalFormula object.
    ChemicalFormula();

    /// Construct a ChemicalFormula object with given chemical formula.
    ChemicalFormula(std::string formula);

    /// Return the chemical formula string.
    auto str() const -> std::string;

    /// Return the elements in the chemical formula and their coefficients.
    auto elements() const -> std::map<std::string, double>;

    /// Return the electric charge of the chemical formula.
    auto charge() const -> double;

    /// Return the coefficient of an element symbol in the chemical formula.
    auto coefficient(std::string symbol) const -> double;

    /// Convert this ChemicalFormula object into a std::string.
    operator std::string() const;

private:
    /// The chemical formula as a string.
    std::string m_formula;

    /// The elements in the chemical formula and their coefficients.
    std::map<std::string, double> m_elements;

    /// The electrical charge of the chemical formula.
    double m_charge;
};

} // namespace Atomik
