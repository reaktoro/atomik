// Atomik is a library that implements basic chemical concepts such as elements, substances, and reactions.
//
// Copyright (C) 2014-2019 Allan Leal and Atomik Contributors
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
#include <Atomik/Element.hpp>
#include <Atomik/Elements.hpp>
#include <Atomik/Substance.hpp>
#include <Atomik/Substances.hpp>
#include <Atomik/YAML.hpp>
using namespace Atomik;

namespace strings {

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
formula: CaCO3
tags: [mineral, solid]
)";

std::string elements = R"(
- name: Hydrogen
  symbol: H
  atomicNumber: 1
  atomicWeight: 0.001007940
  electronegativity: 2.20

- name: Carbon
  symbol: C
  atomicNumber: 6
  atomicWeight: 0.012011000
  electronegativity: 2.55

- name: Oxygen
  symbol: O
  atomicNumber: 8
  atomicWeight: 0.015999400
  electronegativity: 3.44
)";

std::string substances = R"(
- name: H2O(aq)
  formula: H2O
  tags: [ aqueous ]

- name: Na+(aq)
  formula: Na+
  tags: [ aqueous ]

- name: Cl-(aq)
  formula: Cl-
  tags: [ aqueous ]

- name: H2O(g)
  formula: H2O
  tags: [ gaseous ]

- name: CO2(g)
  formula: CO2
  tags: [ gaseous ]
)";

} // namespace strings


TEST_CASE("Testing YAML", "[YAML]")
{
    Element element = yaml(strings::element);

    CHECK( element.symbol() == "H" );
    CHECK( element.name() == "Hydrogen" );
    CHECK( element.atomicNumber() == 1 );
    CHECK( element.atomicWeight() == 0.001007940 );
    CHECK( element.electronegativity() == 2.20 );
    CHECK( element.tags().size() == 1 );
    CHECK( element.tags().at(0) == "group1" );

    Substance substance = yaml(strings::substance);

    CHECK( substance.formula().str() == "CaCO3" );
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
    CHECK( substances[0].formula() == "H2O" );
    CHECK( substances[0].tags().size() == 1 );
    CHECK( substances[0].tags().at(0) == "aqueous" );

    CHECK( substances[1].name() == "Na+(aq)" );
    CHECK( substances[1].formula() == "Na+" );
    CHECK( substances[1].tags().size() == 1 );
    CHECK( substances[1].tags().at(0) == "aqueous" );

    CHECK( substances[2].name() == "Cl-(aq)" );
    CHECK( substances[2].formula() == "Cl-" );
    CHECK( substances[2].tags().size() == 1 );
    CHECK( substances[2].tags().at(0) == "aqueous" );

    CHECK( substances[3].name() == "H2O(g)" );
    CHECK( substances[3].formula() == "H2O" );
    CHECK( substances[3].tags().size() == 1 );
    CHECK( substances[3].tags().at(0) == "gaseous" );

    CHECK( substances[4].name() == "CO2(g)" );
    CHECK( substances[4].formula() == "CO2" );
    CHECK( substances[4].tags().size() == 1 );
    CHECK( substances[4].tags().at(0) == "gaseous" );
}
