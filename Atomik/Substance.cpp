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

#include "Substance.hpp"

// Atomik includes
#include <Atomik/Algorithms.hpp>
#include <Atomik/ChemicalFormula.hpp>
#include <Atomik/Elements.hpp>
#include <Atomik/Exception.hpp>
#include <Atomik/Extract.hpp>

namespace Atomik {
namespace internal {

/// The default database of elements
const Elements elementsdb = Elements::PeriodicTable();

} // namespace internal

struct Substance::Impl
{
    /// The attributes of the substance.
    SubstanceAttributes attributes;

    /// The chemical formula of the substance.
    ChemicalFormula formula;

    /// The elements of the substance.
    Elements elements;

    /// The molar mass of the substance (in unit of kg/mol).
    double molarMass;

    /// Construct a default Substance::Impl instance
    Impl()
    {}

    /// Construct a Substance::Impl instance
    Impl(SubstanceAttributes attribs, const Elements& db)
    : attributes(std::move(attribs)), formula(attributes.formula)
    {
        // Initialize the name of the substance
        if(attributes.name.empty())
            attributes.name = attributes.formula;

        // Initialize the elements of the substance
        for(auto const& symbol : formula.symbols())
            if(auto idx = db.indexWithSymbol(symbol); idx >= 0)
                elements.append(db[idx]);
            else error(true, "Substance with name ", attributes.name,
                " and formula ", attributes.formula,
                " has an unknown element with symbol ", symbol, ".");

        // Initialize the molar mass of the substance
        molarMass = (formula.coefficients() * Extract::molarMasses(elements)).sum();
    }
};

Substance::Substance()
: pimpl(new Impl())
{}

Substance::Substance(const std::string& formula)
: pimpl(new Impl({formula}, internal::elementsdb))
{}

Substance::Substance(const std::string& formula, const Elements& db)
: pimpl(new Impl({formula}, db))
{}

Substance::Substance(SubstanceAttributes attributes)
: pimpl(new Impl(std::move(attributes), internal::elementsdb))
{}

Substance::Substance(SubstanceAttributes attributes, const Elements& db)
: pimpl(new Impl(std::move(attributes), db))
{}

auto Substance::replaceFormula(const std::string& formula) -> Substance
{
    return replaceFormula(formula, elements());
}

auto Substance::replaceFormula(const std::string& formula, const Elements& db) -> Substance
{
    auto attributes = pimpl->attributes;
    attributes.formula = formula;
    return Substance(attributes, db);
}

auto Substance::replaceName(const std::string& name) -> Substance
{
    auto attributes = pimpl->attributes;
    attributes.name = name;
    return Substance(attributes, elements());
}

auto Substance::replaceTags(std::vector<std::string> tags) -> Substance
{
    auto attributes = pimpl->attributes;
    attributes.tags = std::move(tags);
    return Substance(attributes, elements());
}

auto Substance::replaceExtra(std::any extra) -> Substance
{
    auto attributes = pimpl->attributes;
    attributes.extra = std::move(extra);
    return Substance(attributes, elements());
}

auto Substance::name() const -> std::string
{
    return pimpl->attributes.name;
}

auto Substance::formula() const -> const ChemicalFormula&
{
    return pimpl->formula;
}

auto Substance::tags() const -> const std::vector<std::string>&
{
    return pimpl->attributes.tags;
}

auto Substance::extra() const -> const std::any&
{
    return pimpl->attributes.extra;
}

auto Substance::elements() const -> const Elements&
{
    return pimpl->elements;
}

auto Substance::symbols() const -> const std::vector<std::string>&
{
    return formula().symbols();
}

auto Substance::coefficients() const -> const std::valarray<double>&
{
    return formula().coefficients();
}

auto Substance::coefficient(const std::string& symbol) const -> double
{
    return formula().coefficient(symbol);
}

auto Substance::charge() const -> double
{
    return formula().charge();
}

auto Substance::molarMass() const -> double
{
    return pimpl->molarMass;
}

auto Substance::hasTag(const std::string& tag) const -> bool
{
    return index(tags(), tag) < tags().size();
}

auto operator<(const Substance& lhs, const Substance& rhs) -> bool
{
    return lhs.name() < rhs.name();
}

auto operator==(const Substance& lhs, const Substance& rhs) -> bool
{
    return lhs.name()    == rhs.name()    &&
           lhs.formula() == rhs.formula() &&
           lhs.tags()    == rhs.tags()
           ;
}

} // namespace Atomik
