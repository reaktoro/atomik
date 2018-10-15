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

    REQUIRE(equivalent("Ca++", "Ca+2"));
    REQUIRE(equivalent("CO3--", "CO3-2"));
    REQUIRE(equivalent("Fe+++", "Fe+3"));
}
