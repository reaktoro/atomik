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
#include <Atomik/Elements.hpp>
#include <Atomik/StringList.hpp>
using namespace Atomik;

TEST_CASE("Testing Elements", "[Elements]")
{
    Elements elements;

    // Test custom-create chemical elements
    elements = Elements({
        Element({"H", "Hydrogen"}),
        Element({"Na", "Sodium"} )
    });

    REQUIRE(elements.size() == elements.data().size());

    REQUIRE(elements.index("H") < elements.size());
    REQUIRE(elements.index("H") == elements.indexWithSymbol("H"));
    REQUIRE(elements.index("H") == elements.indexWithName("Hydrogen"));

    REQUIRE(elements.index("Na") < elements.size());
    REQUIRE(elements.index("Na") == elements.indexWithSymbol("Na"));
    REQUIRE(elements.index("Na") == elements.indexWithName("Sodium"));

    REQUIRE_NOTHROW(elements.get("H"));
    REQUIRE_NOTHROW(elements.get("Na"));

    REQUIRE_THROWS(elements.get("Ab"));
    REQUIRE_THROWS(elements.get("Xy"));

    // Test the chemical elements from periodic table
    elements = Elements::PeriodicTable();

    REQUIRE(elements.size() == 119);
    REQUIRE(elements.get("Z").name() == "Charge");
    REQUIRE(elements.get("H").name() == "Hydrogen");
    REQUIRE(elements.get("He").name() == "Helium");
    REQUIRE(elements.get("Li").name() == "Lithium");
    REQUIRE(elements.get("Be").name() == "Beryllium");
    REQUIRE(elements.get("B").name() == "Boron");
    REQUIRE(elements.get("C").name() == "Carbon");
    REQUIRE(elements.get("N").name() == "Nitrogen");
    REQUIRE(elements.get("O").name() == "Oxygen");
    REQUIRE(elements.get("F").name() == "Fluorine");
    REQUIRE(elements.get("Ne").name() == "Neon");
    REQUIRE(elements.get("Na").name() == "Sodium");
    REQUIRE(elements.get("Mg").name() == "Magnesium");
    REQUIRE(elements.get("Al").name() == "Aluminum");
    REQUIRE(elements.get("Si").name() == "Silicon");
    REQUIRE(elements.get("P").name() == "Phosphorus");
    REQUIRE(elements.get("S").name() == "Sulfur");
    REQUIRE(elements.get("Cl").name() == "Chlorine");
    REQUIRE(elements.get("Ar").name() == "Argon");
    REQUIRE(elements.get("K").name() == "Potassium");
    REQUIRE(elements.get("Ca").name() == "Calcium");
    REQUIRE(elements.get("Sc").name() == "Scandium");
    REQUIRE(elements.get("Ti").name() == "Titanium");
    REQUIRE(elements.get("V").name() == "Vanadium");
    REQUIRE(elements.get("Cr").name() == "Chromium");
    REQUIRE(elements.get("Mn").name() == "Manganese");
    REQUIRE(elements.get("Fe").name() == "Iron");
    REQUIRE(elements.get("Co").name() == "Cobalt");
    REQUIRE(elements.get("Ni").name() == "Nickel");
    REQUIRE(elements.get("Cu").name() == "Copper");
    REQUIRE(elements.get("Zn").name() == "Zinc");
    REQUIRE(elements.get("Ga").name() == "Gallium");
    REQUIRE(elements.get("Ge").name() == "Germanium");
    REQUIRE(elements.get("As").name() == "Arsenic");
    REQUIRE(elements.get("Se").name() == "Selenium");
    REQUIRE(elements.get("Br").name() == "Bromine");
    REQUIRE(elements.get("Kr").name() == "Krypton");
    REQUIRE(elements.get("Rb").name() == "Rubidium");
    REQUIRE(elements.get("Sr").name() == "Strontium");
    REQUIRE(elements.get("Y").name() == "Yttrium");
    REQUIRE(elements.get("Zr").name() == "Zirconium");
    REQUIRE(elements.get("Nb").name() == "Niobium");
    REQUIRE(elements.get("Mo").name() == "Molybdenum");
    REQUIRE(elements.get("Tc").name() == "Technetium");
    REQUIRE(elements.get("Ru").name() == "Ruthenium");
    REQUIRE(elements.get("Rh").name() == "Rhodium");
    REQUIRE(elements.get("Pd").name() == "Palladium");
    REQUIRE(elements.get("Ag").name() == "Silver");
    REQUIRE(elements.get("Cd").name() == "Cadmium");
    REQUIRE(elements.get("In").name() == "Indium");
    REQUIRE(elements.get("Sn").name() == "Tin");
    REQUIRE(elements.get("Sb").name() == "Antimony");
    REQUIRE(elements.get("Te").name() == "Tellurium");
    REQUIRE(elements.get("I").name() == "Iodine");
    REQUIRE(elements.get("Xe").name() == "Xenon");
    REQUIRE(elements.get("Cs").name() == "Cesium");
    REQUIRE(elements.get("Ba").name() == "Barium");
    REQUIRE(elements.get("La").name() == "Lanthanum");
    REQUIRE(elements.get("Ce").name() == "Cerium");
    REQUIRE(elements.get("Pr").name() == "Praseodymium");
    REQUIRE(elements.get("Nd").name() == "Neodymium");
    REQUIRE(elements.get("Pm").name() == "Promethium");
    REQUIRE(elements.get("Sm").name() == "Samarium");
    REQUIRE(elements.get("Eu").name() == "Europium");
    REQUIRE(elements.get("Gd").name() == "Gadolinium");
    REQUIRE(elements.get("Tb").name() == "Terbium");
    REQUIRE(elements.get("Dy").name() == "Dysprosium");
    REQUIRE(elements.get("Ho").name() == "Holmium");
    REQUIRE(elements.get("Er").name() == "Erbium");
    REQUIRE(elements.get("Tm").name() == "Thulium");
    REQUIRE(elements.get("Yb").name() == "Ytterbium");
    REQUIRE(elements.get("Lu").name() == "Lutetium");
    REQUIRE(elements.get("Hf").name() == "Hafnium");
    REQUIRE(elements.get("Ta").name() == "Tantalum");
    REQUIRE(elements.get("W").name() == "Tungsten");
    REQUIRE(elements.get("Re").name() == "Rhenium");
    REQUIRE(elements.get("Os").name() == "Osmium");
    REQUIRE(elements.get("Ir").name() == "Iridium");
    REQUIRE(elements.get("Pt").name() == "Platinum");
    REQUIRE(elements.get("Au").name() == "Gold");
    REQUIRE(elements.get("Hg").name() == "Mercury");
    REQUIRE(elements.get("Tl").name() == "Thallium");
    REQUIRE(elements.get("Pb").name() == "Lead");
    REQUIRE(elements.get("Bi").name() == "Bismuth");
    REQUIRE(elements.get("Po").name() == "Polonium");
    REQUIRE(elements.get("At").name() == "Astatine");
    REQUIRE(elements.get("Rn").name() == "Radon");
    REQUIRE(elements.get("Fr").name() == "Francium");
    REQUIRE(elements.get("Ra").name() == "Radium");
    REQUIRE(elements.get("Ac").name() == "Actinium");
    REQUIRE(elements.get("Th").name() == "Thorium");
    REQUIRE(elements.get("Pa").name() == "Protactinium");
    REQUIRE(elements.get("U").name() == "Uranium");
    REQUIRE(elements.get("Np").name() == "Neptunium");
    REQUIRE(elements.get("Pu").name() == "Plutonium");
    REQUIRE(elements.get("Am").name() == "Americium");
    REQUIRE(elements.get("Cm").name() == "Curium");
    REQUIRE(elements.get("Bk").name() == "Berkelium");
    REQUIRE(elements.get("Cf").name() == "Californium");
    REQUIRE(elements.get("Es").name() == "Einsteinium");
    REQUIRE(elements.get("Fm").name() == "Fermium");
    REQUIRE(elements.get("Md").name() == "Mendelevium");
    REQUIRE(elements.get("No").name() == "Nobelium");
    REQUIRE(elements.get("Lr").name() == "Lawrencium");
    REQUIRE(elements.get("Rf").name() == "Rutherfordium");
    REQUIRE(elements.get("Db").name() == "Dubnium");
    REQUIRE(elements.get("Sg").name() == "Seaborgium");
    REQUIRE(elements.get("Bh").name() == "Bohrium");
    REQUIRE(elements.get("Hs").name() == "Hassium");
    REQUIRE(elements.get("Mt").name() == "Meitnerium");
    REQUIRE(elements.get("Ds").name() == "Darmstadtium");
    REQUIRE(elements.get("Rg").name() == "Roentgenium");
    REQUIRE(elements.get("Cn").name() == "Copernicium");
    REQUIRE(elements.get("Nh").name() == "Nihonium");
    REQUIRE(elements.get("Fl").name() == "Flerovium");
    REQUIRE(elements.get("Mc").name() == "Moscovium");
    REQUIRE(elements.get("Lv").name() == "Livermorium");
    REQUIRE(elements.get("Ts").name() == "Tennessine");
    REQUIRE(elements.get("Og").name() == "Oganesson");

    // Test the filtering methods
    Elements filtered;

    filtered = elements.withSymbols("H O Na Cl");

    REQUIRE(filtered.size() == 4);
    REQUIRE(filtered.index("H") == 0);
    REQUIRE(filtered.index("O") == 1);
    REQUIRE(filtered.index("Na") == 2);
    REQUIRE(filtered.index("Cl") == 3);

    filtered = elements.withNames("Hydrogen Oxygen Sodium Chlorine");

    REQUIRE(filtered.size() == 4);
    REQUIRE(filtered.index("H") == 0);
    REQUIRE(filtered.index("O") == 1);
    REQUIRE(filtered.index("Na") == 2);
    REQUIRE(filtered.index("Cl") == 3);

    elements = Elements({
        Element()
            .withSymbol("Aa")
            .withTags({"tag1", "tag2", "tag3"}),
        Element()
            .withSymbol("Bb")
            .withTags({"tag1", "tag3"}),
        Element()
            .withSymbol("Cc")
            .withTags({"tag1"})
    });

    filtered = elements.withTag("tag1");

    REQUIRE(filtered.size() == 3);
    REQUIRE(filtered[0].symbol() == "Aa");
    REQUIRE(filtered[1].symbol() == "Bb");
    REQUIRE(filtered[2].symbol() == "Cc");

    filtered = elements.withTags({"tag3", "tag1"});

    REQUIRE(filtered.size() == 2);
    REQUIRE(filtered[0].symbol() == "Aa");
    REQUIRE(filtered[1].symbol() == "Bb");
}
