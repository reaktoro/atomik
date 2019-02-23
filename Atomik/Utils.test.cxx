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
#include <Atomik/Utils.hpp>
using namespace Atomik;

TEST_CASE("Testing Utils", "[Utils]")
{
    std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> res;

    // Test the function index(container, value)
    for(auto n : nums)
        REQUIRE( index(nums, n) == n - 1);

    // Test the function indexfn(container, pred)
    for(auto n : nums)
        REQUIRE( indexfn(nums, [=](auto x) { return x == n; } ) == n - 1);

    // Test the filter function
    res = filter(nums, [](auto x) { return x % 2 == 0; });

    REQUIRE( res.size() == 4 );
    REQUIRE( res[0] == 2 );
    REQUIRE( res[1] == 4 );
    REQUIRE( res[2] == 6 );
    REQUIRE( res[3] == 8 );

    // Test the remove function
    res = remove(nums, [](auto x) { return x % 2 == 1; });

    REQUIRE( res.size() == 4 );
    REQUIRE( res[0] == 2 );
    REQUIRE( res[1] == 4 );
    REQUIRE( res[2] == 6 );
    REQUIRE( res[3] == 8 );
}
