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
    // Parameters parameters;

    // // Testing Parameters::operator=(double)
    // REQUIRE_NOTHROW( parameters = 1.0 );

    // REQUIRE( parameters == 1.0 );
    // REQUIRE( parameters.value() == 1.0 );

    // // Testing Parameters::operator=(vector<double>)
    // REQUIRE_NOTHROW( parameters = {1, 2, 3} );

    // REQUIRE( parameters.values().size() == 3 );
    // REQUIRE( parameters.values().at(0) == 1 );
    // REQUIRE( parameters.values().at(1) == 2 );
    // REQUIRE( parameters.values().at(2) == 3 );

    // // Testing method Parameters::insert
    // REQUIRE_NOTHROW( parameters.insert("a").insert("b") );
    // REQUIRE_NOTHROW( parameters.insert("a").insert("d") );

    // REQUIRE_NOTHROW( parameters.get("a").get("b") = 5.0 );
    // REQUIRE_NOTHROW( parameters.get("a").get("d") = {3.0, 2.0, 1.0} );

    // REQUIRE( parameters.get("a").get("b") == 5.0 );
    // REQUIRE( parameters.get("a").get("d").values().at(0) == 3.0 );
    // REQUIRE( parameters.get("a").get("d").values().at(1) == 2.0 );
    // REQUIRE( parameters.get("a").get("d").values().at(2) == 1.0 );

    // REQUIRE( parameters["a"]["b"] == 5.0 );
    // REQUIRE( parameters["a"]["d"].values().at(0) == 3.0 );
    // REQUIRE( parameters["a"]["d"].values().at(1) == 2.0 );
    // REQUIRE( parameters["a"]["d"].values().at(2) == 1.0 );
}
