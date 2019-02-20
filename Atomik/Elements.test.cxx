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

// Atomik includes
#include <Atomik/Elements.hpp>
using namespace Atomik;

TEST_CASE("Testing Elements", "[Elements]")
{
    Elements elements;

    auto initialsize = elements.size();

    SECTION("After filtering a few elements")
    {
        elements = elements.filter("Na");

        CHECK(elements.size() == 1);
        CHECK_FALSE(elements("Na").empty());
    }

    SECTION("After removing a few elements")
    {
        elements = elements.remove("Na").remove("Cl");

        CHECK(elements.size() == initialsize - 2);
        CHECK(elements("Na").empty());
        CHECK(elements("Cl").empty());
    }
}
