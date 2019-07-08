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
#include <string>
#include <unordered_map>

namespace Atomik {

/// Return the element symbols and their coefficients in a chemical formula.
/// Successfully parsing a chemical formula requires that the first letter in
/// the formula is uppercase and all others in lowercase. Thus, even chemical
/// formulas such as `AaBbb` or `(Aa2Bbb4)Cc6` are supported.
/// There are two ways for specifying electric charge in a chemical formula:
///   1. as a suffix containing as many symbols `+` and `-` as there are charges (e.g., `Fe+++`, `Ca++`, `CO3--`); or
///   2. as a suffix containing the symbol `+` or `-` followed by the number of charges (e.g., `Fe+3`, `Ca+2`, `Na+`)
/// Note that number 1 is optional for the second format (e.g., `Na+` and `Na+1` are equivalent).
/// In both formats, (1) and (2), the symbol `+` is used for positively charged substances, and `-` for negatively charged ones.
/// See below several examples of parsing different chemical formulas:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/// using namespace Atomik;
/// auto formula01 = parseChemicalFormula("H2O");
/// auto formula02 = parseChemicalFormula("CaCl2");
/// auto formula03 = parseChemicalFormula("MgCO3");
/// auto formula04 = parseChemicalFormula("(CaMg)(CO3)2");
/// auto formula05 = parseChemicalFormula("Fe3Al2Si3O12");
/// auto formula06 = parseChemicalFormula("Na+");
/// auto formula07 = parseChemicalFormula("Ca++");
/// auto formula08 = parseChemicalFormula("Fe+++");
/// auto formula09 = parseChemicalFormula("Fe+3");
/// auto formula10 = parseChemicalFormula("CO3--");
/// auto formula11 = parseChemicalFormula("CO3-2");
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
auto parseChemicalFormula(const std::string& formula) -> std::unordered_map<std::string, double>;

} // namespace Atomik
