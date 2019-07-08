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
#include <Atomik/Elements.hpp>
#include <Atomik/Exception.hpp>
#include <Atomik/Extract.hpp>
#include <Atomik/StringList.hpp>
#include <Atomik/SubstanceElements.hpp>
#include <Atomik/SubstanceFormula.hpp>

namespace Atomik {
namespace {

/// The default database of elements
const Elements periodicElements = Elements::PeriodicTable();

} // namespace

struct Substance::Impl
{
    /// The name of the substance such as `H2O(aq)`, `O2(g)`, `H+(aq)`.
    std::string name;

    /// The chemical formula of the substance such as `H2O`, `O2`, `H+`.
    SubstanceFormula formula;

    /// The elements of the substance.
    SubstanceElements elements;

    /// The type of the substance such as `aqueous`, `gaseous`, `liquid`, "mineral", etc..
    std::string type;

    /// The tags of the substance such as `organic`, `mineral`.
    std::vector<std::string> tags;

    /// Construct a default Substance::Impl instance
    Impl()
    {}

    /// Construct a Substance::Impl instance
    Impl(const std::string& formulaStr, const Elements& db)
    : name(formulaStr),
      formula(formulaStr),
      elements({
          .elements = db.withSymbols(formula.symbols()),
          .coefficients = formula.coefficients(),
          .oxidationStates = {}
      }),
      type(),
      tags()
    {
    }

    /// Construct a Substance::Impl instance
    Impl(const Args& args)
    : name(args.name),
      formula(args.formula),
      elements(args.elements),
      type(args.type),
      tags(args.tags)
    {
    }
};

Substance::Substance()
: pimpl(new Impl())
{}

Substance::Substance(const std::string& formula)
: pimpl(new Impl(formula, periodicElements))
{}

Substance::Substance(const std::string& formula, const Elements& db)
: pimpl(new Impl(formula, db))
{}

Substance::Substance(const Args& args)
: pimpl(new Impl(args))
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
    Substance res;
    res.pimpl = std::make_shared<Impl>(*pimpl);
    res.pimpl->name = name;
    return res;
    // auto attributes = pimpl->attributes;
    // attributes.name = name;
    // return Substance(attributes, elements());
}

auto Substance::replaceTags(std::vector<std::string> tags) -> Substance
{
    auto attributes = pimpl->attributes;
    attributes.tags = std::move(tags);
    return Substance(attributes, elements());
}

auto Substance::name() const -> std::string
{
    return pimpl->attributes.name;
}

auto Substance::formula() const -> const Formula&
{
    return pimpl->attributes.formula;
}

auto Substance::tags() const -> const std::vector<std::string>&
{
    return pimpl->attributes.tags;
}

auto Substance::elements() const -> const Elements&
{
    return pimpl->elements;
}

auto Substance::symbols() const -> const std::vector<std::string>&
{
    return formula().symbols();
}

auto Substance::coefficients() const -> const std::vector<double>&
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
