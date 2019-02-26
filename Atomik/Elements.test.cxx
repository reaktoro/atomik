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

    REQUIRE(elements.indexWithSymbol("H") < elements.size());
    REQUIRE(elements.indexWithSymbol("H") == elements.indexWithName("Hydrogen"));

    REQUIRE(elements.indexWithSymbol("Na") < elements.size());
    REQUIRE(elements.indexWithSymbol("Na") == elements.indexWithName("Sodium"));

    REQUIRE_NOTHROW(elements.getWithSymbol("H"));
    REQUIRE_NOTHROW(elements.getWithSymbol("Na"));

    REQUIRE_THROWS(elements.getWithSymbol("Ab"));
    REQUIRE_THROWS(elements.getWithSymbol("Xy"));

    // Test the chemical elements from periodic table
    elements = Elements::PeriodicTable();

    REQUIRE(elements.size() == 119);
    REQUIRE(elements.getWithSymbol("Z").name() == "Charge");
    REQUIRE(elements.getWithSymbol("H").name() == "Hydrogen");
    REQUIRE(elements.getWithSymbol("He").name() == "Helium");
    REQUIRE(elements.getWithSymbol("Li").name() == "Lithium");
    REQUIRE(elements.getWithSymbol("Be").name() == "Beryllium");
    REQUIRE(elements.getWithSymbol("B").name() == "Boron");
    REQUIRE(elements.getWithSymbol("C").name() == "Carbon");
    REQUIRE(elements.getWithSymbol("N").name() == "Nitrogen");
    REQUIRE(elements.getWithSymbol("O").name() == "Oxygen");
    REQUIRE(elements.getWithSymbol("F").name() == "Fluorine");
    REQUIRE(elements.getWithSymbol("Ne").name() == "Neon");
    REQUIRE(elements.getWithSymbol("Na").name() == "Sodium");
    REQUIRE(elements.getWithSymbol("Mg").name() == "Magnesium");
    REQUIRE(elements.getWithSymbol("Al").name() == "Aluminum");
    REQUIRE(elements.getWithSymbol("Si").name() == "Silicon");
    REQUIRE(elements.getWithSymbol("P").name() == "Phosphorus");
    REQUIRE(elements.getWithSymbol("S").name() == "Sulfur");
    REQUIRE(elements.getWithSymbol("Cl").name() == "Chlorine");
    REQUIRE(elements.getWithSymbol("Ar").name() == "Argon");
    REQUIRE(elements.getWithSymbol("K").name() == "Potassium");
    REQUIRE(elements.getWithSymbol("Ca").name() == "Calcium");
    REQUIRE(elements.getWithSymbol("Sc").name() == "Scandium");
    REQUIRE(elements.getWithSymbol("Ti").name() == "Titanium");
    REQUIRE(elements.getWithSymbol("V").name() == "Vanadium");
    REQUIRE(elements.getWithSymbol("Cr").name() == "Chromium");
    REQUIRE(elements.getWithSymbol("Mn").name() == "Manganese");
    REQUIRE(elements.getWithSymbol("Fe").name() == "Iron");
    REQUIRE(elements.getWithSymbol("Co").name() == "Cobalt");
    REQUIRE(elements.getWithSymbol("Ni").name() == "Nickel");
    REQUIRE(elements.getWithSymbol("Cu").name() == "Copper");
    REQUIRE(elements.getWithSymbol("Zn").name() == "Zinc");
    REQUIRE(elements.getWithSymbol("Ga").name() == "Gallium");
    REQUIRE(elements.getWithSymbol("Ge").name() == "Germanium");
    REQUIRE(elements.getWithSymbol("As").name() == "Arsenic");
    REQUIRE(elements.getWithSymbol("Se").name() == "Selenium");
    REQUIRE(elements.getWithSymbol("Br").name() == "Bromine");
    REQUIRE(elements.getWithSymbol("Kr").name() == "Krypton");
    REQUIRE(elements.getWithSymbol("Rb").name() == "Rubidium");
    REQUIRE(elements.getWithSymbol("Sr").name() == "Strontium");
    REQUIRE(elements.getWithSymbol("Y").name() == "Yttrium");
    REQUIRE(elements.getWithSymbol("Zr").name() == "Zirconium");
    REQUIRE(elements.getWithSymbol("Nb").name() == "Niobium");
    REQUIRE(elements.getWithSymbol("Mo").name() == "Molybdenum");
    REQUIRE(elements.getWithSymbol("Tc").name() == "Technetium");
    REQUIRE(elements.getWithSymbol("Ru").name() == "Ruthenium");
    REQUIRE(elements.getWithSymbol("Rh").name() == "Rhodium");
    REQUIRE(elements.getWithSymbol("Pd").name() == "Palladium");
    REQUIRE(elements.getWithSymbol("Ag").name() == "Silver");
    REQUIRE(elements.getWithSymbol("Cd").name() == "Cadmium");
    REQUIRE(elements.getWithSymbol("In").name() == "Indium");
    REQUIRE(elements.getWithSymbol("Sn").name() == "Tin");
    REQUIRE(elements.getWithSymbol("Sb").name() == "Antimony");
    REQUIRE(elements.getWithSymbol("Te").name() == "Tellurium");
    REQUIRE(elements.getWithSymbol("I").name() == "Iodine");
    REQUIRE(elements.getWithSymbol("Xe").name() == "Xenon");
    REQUIRE(elements.getWithSymbol("Cs").name() == "Cesium");
    REQUIRE(elements.getWithSymbol("Ba").name() == "Barium");
    REQUIRE(elements.getWithSymbol("La").name() == "Lanthanum");
    REQUIRE(elements.getWithSymbol("Ce").name() == "Cerium");
    REQUIRE(elements.getWithSymbol("Pr").name() == "Praseodymium");
    REQUIRE(elements.getWithSymbol("Nd").name() == "Neodymium");
    REQUIRE(elements.getWithSymbol("Pm").name() == "Promethium");
    REQUIRE(elements.getWithSymbol("Sm").name() == "Samarium");
    REQUIRE(elements.getWithSymbol("Eu").name() == "Europium");
    REQUIRE(elements.getWithSymbol("Gd").name() == "Gadolinium");
    REQUIRE(elements.getWithSymbol("Tb").name() == "Terbium");
    REQUIRE(elements.getWithSymbol("Dy").name() == "Dysprosium");
    REQUIRE(elements.getWithSymbol("Ho").name() == "Holmium");
    REQUIRE(elements.getWithSymbol("Er").name() == "Erbium");
    REQUIRE(elements.getWithSymbol("Tm").name() == "Thulium");
    REQUIRE(elements.getWithSymbol("Yb").name() == "Ytterbium");
    REQUIRE(elements.getWithSymbol("Lu").name() == "Lutetium");
    REQUIRE(elements.getWithSymbol("Hf").name() == "Hafnium");
    REQUIRE(elements.getWithSymbol("Ta").name() == "Tantalum");
    REQUIRE(elements.getWithSymbol("W").name() == "Tungsten");
    REQUIRE(elements.getWithSymbol("Re").name() == "Rhenium");
    REQUIRE(elements.getWithSymbol("Os").name() == "Osmium");
    REQUIRE(elements.getWithSymbol("Ir").name() == "Iridium");
    REQUIRE(elements.getWithSymbol("Pt").name() == "Platinum");
    REQUIRE(elements.getWithSymbol("Au").name() == "Gold");
    REQUIRE(elements.getWithSymbol("Hg").name() == "Mercury");
    REQUIRE(elements.getWithSymbol("Tl").name() == "Thallium");
    REQUIRE(elements.getWithSymbol("Pb").name() == "Lead");
    REQUIRE(elements.getWithSymbol("Bi").name() == "Bismuth");
    REQUIRE(elements.getWithSymbol("Po").name() == "Polonium");
    REQUIRE(elements.getWithSymbol("At").name() == "Astatine");
    REQUIRE(elements.getWithSymbol("Rn").name() == "Radon");
    REQUIRE(elements.getWithSymbol("Fr").name() == "Francium");
    REQUIRE(elements.getWithSymbol("Ra").name() == "Radium");
    REQUIRE(elements.getWithSymbol("Ac").name() == "Actinium");
    REQUIRE(elements.getWithSymbol("Th").name() == "Thorium");
    REQUIRE(elements.getWithSymbol("Pa").name() == "Protactinium");
    REQUIRE(elements.getWithSymbol("U").name() == "Uranium");
    REQUIRE(elements.getWithSymbol("Np").name() == "Neptunium");
    REQUIRE(elements.getWithSymbol("Pu").name() == "Plutonium");
    REQUIRE(elements.getWithSymbol("Am").name() == "Americium");
    REQUIRE(elements.getWithSymbol("Cm").name() == "Curium");
    REQUIRE(elements.getWithSymbol("Bk").name() == "Berkelium");
    REQUIRE(elements.getWithSymbol("Cf").name() == "Californium");
    REQUIRE(elements.getWithSymbol("Es").name() == "Einsteinium");
    REQUIRE(elements.getWithSymbol("Fm").name() == "Fermium");
    REQUIRE(elements.getWithSymbol("Md").name() == "Mendelevium");
    REQUIRE(elements.getWithSymbol("No").name() == "Nobelium");
    REQUIRE(elements.getWithSymbol("Lr").name() == "Lawrencium");
    REQUIRE(elements.getWithSymbol("Rf").name() == "Rutherfordium");
    REQUIRE(elements.getWithSymbol("Db").name() == "Dubnium");
    REQUIRE(elements.getWithSymbol("Sg").name() == "Seaborgium");
    REQUIRE(elements.getWithSymbol("Bh").name() == "Bohrium");
    REQUIRE(elements.getWithSymbol("Hs").name() == "Hassium");
    REQUIRE(elements.getWithSymbol("Mt").name() == "Meitnerium");
    REQUIRE(elements.getWithSymbol("Ds").name() == "Darmstadtium");
    REQUIRE(elements.getWithSymbol("Rg").name() == "Roentgenium");
    REQUIRE(elements.getWithSymbol("Cn").name() == "Copernicium");
    REQUIRE(elements.getWithSymbol("Nh").name() == "Nihonium");
    REQUIRE(elements.getWithSymbol("Fl").name() == "Flerovium");
    REQUIRE(elements.getWithSymbol("Mc").name() == "Moscovium");
    REQUIRE(elements.getWithSymbol("Lv").name() == "Livermorium");
    REQUIRE(elements.getWithSymbol("Ts").name() == "Tennessine");
    REQUIRE(elements.getWithSymbol("Og").name() == "Oganesson");

    // Test the filtering methods
    Elements filtered;

    filtered = elements.withSymbols("H O Na Cl");

    REQUIRE(filtered.size() == 4);
    REQUIRE_NOTHROW(filtered.getWithSymbol("H"));
    REQUIRE_NOTHROW(filtered.getWithSymbol("O"));
    REQUIRE_NOTHROW(filtered.getWithSymbol("Na"));
    REQUIRE_NOTHROW(filtered.getWithSymbol("Cl"));

    filtered = elements.withNames("Hydrogen Oxygen Sodium Chlorine");

    REQUIRE(filtered.size() == 4);
    REQUIRE_NOTHROW(filtered.getWithSymbol("H"));
    REQUIRE_NOTHROW(filtered.getWithSymbol("O"));
    REQUIRE_NOTHROW(filtered.getWithSymbol("Na"));
    REQUIRE_NOTHROW(filtered.getWithSymbol("Cl"));

    elements = Elements({
        Element().replaceSymbol("Aa").replaceTags({"tag1", "tag2", "tag3"}),
        Element().replaceSymbol("Bb").replaceTags({"tag1", "tag3"}),
        Element().replaceSymbol("Cc").replaceTags({"tag1"})
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
