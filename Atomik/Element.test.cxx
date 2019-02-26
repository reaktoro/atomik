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
#include <Atomik/Element.hpp>
using namespace Atomik;

TEST_CASE("Testing Element", "[Element]")
{
    Element element({
        .symbol = "H",
        .name = "Hydrogen",
        .atomicNumber = 1,
        .atomicWeight = 0.001007940,
        .electronegativity = 2.20,
        .tags = {"none"}
    });

    REQUIRE(element.symbol() == "H");
    REQUIRE(element.name() == "Hydrogen");
    REQUIRE(element.atomicNumber() == 1);
    REQUIRE(element.atomicWeight() == 0.001007940);
    REQUIRE(element.electronegativity() == 2.20);
    REQUIRE(element.tags().count("none"));
    REQUIRE(element.molarMass() == element.atomicWeight());

    element = element.replaceSymbol("Na");
    REQUIRE(element.symbol() == "Na");

    element = element.replaceName("Sodium");
    REQUIRE(element.name() == "Sodium");

    element = element.replaceAtomicNumber(11);
    REQUIRE(element.atomicNumber() == 11);

    element = element.replaceAtomicWeight(0.022989768);
    REQUIRE(element.atomicWeight() == 0.022989768);

    element = element.replaceElectronegativity(0.93);
    REQUIRE(element.electronegativity() == 0.93);

    element = element.replaceTags({"tag1", "tag2"});
    REQUIRE(element.tags().size() == 2);
    REQUIRE(element.tags().count("tag1"));
    REQUIRE(element.tags().count("tag2"));
}
