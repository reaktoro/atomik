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

#pragma once

// C++ includes
#include <algorithm>

namespace Atomik {

template <typename Container, typename T>
auto index(Container const& c, T const& value)
{
    return std::find(c.begin(), c.end(), value) - c.begin();
}

template <typename Container, typename Predicate>
auto indexfn(Container const& c, Predicate const& pred)
{
    return std::find_if(c.begin(), c.end(), pred) - c.begin();
}

} // namespace Atomik
