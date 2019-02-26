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
#include <catch2/catch.hpp>

// Atomik includes
#include <Atomik/Substances.hpp>
#include <Atomik/StringList.hpp>
using namespace Atomik;

TEST_CASE("Testing Substances", "[Substances]")
{
    Substances substances;
    Substances filtered;

    // Test custom-create chemical substances
    substances = Substances({
        Substance({ "H2O"   , "H2O(aq)"   , "aqueous" , { "solvent"} }),
        Substance({ "H+"    , "H+(aq)"    , "aqueous" , { "charged", "cation"} }),
        Substance({ "OH-"   , "OH-(aq)"   , "aqueous" , { "charged", "anion"} }),
        Substance({ "HCO3-" , "HCO3-(aq)" , "aqueous" , { "charged", "anion"} }),
        Substance({ "CO3-2" , "CO3-2(aq)" , "aqueous" , { "charged", "anion"} }),
        Substance({ "CO2"   , "CO2(aq)"   , "aqueous" , { "neutral"} }),
        Substance({ "CO2"   , "CO2(g)"    , "gaseous" }),
        Substance({ "H2O"   , "H2O(g)"    , "gaseous" })
    });

    REQUIRE(substances.size() == 8);

    // Test method Substances::indexWithName
    REQUIRE( substances.indexWithName("H2O(aq)")   == 0);
    REQUIRE( substances.indexWithName("H+(aq)")    == 1);
    REQUIRE( substances.indexWithName("OH-(aq)")   == 2);
    REQUIRE( substances.indexWithName("HCO3-(aq)") == 3);
    REQUIRE( substances.indexWithName("CO3-2(aq)") == 4);
    REQUIRE( substances.indexWithName("CO2(aq)")   == 5);
    REQUIRE( substances.indexWithName("CO2(g)")    == 6);
    REQUIRE( substances.indexWithName("H2O(g)")    == 7);

    // Test method Substances::indexWithFormula
    REQUIRE( substances.indexWithFormula("H2O")   == 0 );
    REQUIRE( substances.indexWithFormula("H+")    == 1 );
    REQUIRE( substances.indexWithFormula("OH-")   == 2 );
    REQUIRE( substances.indexWithFormula("HCO3-") == 3 );
    REQUIRE( substances.indexWithFormula("CO3-2") == 4 );
    REQUIRE( substances.indexWithFormula("CO2")   == 5 );

    // Test method Substances::withNames
    filtered = substances.withNames("H+(aq) OH-(aq) H2O(aq)");

    REQUIRE( filtered[0].name() == substances.getWithName("H+(aq)").name()  );
    REQUIRE( filtered[1].name() == substances.getWithName("OH-(aq)").name() );
    REQUIRE( filtered[2].name() == substances.getWithName("H2O(aq)").name() );

    // Test method Substances::withFormulas
    filtered = substances.withFormulas("CO2 HCO3- CO3--");

    REQUIRE( filtered[0] == substances.getWithName("CO2(aq)") );
    REQUIRE( filtered[1] == substances.getWithName("HCO3-(aq)")  );
    REQUIRE( filtered[2] == substances.getWithName("CO3-2(aq)") );

    // Test method Substances::withType
    filtered = substances.withType("aqueous");

    REQUIRE( filtered.size() == 6 );
    REQUIRE( filtered[0] == substances.getWithName("H2O(aq)") );
    REQUIRE( filtered[1] == substances.getWithName("H+(aq)") );
    REQUIRE( filtered[2] == substances.getWithName("OH-(aq)") );
    REQUIRE( filtered[3] == substances.getWithName("HCO3-(aq)") );
    REQUIRE( filtered[4] == substances.getWithName("CO3-2(aq)") );
    REQUIRE( filtered[5] == substances.getWithName("CO2(aq)") );

    filtered = substances.withType("gaseous");

    REQUIRE( filtered.size() == 2 );
    REQUIRE( filtered[0] == substances.getWithName("CO2(g)"));
    REQUIRE( filtered[1] == substances.getWithName("H2O(g)"));

    // Test method Substances::withTag/withTags
    filtered = substances.withTag("charged");

    REQUIRE( filtered.size() == 4 );
    REQUIRE( filtered[0] == substances.getWithName("H+(aq)")    );
    REQUIRE( filtered[1] == substances.getWithName("OH-(aq)")   );
    REQUIRE( filtered[2] == substances.getWithName("HCO3-(aq)") );
    REQUIRE( filtered[3] == substances.getWithName("CO3-2(aq)") );

    filtered = substances.withTags({"cation", "charged"});

    REQUIRE( filtered.size() == 1 );
    REQUIRE( filtered[0] == substances.getWithName("H+(aq)") );

    filtered = substances.withTags({"anion", "charged"});

    REQUIRE( filtered.size() == 3 );
    REQUIRE( filtered[0] == substances.getWithName("OH-(aq)")   );
    REQUIRE( filtered[1] == substances.getWithName("HCO3-(aq)") );
    REQUIRE( filtered[2] == substances.getWithName("CO3-2(aq)") );

    // Test method Substances::append
    substances.append(Substance("CaCO3").replaceName("CaCO3(calcite)"));

    REQUIRE_NOTHROW(substances.getWithName("CaCO3(calcite)"));
    REQUIRE_NOTHROW(substances.getWithFormula("CaCO3"));
}
