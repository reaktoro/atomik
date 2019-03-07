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

#include "Substances.hpp"

// Atomik includes
#include <Atomik/Algorithms.hpp>
#include <Atomik/ChemicalFormula.hpp>
#include <Atomik/Exception.hpp>
#include <Atomik/StringList.hpp>
#include <Atomik/WithUtils.hpp>

namespace Atomik {

Substances::Substances()
{}

Substances::Substances(std::vector<Substance> substances)
: m_substances(std::move(substances))
{}

Substances::Substances(StringList formulas)
: m_substances(formulas.size())
{
    transform(formulas, m_substances, [&](std::string formula) { return Substance(formula); });
}

auto Substances::append(Substance substance) -> void
{
    m_substances.emplace_back(std::move(substance));
}

auto Substances::data() const -> const std::vector<Substance>&
{
    return m_substances;
}

auto Substances::size() const -> std::size_t
{
    return data().size();
}

auto Substances::operator[](std::size_t index) const -> const Substance&
{
    return data()[index];
}

auto Substances::indexWithName(std::string name) const -> std::size_t
{
    return indexfn(data(), Atomik::withName(name));
}

auto Substances::indexWithFormula(std::string formula) const -> std::size_t
{
    return indexfn(data(), Atomik::withFormula(formula));
}

auto Substances::getWithName(std::string name) const -> Substance
{
    auto idx = indexWithName(name);
    error(idx >= size(), "Could not find a substance with the given name `", name, "`.");
    return m_substances[idx];
}

auto Substances::getWithFormula(std::string formula) const -> Substance
{
    auto idx = indexWithFormula(formula);
    error(idx >= size(), "Could not find a substance with the given formula `", formula, "`.");
    return m_substances[idx];
}

auto Substances::withNames(const StringList& names) const -> Substances
{
    std::vector<Substance> selected(names.size());
    transform(names, selected, [&](auto&& name) { return getWithName(name); });
    return Substances(selected);
}

auto Substances::withFormulas(const StringList& formulas) const -> Substances
{
    std::vector<Substance> selected(formulas.size());
    transform(formulas, selected, [&](auto&& formula) { return getWithFormula(formula); });
    return Substances(selected);
}

auto Substances::withTag(std::string tag) const -> Substances
{
    return Substances(filter(data(), Atomik::withTag(tag)));
}

auto Substances::withoutTag(std::string tag) const -> Substances
{
    return Substances(remove(data(), Atomik::withTag(tag)));
}

auto Substances::withTags(const StringList& tags) const -> Substances
{
    return Substances(filter(data(), Atomik::withTags(tags.data())));
}

auto Substances::withoutTags(const StringList& tags) const -> Substances
{
    return Substances(remove(data(), Atomik::withTags(tags.data())));
}

auto Substances::withElements(const StringList& symbols) const -> Substances
{
    return Substances(filter(data(), Atomik::withSymbols(symbols.data())));
}

auto Substances::withElementsOf(const StringList& formulas) const -> Substances
{
    std::vector<std::string> symbols;
    for(auto formula : formulas)
        symbols = merge(symbols, ChemicalFormula(formula).symbols());
    return withElements(symbols);
}

auto Substances::tagged(const std::string& tag) const -> Substances
{
    return withTag(tag);
}

auto Substances::untagged(const std::string& tag) const -> Substances
{
    return withoutTag(tag);
}

auto Substances::containing(const StringList& elements) const -> Substances
{
    return withElements(elements);
}

} // namespace Atomik
