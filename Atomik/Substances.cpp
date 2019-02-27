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

#include "Substances.hpp"

// C++ includes
#include <algorithm>

// Atomik includes
#include <Atomik/ChemicalFormula.hpp>
#include <Atomik/Exception.hpp>
#include <Atomik/StringList.hpp>
#include <Atomik/Utils.hpp>

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
    const auto has_name = [&](const Substance& substance) {
        return substance.name() == name;
    };
    return indexfn(data(), has_name);
}

auto Substances::indexWithFormula(std::string formula) const -> std::size_t
{
    const auto has_formula = [&](const Substance& substance) {
        return substance.formula() == formula;
    };
    return indexfn(data(), has_formula);
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
    transform(names, selected, [&](auto name) { return getWithName(name); });
    return Substances(selected);
}

auto Substances::withFormulas(const StringList& formulas) const -> Substances
{
    std::vector<Substance> selected(formulas.size());
    transform(formulas, selected, [&](auto formula) { return getWithFormula(formula); });
    return Substances(selected);
}

auto Substances::withType(std::string type) const -> Substances
{
    const auto has_type = [&](const Substance& substance) {
        return substance.type() == type;
    };
    return Substances(filter(data(), has_type));
}

auto Substances::withTag(std::string tag) const -> Substances
{
    const auto has_tag = [&](const Substance& substance) {
        return contains(substance.tags(), tag);
    };
    return Substances(filter(data(), has_tag));
}

auto Substances::withoutTag(std::string tag) const -> Substances
{
    const auto has_tag = [&](const Substance& substance) {
        return contains(substance.tags(), tag);
    };
    return Substances(remove(data(), has_tag));
}

auto Substances::withTags(const StringList& tags) const -> Substances
{
    const auto has_tags = [&](const Substance& substance) {
        return contained(tags, substance.tags());
    };
    return Substances(filter(data(), has_tags));
}

auto Substances::withoutTags(const StringList& tags) const -> Substances
{
    const auto has_tags = [&](const Substance& substance) {
        return contained(tags, substance.tags());
    };
    return Substances(remove(data(), has_tags));
}

auto Substances::withElements(const StringList& symbols) const -> Substances
{
    const auto has_elements = [&](const Substance& substance) {
        return contained(substance.symbols(), symbols);
    };
    return Substances(filter(data(), has_elements));
}

auto Substances::withElementsOf(const StringList& formulas) const -> Substances
{
    std::vector<std::string> symbols;
    for(auto formula : formulas)
        symbols = merge(symbols, ChemicalFormula(formula).symbols());
    return withElements(symbols);
}

auto Substances::append(Substance substance) -> void
{
    m_substances.emplace_back(std::move(substance));
}

} // namespace Atomik
