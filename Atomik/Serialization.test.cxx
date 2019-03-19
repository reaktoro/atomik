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
#include <Atomik/Element.hpp>
#include <Atomik/Elements.hpp>
#include <Atomik/Formula.hpp>
#include <Atomik/Serialization.hpp>
#include <Atomik/Substance.hpp>
#include <Atomik/Substances.hpp>
using namespace Atomik;

namespace strings {

std::string formula = R"(
label: CO2
symbols: [C, O]
coefficients: [1, 2]
)";

std::string element = R"(
symbol: H
name: Hydrogen
atomicNumber: 1
atomicWeight: 0.001007940
electronegativity: 2.20
tags: [ group1 ]
)";

std::string substance = R"(
name: Calcite
formula:
  label: CaCO3
  symbols: [C, Ca, O]
  coefficients: [1, 1, 3]
tags: [mineral, solid]
)";

std::string elements = R"(
- name: Hydrogen
  symbol: H
  atomicNumber: 1
  atomicWeight: 0.001007940
  electronegativity: 2.20
  tags: []

- name: Carbon
  symbol: C
  atomicNumber: 6
  atomicWeight: 0.012011000
  electronegativity: 2.55
  tags: []

- name: Oxygen
  symbol: O
  atomicNumber: 8
  atomicWeight: 0.015999400
  electronegativity: 3.44
  tags: []
)";

std::string substances = R"(
- name: H2O(aq)
  formula:
    label: H2O
    symbols: [H, O]
    coefficients: [2, 1]
  tags: [ aqueous ]

- name: Na+(aq)
  formula:
    label: Na+
    symbols: [Na, Z]
    coefficients: [1, 1]
  tags: [ aqueous ]

- name: Cl-(aq)
  formula:
    label: Cl-
    symbols: [Cl, Z]
    coefficients: [1, -1]
  tags: [ aqueous ]

- name: H2O(g)
  formula:
    label: H2O
    symbols: [H, O]
    coefficients: [2, 1]
  tags: [ gaseous ]

- name: CO2(g)
  formula:
    label: CO2
    symbols: [C, O]
    coefficients: [1, 2]
  tags: [ gaseous ]
)";

} // namespace strings


TEST_CASE("Testing Serialization", "[Serialization]")
{
    Formula formula = yaml(strings::formula);

    CHECK( formula.label() == "CO2" );
    CHECK( formula.symbols().size() == 2 );
    CHECK( formula.coefficient("C") == 1 );
    CHECK( formula.coefficient("O") == 2 );

    Element element = yaml(strings::element);

    CHECK( element.symbol() == "H" );
    CHECK( element.name() == "Hydrogen" );
    CHECK( element.atomicNumber() == 1 );
    CHECK( element.atomicWeight() == 0.001007940 );
    CHECK( element.electronegativity() == 2.20 );
    CHECK( element.tags().size() == 1 );
    CHECK( element.tags().at(0) == "group1" );

    Substance substance = yaml(strings::substance);

    CHECK( substance.formula().equivalent("CaCO3") );
    CHECK( substance.name() == "Calcite" );
    CHECK( substance.tags().size() == 2 );
    CHECK( substance.tags().at(0) == "mineral" );
    CHECK( substance.tags().at(1) == "solid" );

    Elements elements = yaml(strings::elements);

    CHECK( elements.size() == 3 );

    CHECK( elements[0].name() == "Hydrogen" );
    CHECK( elements[0].symbol() == "H" );
    CHECK( elements[0].atomicNumber() == 1 );
    CHECK( elements[0].atomicWeight() == 0.001007940 );
    CHECK( elements[0].electronegativity() == 2.20 );

    CHECK( elements[1].name() == "Carbon" );
    CHECK( elements[1].symbol() == "C" );
    CHECK( elements[1].atomicNumber() == 6 );
    CHECK( elements[1].atomicWeight() == 0.012011000 );
    CHECK( elements[1].electronegativity() == 2.55 );

    CHECK( elements[2].name() == "Oxygen" );
    CHECK( elements[2].symbol() == "O" );
    CHECK( elements[2].atomicNumber() == 8 );
    CHECK( elements[2].atomicWeight() == 0.015999400 );
    CHECK( elements[2].electronegativity() == 3.44 );

    Substances substances = yaml(strings::substances);

    CHECK( substances.size() == 5 );

    CHECK( substances[0].name() == "H2O(aq)" );
    CHECK( substances[0].formula().equivalent("H2O") );
    CHECK( substances[0].tags().size() == 1 );
    CHECK( substances[0].tags().at(0) == "aqueous" );

    CHECK( substances[1].name() == "Na+(aq)" );
    CHECK( substances[1].formula().equivalent("Na+") );
    CHECK( substances[1].tags().size() == 1 );
    CHECK( substances[1].tags().at(0) == "aqueous" );

    CHECK( substances[2].name() == "Cl-(aq)" );
    CHECK( substances[2].formula().equivalent("Cl-") );
    CHECK( substances[2].tags().size() == 1 );
    CHECK( substances[2].tags().at(0) == "aqueous" );

    CHECK( substances[3].name() == "H2O(g)" );
    CHECK( substances[3].formula().equivalent("H2O") );
    CHECK( substances[3].tags().size() == 1 );
    CHECK( substances[3].tags().at(0) == "gaseous" );

    CHECK( substances[4].name() == "CO2(g)" );
    CHECK( substances[4].formula().equivalent("CO2") );
    CHECK( substances[4].tags().size() == 1 );
    CHECK( substances[4].tags().at(0) == "gaseous" );
}
