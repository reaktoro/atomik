// Atomik is a library that implements basic chemical concepts such as elements, substances, and reactions.
//
// Copyright (C) 2018-2019 Allan Leal and Reaktoro Contributors
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
#include <string>
#include <valarray>
#include <vector>

namespace Atomik {

struct Extract
{
    /// Return an array of molar masses from objects with `molarMass()` method.
    template <typename Container>
    static auto molarMasses(const Container& items)
    {
        return values(items, [](auto const& x) { return x.molarMass(); });
    }

    /// Return an array of charges from objects with `charge()` method.
    template <typename Container>
    static auto charges(const Container& items)
    {
        return values(items, [](auto const& x) { return x.charge(); });
    }

    /// Return a vector of names from objects with `symbol()` method.
    template <typename Container>
    static auto symbols(const Container& items)
    {
        return strings(items, [](auto const& x) { return x.symbol(); });
    }

    /// Return a vector of names from objects with `name()` method.
    template <typename Container>
    static auto names(const Container& items)
    {
        return strings(items, [](auto const& x) { return x.name(); });
    }

    /// Return an array of values from objects using an extractor function.
    template <typename Container, typename Function>
    static auto values(const Container& items, const Function& f)
    {
        return extract<std::valarray<double>>(items, f);
    }

    /// Return a vector of strings from objects using an extractor function.
    template <typename Container, typename Function>
    static auto strings(const Container& items, const Function& f)
    {
        return extract<std::vector<std::string>>(items, f);
    }

    /// Extract data from objects using an extractor function.
    template <typename Result, typename Container, typename Function>
    static auto extract(const Container& items, const Function& f)
    {
        Result res(items.size());
        std::transform(std::begin(items), std::end(items), std::begin(res), f);
        return res;
    }
};

} // namespace Atomik
