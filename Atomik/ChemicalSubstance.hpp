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
#include <Atomik/ChemicalElement.hpp>
#include <Atomik/ChemicalElements.hpp>
#include <Atomik/ChemicalFormula.hpp>

namespace Atomik {

/// A type used to represent a chemical substance.
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
class ChemicalSubstance
{
public:
    /// Construct a default Substance object.
    ChemicalSubstance();

    /// Construct a Substance object with a given chemical formula. A default database of chemical elements is used construct the substance's elements.
    ChemicalSubstance(std::string formula);

    /// Construct a Substance object with a given chemical formula. A customized database of chemical elements is used to construct the substance's elements.
    ChemicalSubstance(std::string formula, const ChemicalElements& elements);

    /// Initialize the Substance object with a given chemical formula. A default database of chemical elements is used construct the substance's elements.
    auto initialize(std::string formula) -> void;

    /// Initialize the Substance object with a given chemical formula. A customized database of chemical elements is used to construct the substance's elements.
    auto initialize(std::string formula, const ChemicalElements& elements) -> void;

    /// Return the chemical formula of the substance.
    auto formula() const -> std::string;

    /// Return the chemical elements of the substance and their coefficients.
    auto elements() const -> const std::vector<std::tuple<ChemicalElement, double>>&;

    /// Return the electrical charge of the substance.
    auto charge() -> double;

    /// Return the molar mass of the substance (in unit of kg/mol).
    auto molarMass() -> double;

private:
    /// The chemical formula of the substance.
    ChemicalFormula m_formula;

    /// The chemical elements of the substance and their coefficients.
    std::vector<std::tuple<ChemicalElement, double>> m_elements;

    /// The molar mass of the substance (in unit of kg/mol).
    double m_molarmass;

};

} // namespace Atomik
