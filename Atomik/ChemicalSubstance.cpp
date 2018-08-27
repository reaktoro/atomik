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

#include "ChemicalSubstance.hpp"

namespace Atomik {
namespace internal {

const ChemicalElements elements;

} // namespace internal

ChemicalSubstance::ChemicalSubstance()
{}

ChemicalSubstance::ChemicalSubstance(std::string formula)
{
    initialize(formula);
}

ChemicalSubstance::ChemicalSubstance(std::string formula, const ChemicalElements& elements)
{
    initialize(formula, elements);
}

auto ChemicalSubstance::initialize(std::string formula) -> void
{
    initialize(formula, internal::elements);
}

auto ChemicalSubstance::initialize(std::string formula, const ChemicalElements& elements) -> void
{
    // Initialize the chemical formula of the chemical substance
    m_formula.initialize(formula);

    // Initialize the chemical elements of the chemical substance
    m_elements.clear();
    for(const auto& pair : m_formula.elements())
        m_elements.emplace_back(elements.get(pair.first), pair.second);

    // Initialize the molar mass of the chemical substance
    m_molarmass = 0.0;
    for(const auto& pair : m_elements)
        m_molarmass += std::get<1>(pair) * std::get<0>(pair).atomicWeight();
}

auto ChemicalSubstance::formula() const -> std::string
{
    return m_formula.formula();
}

auto ChemicalSubstance::elements() const -> const std::vector<std::tuple<ChemicalElement, double>>&
{
    return m_elements;
}

auto ChemicalSubstance::charge() -> double
{
    return m_formula.charge();
}

auto ChemicalSubstance::molarMass() -> double
{
    return m_molarmass;
}

} // namespace Atomik
