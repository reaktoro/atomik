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

    CHECK(elements.size() == elements.data().size());
    CHECK(elements.index("Na"));
    CHECK(elements.index("Na") == elements.indexWithSymbol("Na"));
    CHECK(elements.index("Na") == elements.indexWithName("Sodium"));
    CHECK_NOTHROW(elements("Na"));
    CHECK_THROWS(elements("Xyz"));
}
