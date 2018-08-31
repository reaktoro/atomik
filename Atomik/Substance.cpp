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

/// The default database of elements
const ElementDatabase default_elementdb;

// Throw a runtime error if the substance name has spaces.
auto checkSubstanceNameHasNoSpaces(std::string name) -> void
{
    // Check the name provided has no spaces
    if(name.find(' ') != std::string::npos)
        throw std::runtime_error("***ERROR***: The given substance name `" + name + "` violates the naming rule for substance names, which must have no spaces.");
}

} // namespace internal

Substance::Substance()
{}

Substance::Substance(std::string formula)
: Substance(formula, formula, internal::default_elementdb)
{
}

Substance::Substance(std::string formula, const ElementDatabase& elementdb)
: Substance(formula, formula, elementdb)
{
}

Substance::Substance(std::string name, std::string formula)
: Substance(name, formula, internal::default_elementdb)
{
}

Substance::Substance(std::string name, std::string formula, const ElementDatabase& elementdb)
: m_name(name), m_formula(formula)
{
    // Check if provided name has space and throws a runtime error if true
    internal::checkSubstanceNameHasNoSpaces(name);

    // Initialize the chemical elements of the chemical substance
    m_elements.clear();
    for(const auto& pair : m_formula.elements())
        m_elements.emplace_back(elementdb.get(pair.first), pair.second);

    // Initialize the molar mass of the chemical substance
    m_molarmass = 0.0;
    for(const auto& pair : m_elements)
        m_molarmass += std::get<1>(pair) * std::get<0>(pair).atomicWeight();
}

auto Substance::name() const -> std::string
{
    return m_name;
}

auto Substance::formula() const -> std::string
{
    return m_formula.formula();
}

auto Substance::elements() const -> const std::vector<std::tuple<Element, double>>&
{
    return m_elements;
}

auto Substance::charge() const -> double
{
    return m_formula.charge();
}

auto Substance::molarMass() const -> double
{
    return m_molarmass;
}

auto Substance::coefficient(std::string symbol) const -> double
{
    return m_formula.coefficient(symbol);
}

} // namespace Atomik
