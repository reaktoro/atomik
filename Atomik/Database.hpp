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
#include <functional>
#include <string>
#include <vector>

namespace Atomik {

/// A type used to define a chemical element and its attributes.
template<typename T>
class Database
{
public:
    /// Construct a default Database object.
    Database() : m_data() {}

    auto index(std::string name) const -> std::size_t;

    auto pop() { m_data.pop_back(); }

    auto push(const T& x) { m_data.push_back(x); }

    auto push(T&& x) { m_data.push_back(x); }

    template<typename Pred>
    auto filter(const Pred& pred) const -> std::optional<T>;

    template<typename Pred>
    auto find(const T& x) const -> std::optional<T>;

    template<typename Pred>
    auto filter(const Pred& pred) const -> std::optional<T>;
    auto remove();
    auto find();
    auto insert();
    auto size();
    auto erase();

private:
    /// The data in the database.
    std::vector<T> m_data;
};

/// Compare two Element objects for less than.
auto operator<(const Element& lhs, const Element& rhs) -> bool;

/// Compare two Element objects for equality.
auto operator==(const Element& lhs, const Element& rhs) -> bool;

} // namespace Atomik
