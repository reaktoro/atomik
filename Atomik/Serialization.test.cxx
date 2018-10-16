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

// C++ includes
#include <sstream>

// Atomik includes
#include <Atomik/ChemicalFormula.hpp>
#include <Atomik/Serialization.hpp>
#include <Atomik/Element.hpp>
using namespace Atomik;

TEST_CASE("Testing serialization of ChemicalFormula", "[Serialization]")
{
    ChemicalFormula formula;

    std::istringstream iss("CaCO3");
    iss >> formula;

    CHECK(formula.str() == "CaCO3");
    CHECK(formula.coefficient("Ca") == 1);
    CHECK(formula.coefficient("C") == 1);
    CHECK(formula.coefficient("O") == 3);
}

TEST_CASE("Testing serialization of Element", "[Serialization]")
{
    Element element;

    std::istringstream iss("H Hydrogen 1 1.00794 2.2");
    iss >> element;

    CHECK(element.symbol() == "H");
    CHECK(element.name() == "Hydrogen");
    CHECK(element.atomicNumber() == 1);
    CHECK(element.atomicWeight() == 1.00794);
    CHECK(element.electronegativity() == 2.2);
}
