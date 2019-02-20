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

#include "Element.hpp"

namespace Atomik {

Element::Element()
: m_data(new ElementData{})
{}

Element::Element(const ElementData& data)
 : m_data(new ElementData(data))
{}

auto Element::symbol() const -> std::string
{
    return m_data->symbol;
};

auto Element::name() const -> std::string
{
    return m_data->name;
};

auto Element::atomicNumber() const -> std::size_t
{
    return m_data->atomic_number;
};

auto Element::atomicWeight() const -> double
{
    return m_data->atomic_weight;
};

auto Element::electronegativity() const -> double
{
    return m_data->electronegativity;
};

auto Element::tags() const -> std::set<std::string>
{
    return m_data->tags;
};

auto Element::data() const -> const ElementData&
{
    return *m_data;
}

auto operator<(const Element& lhs, const Element& rhs) -> bool
{
    return lhs.atomicNumber() < rhs.atomicNumber();
}

auto operator==(const Element& lhs, const Element& rhs) -> bool
{
    return lhs.atomicNumber() == rhs.atomicNumber();
}

} // namespace Atomik
