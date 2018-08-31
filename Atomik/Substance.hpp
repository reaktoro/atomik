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
#include <tuple>
#include <vector>

// Atomik includes
#include <Atomik/ChemicalFormula.hpp>
#include <Atomik/Element.hpp>
#include <Atomik/ElementDatabase.hpp>

namespace Atomik {

/// A type used to represent a chemical substance.
/// The chemical formula of a substance can be represented by a string with the following formats:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// Substance substance01("H2O");
/// Substance substance02("CaCl2");
/// Substance substance03("MgCO3");
/// Substance substance04("(CaMg)(CO3)2");
/// Substance substance05("Fe3Al2Si3O12");
/// Substance substance06("Na+");
/// Substance substance07("Ca++");
/// Substance substance08("Fe+++");
/// Substance substance09("Fe+3");
/// Substance substance10("CO3--");
/// Substance substance11("CO3-2");
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// There are two ways of specifying the electric charge of the substance:
///   1. as a suffix containing as many symbols `+` and `-` as there are charges (e.g., `Fe+++`, `Ca++`, `CO3--`); or
///   2. as a suffix containing the symbol `+` or `-` followed by the number of charges (e.g., `Fe+3`, `Ca+2`, `Na+`)
/// Note that number 1 is optional for the second formart.
/// In both formats, the symbol `+` is used for positively charged substances, and `-` for negatively charged ones.
class Substance
{
public:
    /// Construct a default Substance object.
    Substance();

    /// Construct a Substance object with a given chemical formula.
    /// A default database of chemical elements is used to construct the elements composing the substance.
    /// @param formula The chemical formula of the substance (e.g., "H2O", "CaCO3", "CO3--", "CO3-2").
    Substance(std::string formula);

    /// Construct a Substance object with a given chemical formula.
    /// @param formula The chemical formula of the substance (e.g., "H2O", "CaCO3", "CO3--", "CO3-2").
    /// @param elementdb The user-defined database of chemical elements.
    Substance(std::string formula, const ElementDatabase& elementdb);

    /// Return the chemical formula of the substance.
    auto formula() const -> std::string;

    /// Return the chemical elements of the substance and their coefficients.
    auto elements() const -> const std::vector<std::tuple<Element, double>>&;

    /// Return the electrical charge of the substance.
    auto charge() -> double;

    /// Return the molar mass of the substance (in unit of kg/mol).
    auto molarMass() -> double;

private:
    /// The name of the substance.
    std::string m_name;

    /// The chemical formula of the substance.
    ChemicalFormula m_formula;

    /// The chemical elements of the substance and their coefficients.
    std::vector<std::tuple<Element, double>> m_elements;

    /// The molar mass of the substance (in unit of kg/mol).
    double m_molarmass;

};

} // namespace Atomik
