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

// Catch includes
#include <catch/catch.hpp>

// Atomik includes
#include <Atomik/Atomik.hpp>
using namespace Atomik;

TEST_CASE("Testing ChemicalFormula class", "[ChemicalFormula]")
{
    ChemicalFormula formula;

    formula = ChemicalFormula("H2O");
    REQUIRE(formula.str() == "H2O");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("H") == 2);
    REQUIRE(formula.coefficient("O") == 1);
    REQUIRE(formula.elements().at("H") == 2);
    REQUIRE(formula.elements().at("O") == 1);

    formula = ChemicalFormula("CaCO3");
    REQUIRE(formula.str() == "CaCO3");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("C") == 1);
    REQUIRE(formula.coefficient("Ca") == 1);
    REQUIRE(formula.coefficient("O") == 3);
    REQUIRE(formula.elements().at("C") == 1);
    REQUIRE(formula.elements().at("Ca") == 1);
    REQUIRE(formula.elements().at("O") == 3);

    formula = ChemicalFormula("HCO3-");
    REQUIRE(formula.str() == "HCO3-");
    REQUIRE(formula.charge() == -1);
    REQUIRE(formula.coefficient("C") == 1);
    REQUIRE(formula.coefficient("H") == 1);
    REQUIRE(formula.coefficient("O") == 3);
    REQUIRE(formula.elements().at("C") == 1);
    REQUIRE(formula.elements().at("H") == 1);
    REQUIRE(formula.elements().at("O") == 3);

    formula = ChemicalFormula("H+");
    REQUIRE(formula.str() == "H+");
    REQUIRE(formula.charge() == 1);
    REQUIRE(formula.coefficient("H") == 1);
    REQUIRE(formula.elements().at("H") == 1);

    formula = ChemicalFormula("Na+");
    REQUIRE(formula.str() == "Na+");
    REQUIRE(formula.charge() == 1);
    REQUIRE(formula.coefficient("Na") == 1);
    REQUIRE(formula.elements().at("Na") == 1);

    formula = ChemicalFormula("Cl-");
    REQUIRE(formula.str() == "Cl-");
    REQUIRE(formula.charge() == -1);
    REQUIRE(formula.coefficient("Cl") == 1);
    REQUIRE(formula.elements().at("Cl") == 1);

    formula = ChemicalFormula("CO3--");
    REQUIRE(formula.str() == "CO3--");
    REQUIRE(formula.charge() == -2);
    REQUIRE(formula.coefficient("C") == 1);
    REQUIRE(formula.coefficient("O") == 3);
    REQUIRE(formula.elements().at("C") == 1);
    REQUIRE(formula.elements().at("O") == 3);

    formula = ChemicalFormula("CO3-2");
    REQUIRE(formula.str() == "CO3-2");
    REQUIRE(formula.charge() == -2);
    REQUIRE(formula.coefficient("C") == 1);
    REQUIRE(formula.coefficient("O") == 3);
    REQUIRE(formula.elements().at("C") == 1);
    REQUIRE(formula.elements().at("O") == 3);

    formula = ChemicalFormula("Fe+++");
    REQUIRE(formula.str() == "Fe+++");
    REQUIRE(formula.charge() == 3);
    REQUIRE(formula.coefficient("Fe") == 1);
    REQUIRE(formula.elements().at("Fe") == 1);

    formula = ChemicalFormula("Fe+3");
    REQUIRE(formula.str() == "Fe+3");
    REQUIRE(formula.charge() == 3);
    REQUIRE(formula.coefficient("Fe") == 1);
    REQUIRE(formula.elements().at("Fe") == 1);

    formula = ChemicalFormula("(CaMg)(CO3)2");
    REQUIRE(formula.str() == "(CaMg)(CO3)2");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("C") == 2);
    REQUIRE(formula.coefficient("Ca") == 1);
    REQUIRE(formula.coefficient("Mg") == 1);
    REQUIRE(formula.coefficient("O") == 6);
    REQUIRE(formula.elements().at("C") == 2);
    REQUIRE(formula.elements().at("Ca") == 1);
    REQUIRE(formula.elements().at("Mg") == 1);
    REQUIRE(formula.elements().at("O") == 6);

    formula = ChemicalFormula("CH3COOH");
    REQUIRE(formula.str() == "CH3COOH");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("C") == 2);
    REQUIRE(formula.coefficient("H") == 4);
    REQUIRE(formula.coefficient("O") == 2);
    REQUIRE(formula.elements().at("C") == 2);
    REQUIRE(formula.elements().at("H") == 4);
    REQUIRE(formula.elements().at("O") == 2);

    formula = ChemicalFormula("Al2.5Si0.5O4.75");
    REQUIRE(formula.str() == "Al2.5Si0.5O4.75");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("Al") == 2.5);
    REQUIRE(formula.coefficient("Si") == 0.5);
    REQUIRE(formula.coefficient("O") == 4.75);
    REQUIRE(formula.elements().at("Al") == 2.5);
    REQUIRE(formula.elements().at("Si") == 0.5);
    REQUIRE(formula.elements().at("O") == 4.75);

    formula = ChemicalFormula("Fe4Al18Si7.5O48H4");
    REQUIRE(formula.str() == "Fe4Al18Si7.5O48H4");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("Fe") == 4);
    REQUIRE(formula.coefficient("Al") == 18);
    REQUIRE(formula.coefficient("Si") == 7.5);
    REQUIRE(formula.coefficient("O") == 48);
    REQUIRE(formula.coefficient("H") == 4);
    REQUIRE(formula.elements().at("Fe") == 4);
    REQUIRE(formula.elements().at("Al") == 18);
    REQUIRE(formula.elements().at("Si") == 7.5);
    REQUIRE(formula.elements().at("O") == 48);
    REQUIRE(formula.elements().at("H") == 4);

    formula = ChemicalFormula("Mg4Al18Si7.5O48H4");
    REQUIRE(formula.str() == "Mg4Al18Si7.5O48H4");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("Mg") == 4);
    REQUIRE(formula.coefficient("Al") == 18);
    REQUIRE(formula.coefficient("Si") == 7.5);
    REQUIRE(formula.coefficient("O") == 48);
    REQUIRE(formula.coefficient("H") == 4);
    REQUIRE(formula.elements().at("Mg") == 4);
    REQUIRE(formula.elements().at("Al") == 18);
    REQUIRE(formula.elements().at("Si") == 7.5);
    REQUIRE(formula.elements().at("O") == 48);
    REQUIRE(formula.elements().at("H") == 4);

    formula = ChemicalFormula("Mn4Al18Si7.5O48H4");
    REQUIRE(formula.str() == "Mn4Al18Si7.5O48H4");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("Mn") == 4);
    REQUIRE(formula.coefficient("Al") == 18);
    REQUIRE(formula.coefficient("Si") == 7.5);
    REQUIRE(formula.coefficient("O") == 48);
    REQUIRE(formula.coefficient("H") == 4);
    REQUIRE(formula.elements().at("Mn") == 4);
    REQUIRE(formula.elements().at("Al") == 18);
    REQUIRE(formula.elements().at("Si") == 7.5);
    REQUIRE(formula.elements().at("O") == 48);
    REQUIRE(formula.elements().at("H") == 4);

    formula = ChemicalFormula("Ca0.5Al1Si2O6");
    REQUIRE(formula.str() == "Ca0.5Al1Si2O6");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("Ca") == 0.5);
    REQUIRE(formula.coefficient("Al") == 1);
    REQUIRE(formula.coefficient("Si") == 2);
    REQUIRE(formula.coefficient("O") == 6);
    REQUIRE(formula.elements().at("Ca") == 0.5);
    REQUIRE(formula.elements().at("Al") == 1);
    REQUIRE(formula.elements().at("Si") == 2);
    REQUIRE(formula.elements().at("O") == 6);

    formula = ChemicalFormula("K0.5Fe5Al2Si8O30.5H12.5");
    REQUIRE(formula.str() == "K0.5Fe5Al2Si8O30.5H12.5");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("K") == 0.5);
    REQUIRE(formula.coefficient("Fe") == 5);
    REQUIRE(formula.coefficient("Al") == 2);
    REQUIRE(formula.coefficient("Si") == 8);
    REQUIRE(formula.coefficient("O") == 30.5);
    REQUIRE(formula.coefficient("H") == 12.5);
    REQUIRE(formula.elements().at("K") == 0.5);
    REQUIRE(formula.elements().at("Fe") == 5);
    REQUIRE(formula.elements().at("Al") == 2);
    REQUIRE(formula.elements().at("Si") == 8);
    REQUIRE(formula.elements().at("O") == 30.5);
    REQUIRE(formula.elements().at("H") == 12.5);

    formula = ChemicalFormula("K0.5Mg5Al2Si8O30.5H12.5");
    REQUIRE(formula.str() == "K0.5Mg5Al2Si8O30.5H12.5");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("K") == 0.5);
    REQUIRE(formula.coefficient("Mg") == 5);
    REQUIRE(formula.coefficient("Al") == 2);
    REQUIRE(formula.coefficient("Si") == 8);
    REQUIRE(formula.coefficient("O") == 30.5);
    REQUIRE(formula.coefficient("H") == 12.5);
    REQUIRE(formula.elements().at("K") == 0.5);
    REQUIRE(formula.elements().at("Mg") == 5);
    REQUIRE(formula.elements().at("Al") == 2);
    REQUIRE(formula.elements().at("Si") == 8);
    REQUIRE(formula.elements().at("O") == 30.5);
    REQUIRE(formula.elements().at("H") == 12.5);

    formula = ChemicalFormula("Mg3.5Al9Si1.5O20");
    REQUIRE(formula.str() == "Mg3.5Al9Si1.5O20");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("Mg") == 3.5);
    REQUIRE(formula.coefficient("Al") == 9);
    REQUIRE(formula.coefficient("Si") == 1.5);
    REQUIRE(formula.coefficient("O") == 20);
    REQUIRE(formula.elements().at("Mg") == 3.5);
    REQUIRE(formula.elements().at("Al") == 9);
    REQUIRE(formula.elements().at("Si") == 1.5);
    REQUIRE(formula.elements().at("O") == 20);

    formula = ChemicalFormula("Fe3.5Al9Si1.5O20");
    REQUIRE(formula.str() == "Fe3.5Al9Si1.5O20");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("Fe") == 3.5);
    REQUIRE(formula.coefficient("Al") == 9);
    REQUIRE(formula.coefficient("Si") == 1.5);
    REQUIRE(formula.coefficient("O") == 20);
    REQUIRE(formula.elements().at("Fe") == 3.5);
    REQUIRE(formula.elements().at("Al") == 9);
    REQUIRE(formula.elements().at("Si") == 1.5);
    REQUIRE(formula.elements().at("O") == 20);

    formula = ChemicalFormula("Fe0.875S1");
    REQUIRE(formula.str() == "Fe0.875S1");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("Fe") == 0.875);
    REQUIRE(formula.coefficient("S") == 1);
    REQUIRE(formula.elements().at("Fe") == 0.875);
    REQUIRE(formula.elements().at("S") == 1);

    REQUIRE(equivalent("Ca++", "Ca+2"));
    REQUIRE(equivalent("CO3--", "CO3-2"));
    REQUIRE(equivalent("Fe+++", "Fe+3"));
}
