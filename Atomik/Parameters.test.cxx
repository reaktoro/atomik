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
#include <Atomik/Parameters.hpp>
using namespace Atomik;

TEST_CASE("Testing Parameters class", "[Parameters]")
{
    Parameters parameters;

    parameters = 1.0;

    REQUIRE( parameters.value() == 1.0 );

    parameters = {1, 2, 3};

    REQUIRE( parameters.values().size() == 3 );
    REQUIRE( parameters.values().at(0) == 1 );
    REQUIRE( parameters.values().at(1) == 2 );
    REQUIRE( parameters.values().at(2) == 3 );

    // parameters.insert("a").value() = 1.0;
    parameters.insert("a");
    parameters["a"] = 1.0;
    // parameters["a"];


    REQUIRE( parameters["a"] == 1.0 );


    parameters.insert("a").insert("b") = 3.0;

    REQUIRE( parameters["a"]["b"] == 3.0 );
}
