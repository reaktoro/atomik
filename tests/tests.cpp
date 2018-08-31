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
#include "catch.hpp"

// Atomik includes
#include <Atomik/Atomik.hpp>
using namespace Atomik;

TEST_CASE("Testing ChemicalFormula class", "[ChemicalFormula]")
{
    ChemicalFormula formula;

    formula = ChemicalFormula("H2O");
    REQUIRE(formula.formula() == "H2O");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("H") == 2);
    REQUIRE(formula.coefficient("O") == 1);
    REQUIRE(formula.elements().at("H") == 2);
    REQUIRE(formula.elements().at("O") == 1);

    formula = ChemicalFormula("CaCO3");
    REQUIRE(formula.formula() == "CaCO3");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("C") == 1);
    REQUIRE(formula.coefficient("Ca") == 1);
    REQUIRE(formula.coefficient("O") == 3);
    REQUIRE(formula.elements().at("C") == 1);
    REQUIRE(formula.elements().at("Ca") == 1);
    REQUIRE(formula.elements().at("O") == 3);

    formula = ChemicalFormula("HCO3-");
    REQUIRE(formula.formula() == "HCO3-");
    REQUIRE(formula.charge() == -1);
    REQUIRE(formula.coefficient("C") == 1);
    REQUIRE(formula.coefficient("H") == 1);
    REQUIRE(formula.coefficient("O") == 3);
    REQUIRE(formula.elements().at("C") == 1);
    REQUIRE(formula.elements().at("H") == 1);
    REQUIRE(formula.elements().at("O") == 3);

    formula = ChemicalFormula("H+");
    REQUIRE(formula.formula() == "H+");
    REQUIRE(formula.charge() == 1);
    REQUIRE(formula.coefficient("H") == 1);
    REQUIRE(formula.elements().at("H") == 1);

    formula = ChemicalFormula("Na+");
    REQUIRE(formula.formula() == "Na+");
    REQUIRE(formula.charge() == 1);
    REQUIRE(formula.coefficient("Na") == 1);
    REQUIRE(formula.elements().at("Na") == 1);

    formula = ChemicalFormula("Cl-");
    REQUIRE(formula.formula() == "Cl-");
    REQUIRE(formula.charge() == -1);
    REQUIRE(formula.coefficient("Cl") == 1);
    REQUIRE(formula.elements().at("Cl") == 1);

    formula = ChemicalFormula("CO3--");
    REQUIRE(formula.formula() == "CO3--");
    REQUIRE(formula.charge() == -2);
    REQUIRE(formula.coefficient("C") == 1);
    REQUIRE(formula.coefficient("O") == 3);
    REQUIRE(formula.elements().at("C") == 1);
    REQUIRE(formula.elements().at("O") == 3);

    formula = ChemicalFormula("CO3-2");
    REQUIRE(formula.formula() == "CO3-2");
    REQUIRE(formula.charge() == -2);
    REQUIRE(formula.coefficient("C") == 1);
    REQUIRE(formula.coefficient("O") == 3);
    REQUIRE(formula.elements().at("C") == 1);
    REQUIRE(formula.elements().at("O") == 3);

    formula = ChemicalFormula("Fe+++");
    REQUIRE(formula.formula() == "Fe+++");
    REQUIRE(formula.charge() == 3);
    REQUIRE(formula.coefficient("Fe") == 1);
    REQUIRE(formula.elements().at("Fe") == 1);

    formula = ChemicalFormula("Fe+3");
    REQUIRE(formula.formula() == "Fe+3");
    REQUIRE(formula.charge() == 3);
    REQUIRE(formula.coefficient("Fe") == 1);
    REQUIRE(formula.elements().at("Fe") == 1);

    formula = ChemicalFormula("(CaMg)(CO3)2");
    REQUIRE(formula.formula() == "(CaMg)(CO3)2");
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
    REQUIRE(formula.formula() == "CH3COOH");
    REQUIRE(formula.charge() == 0);
    REQUIRE(formula.coefficient("C") == 2);
    REQUIRE(formula.coefficient("H") == 4);
    REQUIRE(formula.coefficient("O") == 2);
    REQUIRE(formula.elements().at("C") == 2);
    REQUIRE(formula.elements().at("H") == 4);
    REQUIRE(formula.elements().at("O") == 2);
}

TEST_CASE("Testing Substance class", "[Substance]")
{
    Substance substance;

    substance = Substance("H2O");
    REQUIRE(substance.formula() == "H2O");
    REQUIRE(substance.charge() == 0);
    REQUIRE(substance.elements().size() == 2);
    REQUIRE(substance.molarMass() == Approx(0.01801528));
    REQUIRE(substance.coefficient("H") == 2);
    REQUIRE(substance.coefficient("O") == 1);

    substance = Substance("CaCO3");
    REQUIRE(substance.formula() == "CaCO3");
    REQUIRE(substance.charge() == 0);
    REQUIRE(substance.elements().size() == 3);
    REQUIRE(substance.molarMass() == Approx(0.1000869));
    REQUIRE(substance.coefficient("C") == 1);
    REQUIRE(substance.coefficient("Ca") == 1);
    REQUIRE(substance.coefficient("O") == 3);

    substance = Substance("HCO3-");
    REQUIRE(substance.formula() == "HCO3-");
    REQUIRE(substance.charge() == -1);
    REQUIRE(substance.elements().size() == 3);
    REQUIRE(substance.molarMass() == Approx(0.0610168));
    REQUIRE(substance.coefficient("C") == 1);
    REQUIRE(substance.coefficient("H") == 1);
    REQUIRE(substance.coefficient("O") == 3);

    substance = Substance("H+");
    REQUIRE(substance.formula() == "H+");
    REQUIRE(substance.charge() == 1);
    REQUIRE(substance.elements().size() == 1);
    REQUIRE(substance.molarMass() == Approx(0.00100794));
    REQUIRE(substance.coefficient("H") == 1);

    substance = Substance("Na+");
    REQUIRE(substance.formula() == "Na+");
    REQUIRE(substance.charge() == 1);
    REQUIRE(substance.elements().size() == 1);
    REQUIRE(substance.molarMass() == Approx(0.022989769));
    REQUIRE(substance.coefficient("Na") == 1);

    substance = Substance("Cl-");
    REQUIRE(substance.formula() == "Cl-");
    REQUIRE(substance.charge() == -1);
    REQUIRE(substance.elements().size() == 1);
    REQUIRE(substance.molarMass() == Approx(0.035453));
    REQUIRE(substance.coefficient("Cl") == 1);

    substance = Substance("CO3--");
    REQUIRE(substance.formula() == "CO3--");
    REQUIRE(substance.charge() == -2);
    REQUIRE(substance.elements().size() == 2);
    REQUIRE(substance.molarMass() == Approx(0.0600092));
    REQUIRE(substance.coefficient("C") == 1);
    REQUIRE(substance.coefficient("O") == 3);

    substance = Substance("Fe+++");
    REQUIRE(substance.formula() == "Fe+++");
    REQUIRE(substance.charge() == 3);
    REQUIRE(substance.elements().size() == 1);
    REQUIRE(substance.molarMass() == Approx(0.055847));
    REQUIRE(substance.coefficient("Fe") == 1);

    substance = Substance("(CaMg)(CO3)2");
    REQUIRE(substance.formula() == "(CaMg)(CO3)2");
    REQUIRE(substance.charge() == 0);
    REQUIRE(substance.elements().size() == 4);
    REQUIRE(substance.molarMass() == Approx(0.1844014));
    REQUIRE(substance.coefficient("C") == 2);
    REQUIRE(substance.coefficient("Ca") == 1);
    REQUIRE(substance.coefficient("Mg") == 1);
    REQUIRE(substance.coefficient("O") == 6);

    substance = Substance("CH3COOH");
    REQUIRE(substance.formula() == "CH3COOH");
    REQUIRE(substance.charge() == 0);
    REQUIRE(substance.elements().size() == 3);
    REQUIRE(substance.molarMass() == Approx(0.06005256));
    REQUIRE(substance.coefficient("C") == 2);
    REQUIRE(substance.coefficient("H") == 4);
    REQUIRE(substance.coefficient("O") == 2);
}
