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
}

TEST_CASE("Testing Substance class", "[Substance]")
{
    Substance substance;

    substance = Substance("H2O").name("WATER");
    REQUIRE(substance.uid() == "H2O");
    REQUIRE(substance.name() == "WATER");
    REQUIRE(substance.formula().str() == "H2O");
    REQUIRE(substance.charge() == 0);
    REQUIRE(substance.elements().size() == 2);
    REQUIRE(substance.molarMass() == Approx(0.01801528));
    REQUIRE(substance.coefficient("H") == 2);
    REQUIRE(substance.coefficient("O") == 1);

    substance = Substance("CaCO3").name("CALCIUM-CARBONATE").uid("CaCO3(calcite)");
    REQUIRE(substance.uid() == "CaCO3(calcite)");
    REQUIRE(substance.name() == "CALCIUM-CARBONATE");
    REQUIRE(substance.formula().str() == "CaCO3");
    REQUIRE(substance.charge() == 0);
    REQUIRE(substance.elements().size() == 3);
    REQUIRE(substance.molarMass() == Approx(0.1000869));
    REQUIRE(substance.coefficient("C") == 1);
    REQUIRE(substance.coefficient("Ca") == 1);
    REQUIRE(substance.coefficient("O") == 3);

    substance = Substance("HCO3-");
    REQUIRE(substance.uid() == "HCO3-");
    REQUIRE(substance.name() == "HCO3-");
    REQUIRE(substance.formula().str() == "HCO3-");
    REQUIRE(substance.charge() == -1);
    REQUIRE(substance.elements().size() == 3);
    REQUIRE(substance.molarMass() == Approx(0.0610168));
    REQUIRE(substance.coefficient("C") == 1);
    REQUIRE(substance.coefficient("H") == 1);
    REQUIRE(substance.coefficient("O") == 3);

    substance = Substance("H+");
    REQUIRE(substance.uid() == "H+");
    REQUIRE(substance.name() == "H+");
    REQUIRE(substance.formula().str() == "H+");
    REQUIRE(substance.charge() == 1);
    REQUIRE(substance.elements().size() == 1);
    REQUIRE(substance.molarMass() == Approx(0.00100794));
    REQUIRE(substance.coefficient("H") == 1);

    substance = Substance("Na+");
    REQUIRE(substance.uid() == "Na+");
    REQUIRE(substance.name() == "Na+");
    REQUIRE(substance.formula().str() == "Na+");
    REQUIRE(substance.charge() == 1);
    REQUIRE(substance.elements().size() == 1);
    REQUIRE(substance.molarMass() == Approx(0.022989769));
    REQUIRE(substance.coefficient("Na") == 1);

    substance = Substance("Cl-");
    REQUIRE(substance.uid() == "Cl-");
    REQUIRE(substance.name() == "Cl-");
    REQUIRE(substance.formula().str() == "Cl-");
    REQUIRE(substance.charge() == -1);
    REQUIRE(substance.elements().size() == 1);
    REQUIRE(substance.molarMass() == Approx(0.035453));
    REQUIRE(substance.coefficient("Cl") == 1);

    substance = Substance("CO3--");
    REQUIRE(substance.uid() == "CO3--");
    REQUIRE(substance.name() == "CO3--");
    REQUIRE(substance.formula().str() == "CO3--");
    REQUIRE(substance.charge() == -2);
    REQUIRE(substance.elements().size() == 2);
    REQUIRE(substance.molarMass() == Approx(0.0600092));
    REQUIRE(substance.coefficient("C") == 1);
    REQUIRE(substance.coefficient("O") == 3);

    substance = Substance("Fe+++");
    REQUIRE(substance.name() == "Fe+++");
    REQUIRE(substance.formula().str() == "Fe+++");
    REQUIRE(substance.charge() == 3);
    REQUIRE(substance.elements().size() == 1);
    REQUIRE(substance.molarMass() == Approx(0.055847));
    REQUIRE(substance.coefficient("Fe") == 1);

    substance = Substance("(CaMg)(CO3)2").name("CALCIUM-MAGNESIUM-CARBONATE").uid("(CaMg)(CO3)2(dolomite)");
    REQUIRE(substance.uid() == "(CaMg)(CO3)2(dolomite)");
    REQUIRE(substance.name() == "CALCIUM-MAGNESIUM-CARBONATE");
    REQUIRE(substance.formula().str() == "(CaMg)(CO3)2");
    REQUIRE(substance.charge() == 0);
    REQUIRE(substance.elements().size() == 4);
    REQUIRE(substance.molarMass() == Approx(0.1844014));
    REQUIRE(substance.coefficient("C") == 2);
    REQUIRE(substance.coefficient("Ca") == 1);
    REQUIRE(substance.coefficient("Mg") == 1);
    REQUIRE(substance.coefficient("O") == 6);

    substance = Substance("CH3COOH");
    REQUIRE(substance.uid() == "CH3COOH");
    REQUIRE(substance.name() == "CH3COOH");
    REQUIRE(substance.formula().str() == "CH3COOH");
    REQUIRE(substance.charge() == 0);
    REQUIRE(substance.elements().size() == 3);
    REQUIRE(substance.molarMass() == Approx(0.06005256));
    REQUIRE(substance.coefficient("C") == 2);
    REQUIRE(substance.coefficient("H") == 4);
    REQUIRE(substance.coefficient("O") == 2);

    REQUIRE_THROWS(Substance("CaCO3").name("CALCIUM CARBONATE")); // runtime error if substance name has space
    REQUIRE_THROWS(Substance("CaCO3").uid("CaCO3 calcite")); // runtime error if substance uid has space

    ElementDatabase elements;
    elements.append({"Aa"});
    elements.append({"Bb"});

    substance = Substance("AaBb2+", elements);
    REQUIRE(substance.uid() == "AaBb2+");
    REQUIRE(substance.name() == "AaBb2+");
    REQUIRE(substance.formula().str() == "AaBb2+");
    REQUIRE(substance.charge() == 1);
    REQUIRE(substance.elements().size() == 2);
    REQUIRE(substance.molarMass() == Approx(0.0));
    REQUIRE(substance.coefficient("Aa") == 1);
    REQUIRE(substance.coefficient("Bb") == 2);
}
