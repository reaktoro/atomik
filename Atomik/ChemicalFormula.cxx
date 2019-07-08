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

// Catch includes
#include <catch2/catch.hpp>

// Atomik includes
#include <Atomik/ChemicalFormula.hpp>
using namespace Atomik;

TEST_CASE("Testing ChemicalFormula class", "[ChemicalFormula]")
{
    std::unordered_map<std::string, double> formula;

    formula = parseChemicalFormula("H2O");
    REQUIRE(formula.size() == 2);
    REQUIRE(formula["H"] == 2);
    REQUIRE(formula["O"] == 1);

    formula = parseChemicalFormula("CaCO3");
    REQUIRE(formula.size() == 3);
    REQUIRE(formula["C"] == 1);
    REQUIRE(formula["Ca"] == 1);
    REQUIRE(formula["O"] == 3);

    formula = parseChemicalFormula("HCO3-");
    REQUIRE(formula.size() == 4);
    REQUIRE(formula["C"] == 1);
    REQUIRE(formula["H"] == 1);
    REQUIRE(formula["O"] == 3);
    REQUIRE(formula["Z"] == -1);

    formula = parseChemicalFormula("H+");
    REQUIRE(formula.size() == 2);
    REQUIRE(formula["H"] == 1);
    REQUIRE(formula["Z"] == 1);

    formula = parseChemicalFormula("Na+");
    REQUIRE(formula.size() == 2);
    REQUIRE(formula["Na"] == 1);
    REQUIRE(formula["Z"] == 1);

    formula = parseChemicalFormula("Cl-");
    REQUIRE(formula.size() == 2);
    REQUIRE(formula["Cl"] == 1);
    REQUIRE(formula["Z"] == -1);

    formula = parseChemicalFormula("CO3--");
    REQUIRE(formula.size() == 3);
    REQUIRE(formula["C"] == 1);
    REQUIRE(formula["O"] == 3);
    REQUIRE(formula["Z"] == -2);

    formula = parseChemicalFormula("CO3-2");
    REQUIRE(formula.size() == 3);
    REQUIRE(formula["C"] == 1);
    REQUIRE(formula["O"] == 3);
    REQUIRE(formula["Z"] == -2);

    formula = parseChemicalFormula("Fe+++");
    REQUIRE(formula.size() == 2);
    REQUIRE(formula["Fe"] == 1);
    REQUIRE(formula["Z"] == 3);

    formula = parseChemicalFormula("Fe+3");
    REQUIRE(formula.size() == 2);
    REQUIRE(formula["Fe"] == 1);
    REQUIRE(formula["Z"] == 3);

    formula = parseChemicalFormula("(CaMg)(CO3)2");
    REQUIRE(formula.size() == 4);
    REQUIRE(formula["C"] == 2);
    REQUIRE(formula["Ca"] == 1);
    REQUIRE(formula["Mg"] == 1);
    REQUIRE(formula["O"] == 6);

    formula = parseChemicalFormula("CH3COOH");
    REQUIRE(formula.size() == 3);
    REQUIRE(formula["C"] == 2);
    REQUIRE(formula["H"] == 4);
    REQUIRE(formula["O"] == 2);

    formula = parseChemicalFormula("Al2.5Si0.5O4.75");
    REQUIRE(formula.size() == 3);
    REQUIRE(formula["Al"] == 2.5);
    REQUIRE(formula["Si"] == 0.5);
    REQUIRE(formula["O"] == 4.75);

    formula = parseChemicalFormula("Fe4Al18Si7.5O48H4");
    REQUIRE(formula.size() == 5);
    REQUIRE(formula["Fe"] == 4);
    REQUIRE(formula["Al"] == 18);
    REQUIRE(formula["Si"] == 7.5);
    REQUIRE(formula["O"] == 48);
    REQUIRE(formula["H"] == 4);

    formula = parseChemicalFormula("Mg4Al18Si7.5O48H4");
    REQUIRE(formula.size() == 5);
    REQUIRE(formula["Mg"] == 4);
    REQUIRE(formula["Al"] == 18);
    REQUIRE(formula["Si"] == 7.5);
    REQUIRE(formula["O"] == 48);
    REQUIRE(formula["H"] == 4);

    formula = parseChemicalFormula("Mn4Al18Si7.5O48H4");
    REQUIRE(formula.size() == 5);
    REQUIRE(formula["Mn"] == 4);
    REQUIRE(formula["Al"] == 18);
    REQUIRE(formula["Si"] == 7.5);
    REQUIRE(formula["O"] == 48);
    REQUIRE(formula["H"] == 4);

    formula = parseChemicalFormula("Ca0.5Al1Si2O6");
    REQUIRE(formula.size() == 4);
    REQUIRE(formula["Ca"] == 0.5);
    REQUIRE(formula["Al"] == 1);
    REQUIRE(formula["Si"] == 2);
    REQUIRE(formula["O"] == 6);

    formula = parseChemicalFormula("K0.5Fe5Al2Si8O30.5H12.5");
    REQUIRE(formula.size() == 6);
    REQUIRE(formula["K"] == 0.5);
    REQUIRE(formula["Fe"] == 5);
    REQUIRE(formula["Al"] == 2);
    REQUIRE(formula["Si"] == 8);
    REQUIRE(formula["O"] == 30.5);
    REQUIRE(formula["H"] == 12.5);

    formula = parseChemicalFormula("K0.5Mg5Al2Si8O30.5H12.5");
    REQUIRE(formula.size() == 6);
    REQUIRE(formula["K"] == 0.5);
    REQUIRE(formula["Mg"] == 5);
    REQUIRE(formula["Al"] == 2);
    REQUIRE(formula["Si"] == 8);
    REQUIRE(formula["O"] == 30.5);
    REQUIRE(formula["H"] == 12.5);

    formula = parseChemicalFormula("Mg3.5Al9Si1.5O20");
    REQUIRE(formula.size() == 4);
    REQUIRE(formula["Mg"] == 3.5);
    REQUIRE(formula["Al"] == 9);
    REQUIRE(formula["Si"] == 1.5);
    REQUIRE(formula["O"] == 20);

    formula = parseChemicalFormula("Fe3.5Al9Si1.5O20");
    REQUIRE(formula.size() == 4);
    REQUIRE(formula["Fe"] == 3.5);
    REQUIRE(formula["Al"] == 9);
    REQUIRE(formula["Si"] == 1.5);
    REQUIRE(formula["O"] == 20);

    formula = parseChemicalFormula("Fe0.875S1");
    REQUIRE(formula.size() == 2);
    REQUIRE(formula["Fe"] == 0.875);
    REQUIRE(formula["S"] == 1);
}
