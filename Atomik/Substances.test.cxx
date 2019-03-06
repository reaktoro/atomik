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
#include <Atomik/Substances.hpp>
#include <Atomik/StringList.hpp>
using namespace Atomik;

TEST_CASE("Testing Substances", "[Substances]")
{
    Substances substances;
    Substances filtered;

    // Test constructor Substances(formulas)
    substances = Substances("H2O H+ OH- H2 O2 Na+ Cl- NaCl CO2 HCO3- CO3-2 CH4");

    REQUIRE( substances.size() == 12 );

    REQUIRE( substances[0].name()  == "H2O"   );
    REQUIRE( substances[1].name()  == "H+"    );
    REQUIRE( substances[2].name()  == "OH-"   );
    REQUIRE( substances[3].name()  == "H2"    );
    REQUIRE( substances[4].name()  == "O2"    );
    REQUIRE( substances[5].name()  == "Na+"   );
    REQUIRE( substances[6].name()  == "Cl-"   );
    REQUIRE( substances[7].name()  == "NaCl"  );
    REQUIRE( substances[8].name()  == "CO2"   );
    REQUIRE( substances[9].name()  == "HCO3-" );
    REQUIRE( substances[10].name() == "CO3-2" );
    REQUIRE( substances[11].name() == "CH4"   );

    // Test constructor Substances(vector<Substance>)
    substances = Substances({
        Substance({ "H2O"  , "H2O(aq)"  , { "aqueous", "neutral", "solvent" } }),
        Substance({ "H+"   , "H+(aq)"   , { "aqueous", "charged", "cation"}   }),
        Substance({ "OH-"  , "OH-(aq)"  , { "aqueous", "charged", "anion" }   }),
        Substance({ "H2"   , "H2(aq)"   , { "aqueous", "neutral" }            }),
        Substance({ "O2"   , "O2(aq)"   , { "aqueous", "neutral" }            }),
        Substance({ "Na+"  , "Na+(aq)"  , { "aqueous", "charged", "cation"}   }),
        Substance({ "Cl-"  , "Cl-(aq)"  , { "aqueous", "charged", "anion" }   }),
        Substance({ "NaCl" , "NaCl(aq)" , { "aqueous", "neutral" }            }),
        Substance({ "CO2"  , "CO2(aq)"  , { "aqueous", "neutral" }            }),
        Substance({ "HCO3-", "HCO3-(aq)", { "aqueous", "charged", "anion" }   }),
        Substance({ "CO3-2", "CO3-2(aq)", { "aqueous", "charged", "anion" }   }),
        Substance({ "CH4"  , "CH4(aq)"  , { "aqueous", "neutral" }            }),
        Substance({ "H2O"  , "H2O(g)"   , { "gaseous" }                       }),
        Substance({ "CO2"  , "CO2(g)"   , { "gaseous" }                       }),
        Substance({ "CH4"  , "CH4(g)"   , { "gaseous" }                       }),
    });

    REQUIRE(substances.size() == 15);

    // Test method Substances::indexWithName
    REQUIRE( substances.indexWithName("H2O(aq)")   == 0);
    REQUIRE( substances.indexWithName("H+(aq)")    == 1);
    REQUIRE( substances.indexWithName("OH-(aq)")   == 2);
    REQUIRE( substances.indexWithName("H2(aq)")    == 3);
    REQUIRE( substances.indexWithName("O2(aq)")    == 4);
    REQUIRE( substances.indexWithName("Na+(aq)")   == 5);
    REQUIRE( substances.indexWithName("Cl-(aq)")   == 6);
    REQUIRE( substances.indexWithName("NaCl(aq)")  == 7);
    REQUIRE( substances.indexWithName("CO2(aq)")   == 8);
    REQUIRE( substances.indexWithName("HCO3-(aq)") == 9);
    REQUIRE( substances.indexWithName("CO3-2(aq)") == 10);
    REQUIRE( substances.indexWithName("CH4(aq)")   == 11);
    REQUIRE( substances.indexWithName("H2O(g)")    == 12);
    REQUIRE( substances.indexWithName("CO2(g)")    == 13);
    REQUIRE( substances.indexWithName("CH4(g)")    == 14);

    // Test method Substances::indexWithFormula
    REQUIRE( substances.indexWithFormula("H2O")   == 0);
    REQUIRE( substances.indexWithFormula("H+")    == 1);
    REQUIRE( substances.indexWithFormula("OH-")   == 2);
    REQUIRE( substances.indexWithFormula("H2")    == 3);
    REQUIRE( substances.indexWithFormula("O2")    == 4);
    REQUIRE( substances.indexWithFormula("Na+")   == 5);
    REQUIRE( substances.indexWithFormula("Cl-")   == 6);
    REQUIRE( substances.indexWithFormula("NaCl")  == 7);
    REQUIRE( substances.indexWithFormula("CO2")   == 8);
    REQUIRE( substances.indexWithFormula("HCO3-") == 9);
    REQUIRE( substances.indexWithFormula("CO3-2") == 10);
    REQUIRE( substances.indexWithFormula("CH4")   == 11);

    // Test method Substances::withNames
    filtered = substances.withNames("H+(aq) OH-(aq) H2O(aq)");

    REQUIRE( filtered[0].name() == substances.getWithName("H+(aq)").name()  );
    REQUIRE( filtered[1].name() == substances.getWithName("OH-(aq)").name() );
    REQUIRE( filtered[2].name() == substances.getWithName("H2O(aq)").name() );

    // Test method Substances::withFormulas
    filtered = substances.withFormulas("CO2 HCO3- CO3-2");

    REQUIRE( filtered[0] == substances.getWithName("CO2(aq)") );
    REQUIRE( filtered[1] == substances.getWithName("HCO3-(aq)")  );
    REQUIRE( filtered[2] == substances.getWithName("CO3-2(aq)") );

    // Test method Substances::withTag
    filtered = substances.withTag("charged");

    REQUIRE( filtered.size() == 6 );
    REQUIRE( filtered[0] == substances.getWithName("H+(aq)")    );
    REQUIRE( filtered[1] == substances.getWithName("OH-(aq)")   );
    REQUIRE( filtered[2] == substances.getWithName("Na+(aq)") );
    REQUIRE( filtered[3] == substances.getWithName("Cl-(aq)") );
    REQUIRE( filtered[4] == substances.getWithName("HCO3-(aq)") );
    REQUIRE( filtered[5] == substances.getWithName("CO3-2(aq)") );

    // Test method Substances::withTags
    filtered = substances.withTags({"cation", "charged"});

    REQUIRE( filtered.size() == 2 );
    REQUIRE( filtered[0] == substances.getWithName("H+(aq)") );
    REQUIRE( filtered[1] == substances.getWithName("Na+(aq)") );

    // Test method Substances::withTags
    filtered = substances.withTags({"anion", "charged"});

    REQUIRE( filtered.size() == 4 );
    REQUIRE( filtered[0] == substances.getWithName("OH-(aq)")   );
    REQUIRE( filtered[1] == substances.getWithName("Cl-(aq)")   );
    REQUIRE( filtered[2] == substances.getWithName("HCO3-(aq)") );
    REQUIRE( filtered[3] == substances.getWithName("CO3-2(aq)") );

    // Test method Substances::tagged (alias of Substances::withTag)
    filtered = substances.tagged("aqueous");

    REQUIRE( filtered.size() == 12 );
    REQUIRE( filtered[0]  == substances.getWithName("H2O(aq)") );
    REQUIRE( filtered[1]  == substances.getWithName("H+(aq)") );
    REQUIRE( filtered[2]  == substances.getWithName("OH-(aq)") );
    REQUIRE( filtered[3]  == substances.getWithName("H2(aq)") );
    REQUIRE( filtered[4]  == substances.getWithName("O2(aq)") );
    REQUIRE( filtered[5]  == substances.getWithName("Na+(aq)") );
    REQUIRE( filtered[6]  == substances.getWithName("Cl-(aq)") );
    REQUIRE( filtered[7]  == substances.getWithName("NaCl(aq)") );
    REQUIRE( filtered[8]  == substances.getWithName("CO2(aq)") );
    REQUIRE( filtered[9]  == substances.getWithName("HCO3-(aq)") );
    REQUIRE( filtered[10] == substances.getWithName("CO3-2(aq)") );
    REQUIRE( filtered[11] == substances.getWithName("CH4(aq)") );

    // Test method Substances::untagged (alias of Substances::withoutTag)
    filtered = substances.untagged("aqueous");

    REQUIRE( filtered.size() == 3 );
    REQUIRE( filtered[0] == substances.getWithName("H2O(g)"));
    REQUIRE( filtered[1] == substances.getWithName("CO2(g)"));
    REQUIRE( filtered[2] == substances.getWithName("CH4(g)"));

    // Test method Substances::withElements
    filtered = substances.withElements("H O");

    REQUIRE( filtered.size() == 4 );
    REQUIRE( filtered[0].name() == substances.getWithName("H2O(aq)").name() );
    REQUIRE( filtered[1].name() == substances.getWithName("H2(aq)").name() );
    REQUIRE( filtered[2].name() == substances.getWithName("O2(aq)").name() );
    REQUIRE( filtered[3].name() == substances.getWithName("H2O(g)").name() );

    // Test method Substances::withElements
    filtered = substances.containing("H O Z");

    REQUIRE( filtered.size() == 6 );
    REQUIRE( filtered[0] == substances.getWithName("H2O(aq)") );
    REQUIRE( filtered[1] == substances.getWithName("H+(aq)") );
    REQUIRE( filtered[2] == substances.getWithName("OH-(aq)") );
    REQUIRE( filtered[3] == substances.getWithName("H2(aq)") );
    REQUIRE( filtered[4] == substances.getWithName("O2(aq)") );
    REQUIRE( filtered[5] == substances.getWithName("H2O(g)") );

    // Test method Substances::containing (alias of Substances::withElements)
    filtered = substances.withElements("H O C Z");

    REQUIRE( filtered.size() == 12 );
    REQUIRE( filtered[0]  == substances.getWithName("H2O(aq)")   );
    REQUIRE( filtered[1]  == substances.getWithName("H+(aq)")    );
    REQUIRE( filtered[2]  == substances.getWithName("OH-(aq)")   );
    REQUIRE( filtered[3]  == substances.getWithName("H2(aq)")    );
    REQUIRE( filtered[4]  == substances.getWithName("O2(aq)")    );
    REQUIRE( filtered[5]  == substances.getWithName("CO2(aq)")   );
    REQUIRE( filtered[6]  == substances.getWithName("HCO3-(aq)") );
    REQUIRE( filtered[7]  == substances.getWithName("CO3-2(aq)") );
    REQUIRE( filtered[8]  == substances.getWithName("CH4(aq)")   );
    REQUIRE( filtered[9]  == substances.getWithName("H2O(g)")    );
    REQUIRE( filtered[10] == substances.getWithName("CO2(g)")    );
    REQUIRE( filtered[11] == substances.getWithName("CH4(g)")    );

    REQUIRE( substances.withElements("").size() == 0);
    REQUIRE( substances.withElements("Aa Bb Cc Dd Ee").size() == 0 );
    REQUIRE( substances.withElements("H O Aa Bb Cc Dd Ee").size() == 4 ); // { H2O(aq), H2(aq), O2(aq), H2O(g) }

    // Test method Substances::withElementsOf
    filtered = substances.withElementsOf("H2O NaCl");

    REQUIRE( filtered.size() == 5 );
    REQUIRE( filtered[0] == substances.getWithName("H2O(aq)")   );
    REQUIRE( filtered[1] == substances.getWithName("H2(aq)")    );
    REQUIRE( filtered[2] == substances.getWithName("O2(aq)")    );
    REQUIRE( filtered[3] == substances.getWithName("NaCl(aq)")  );
    REQUIRE( filtered[4] == substances.getWithName("H2O(g)")    );

    filtered = substances.withElementsOf("H2O Na+ Cl-");

    REQUIRE( filtered.size() == 9 );
    REQUIRE( filtered[0] == substances.getWithName("H2O(aq)")   );
    REQUIRE( filtered[1] == substances.getWithName("H+(aq)")    );
    REQUIRE( filtered[2] == substances.getWithName("OH-(aq)")   );
    REQUIRE( filtered[3] == substances.getWithName("H2(aq)")    );
    REQUIRE( filtered[4] == substances.getWithName("O2(aq)")    );
    REQUIRE( filtered[5] == substances.getWithName("Na+(aq)")   );
    REQUIRE( filtered[6] == substances.getWithName("Cl-(aq)")   );
    REQUIRE( filtered[7] == substances.getWithName("NaCl(aq)")  );
    REQUIRE( filtered[8] == substances.getWithName("H2O(g)")    );

    filtered = substances.withElementsOf("HOCNaClZ");

    REQUIRE( filtered.size() == substances.size() );
    REQUIRE( filtered[0]  == substances.getWithName("H2O(aq)")   );
    REQUIRE( filtered[1]  == substances.getWithName("H+(aq)")    );
    REQUIRE( filtered[2]  == substances.getWithName("OH-(aq)")   );
    REQUIRE( filtered[3]  == substances.getWithName("H2(aq)")    );
    REQUIRE( filtered[4]  == substances.getWithName("O2(aq)")    );
    REQUIRE( filtered[5]  == substances.getWithName("Na+(aq)")   );
    REQUIRE( filtered[6]  == substances.getWithName("Cl-(aq)")   );
    REQUIRE( filtered[7]  == substances.getWithName("NaCl(aq)")  );
    REQUIRE( filtered[8]  == substances.getWithName("CO2(aq)")   );
    REQUIRE( filtered[9]  == substances.getWithName("HCO3-(aq)") );
    REQUIRE( filtered[10] == substances.getWithName("CO3-2(aq)") );
    REQUIRE( filtered[11] == substances.getWithName("CH4(aq)")   );
    REQUIRE( filtered[12] == substances.getWithName("H2O(g)")    );
    REQUIRE( filtered[13] == substances.getWithName("CO2(g)")    );
    REQUIRE( filtered[14] == substances.getWithName("CH4(g)")    );

    // Test method Substances::append
    substances.append(Substance("CaCO3").replaceName("CaCO3(calcite)"));

    REQUIRE_NOTHROW(substances.getWithName("CaCO3(calcite)"));
    REQUIRE_NOTHROW(substances.getWithFormula("CaCO3"));
}
