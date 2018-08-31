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

#include "Substance.hpp"

namespace Atomik {
namespace internal {

const ElementDatabase default_elementdb;

} // namespace internal

Substance::Substance()
{}

Substance::Substance(std::string formula)
: Substance(formula, internal::default_elementdb)
{
}

Substance::Substance(std::string formula, const ElementDatabase& elementdb)
{
    // Initialize the chemical formula of the chemical substance
    m_formula.initialize(formula);

    // Initialize the chemical elements of the chemical substance
    m_elements.clear();
    for(const auto& pair : m_formula.elements())
        m_elements.emplace_back(elementdb.get(pair.first), pair.second);

    // Initialize the molar mass of the chemical substance
    m_molarmass = 0.0;
    for(const auto& pair : m_elements)
        m_molarmass += std::get<1>(pair) * std::get<0>(pair).atomicWeight();
}

auto Substance::formula() const -> std::string
{
    return m_formula.formula();
}

auto Substance::elements() const -> const std::vector<std::tuple<Element, double>>&
{
    return m_elements;
}

auto Substance::charge() -> double
{
    return m_formula.charge();
}

auto Substance::molarMass() -> double
{
    return m_molarmass;
}

} // namespace Atomik
