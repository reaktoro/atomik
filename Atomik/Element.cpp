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

#include "Element.hpp"

// Atomik includes
#include <Atomik/Algorithms.hpp>

namespace Atomik {

struct Element::Impl
{
    /// The attributes of the element.
    ElementData attributes;

    /// Construct a default Element::Impl object.
    Impl()
    {}

    /// Construct an Element::Impl object with given attributes.
    Impl(const ElementData& attributes)
    : attributes(attributes)
    {}
};

Element::Element()
: pimpl(new Impl())
{}

Element::Element(const ElementData& attributes)
 : pimpl(new Impl(attributes))
{}

auto Element::replaceSymbol(const std::string& symbol) const -> Element
{
    auto attributes = pimpl->attributes;
    attributes.symbol = symbol;
    return Element(attributes);
}

auto Element::replaceName(const std::string& name) const -> Element
{
    auto attributes = pimpl->attributes;
    attributes.name = name;
    return Element(attributes);
}

auto Element::replaceAtomicNumber(std::size_t atomicNumber) const -> Element
{
    auto attributes = pimpl->attributes;
    attributes.atomicNumber = atomicNumber;
    return Element(attributes);
}

auto Element::replaceAtomicWeight(double atomicWeight) const -> Element
{
    auto attributes = pimpl->attributes;
    attributes.atomicWeight = atomicWeight;
    return Element(attributes);
}

auto Element::replaceElectronegativity(double electronegativity) const -> Element
{
    auto attributes = pimpl->attributes;
    attributes.electronegativity = electronegativity;
    return Element(attributes);
}

auto Element::replaceTags(std::vector<std::string> tags) const -> Element
{
    auto attributes = pimpl->attributes;
    attributes.tags = tags;
    return Element(attributes);
}

auto Element::symbol() const -> std::string
{
    return pimpl->attributes.symbol;
}

auto Element::name() const -> std::string
{
    return pimpl->attributes.name;
}

auto Element::atomicNumber() const -> std::size_t
{
    return pimpl->attributes.atomicNumber;
}

auto Element::atomicWeight() const -> double
{
    return pimpl->attributes.atomicWeight;
}

auto Element::electronegativity() const -> double
{
    return pimpl->attributes.electronegativity;
}

auto Element::tags() const -> const std::vector<std::string>&
{
    return pimpl->attributes.tags;
}

auto Element::molarMass() const -> double
{
    return atomicWeight();
}

auto Element::hasTag(const std::string& tag) const -> bool
{
    return index(tags(), tag) < tags().size();
}

auto operator<(const Element& lhs, const Element& rhs) -> bool
{
    return lhs.atomicNumber() < rhs.atomicNumber();
}

auto operator==(const Element& lhs, const Element& rhs) -> bool
{
    return lhs.symbol()            == rhs.symbol()            &&
           lhs.name()              == rhs.name()              &&
           lhs.atomicNumber()      == rhs.atomicNumber()      &&
           lhs.atomicWeight()      == rhs.atomicWeight()      &&
           lhs.electronegativity() == rhs.electronegativity() &&
           lhs.tags()              == rhs.tags()
           ;
}

} // attributes Atomik
