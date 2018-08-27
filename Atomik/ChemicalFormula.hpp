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

/// A type used to represent a chemical formula of a substance.
/// The chemical formula of a substance can be represented by a
/// string  with the following formats:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// std::string formula1 = "H2O";
/// std::string formula2 = "CaCl2";
/// std::string formula3 = "MgCO3";
/// std::string formula4 = "(CaMg)(CO3)2";
/// std::string formula5 = "Fe3Al2Si3O12";
/// std::string formula6 = "Na+";
/// std::string formula7 = "Ca++";
/// std::string formula8 = "Fe+++";
/// std::string formula9 = "CO3--";
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// The electric charge of the substance is represented by a suffix
/// containing as many symbols `+` and `-` as there are charges,
/// with `+` used for positively charged substances, and `-` for
/// negatively charged ones.
class ChemicalFormula
{
public:
    /// Construct a default ChemicalFormula object.
    ChemicalFormula();

    /// Construct a ChemicalFormula object with given chemical formula.
    ChemicalFormula(std::string formula);

    /// Initialize the ChemicalFormula object with a given chemical formula.
    auto initialize(std::string formula) -> void;

    /// Return the chemical formula string.
    auto formula() const -> std::string;

    /// Return the elements in the chemical formula and their coefficients.
    auto elements() const -> std::map<std::string, double>;

    /// Return the electrical charge of the chemical formula.
    auto charge() -> double;

    /// Return the coefficient of an element symbol in the chemical formula.
    auto coefficient(std::string symbol) const -> double;

private:
    /// The chemical formula as a string.
    std::string m_formula;

    /// The elements in the chemical formula and their coefficients.
    std::map<std::string, double> m_elements;

    /// The electrical charge of the chemical formula.
    double m_charge;
};

} // namespace Atomik
