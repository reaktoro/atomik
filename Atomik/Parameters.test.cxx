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
#include <Atomik/Parameters.hpp>
using namespace Atomik;

TEST_CASE("Testing ParamValue class", "[ParamValue]")
{
    ParamValue param;

    // Testing ParamValue(double) constructor
    param = ParamValue(1.0);

    REQUIRE( param == 1.0 );
    REQUIRE( param.value() == 1.0 );

    // Testing operator=(double)
    param = 1.0;

    REQUIRE( param == 1.0 );
    REQUIRE( param.value() == 1.0 );

    REQUIRE_THROWS( param.values() );

    // Testing ParamValue(vector<double>) constructor
    param = ParamValue({1.0, 2.0, 3.0});

    REQUIRE( param.values().size() == 3 );
    REQUIRE( param.values()[0] == 1.0 );
    REQUIRE( param.values()[1] == 2.0 );
    REQUIRE( param.values()[2] == 3.0 );

    // Testing operator=(vector<double>)
    param = {1.0, 2.0, 3.0};

    REQUIRE( param.values().size() == 3 );
    REQUIRE( param.values()[0] == 1.0 );
    REQUIRE( param.values()[1] == 2.0 );
    REQUIRE( param.values()[2] == 3.0 );

    REQUIRE_THROWS( param.value() );
}

TEST_CASE("Testing Parameters class", "[Parameters]")
{
    Parameters parameters;

    parameters.set("a") = 1.0;
    REQUIRE( parameters.get("a") == 1.0 );

    parameters.set("a", "b") = 2.0;
    REQUIRE( parameters.get("a", "b") == 2.0 );
    REQUIRE( parameters.get("a.b") == 2.0 );

    parameters.set("a", "c") = 2.0;
    REQUIRE( parameters.get("a", "b") == 2.0 );
    REQUIRE( parameters.get("a.b") == 2.0 );

    parameters.set("a", "b", "c") = { 1.0, 2.0, 3.0 };
    REQUIRE( parameters.get("a.b.c").size() == 3 );
    REQUIRE( parameters.get("a.b.c")[0] == 1.0 );
    REQUIRE( parameters.get("a.b.c")[1] == 2.0 );
    REQUIRE( parameters.get("a.b.c")[2] == 3.0 );
}
