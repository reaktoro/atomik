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
#include <Atomik/Extract.hpp>
using namespace Atomik;

struct Foo
{
    auto name() const { return "foo"; }

    auto symbol() const { return "Xy"; }

    auto charge() const { return 1.0; }

    auto molarMass() const { return 14.0; }
};

TEST_CASE("Testing Extract", "[Extract]")
{
    std::vector<Foo> foos(5);

    auto names = Extract::names(foos);
    auto symbols = Extract::symbols(foos);
    auto charges = Extract::charges(foos);
    auto molarMasses = Extract::molarMasses(foos);

    REQUIRE(names.size() == 5);
    REQUIRE(symbols.size() == 5);
    REQUIRE(charges.size() == 5);
    REQUIRE(molarMasses.size() == 5);

    for(auto name : names)
        REQUIRE(name == "foo");

    for(auto symbol : symbols)
        REQUIRE(symbol == "Xy");

    for(auto charge : charges)
        REQUIRE(charge == 1.0);

    for(auto molarMass : molarMasses)
        REQUIRE(molarMass == 14.0);
}
