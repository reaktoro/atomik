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

struct Element::Impl
{
    /// The attributes of the element.
    ElementAttributes attributes;

    /// Construct a default Element::Impl object.
    Impl()
    {}

    /// Construct an Element::Impl object with given attributes.
    Impl(const ElementAttributes& attributes)
    : attributes(attributes)
    {}
};

Element::Element()
: pimpl(new Impl())
{}

Element::Element(const ElementAttributes& attributes)
 : pimpl(new Impl(attributes))
{}

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

auto Element::molarMass() const -> double
{
    return atomicWeight();
}

auto Element::tags() const -> const std::set<std::string>&
{
    return pimpl->attributes.tags;
}

auto Element::attributes() const -> ElementAttributes
{
    return pimpl->attributes;
}

auto Element::withSymbol(std::string symbol) const -> Element
{
    auto attribs = attributes();
    attribs.symbol = symbol;
    return Element(attribs);
}

auto Element::withName(std::string name) const -> Element
{
    auto attribs = attributes();
    attribs.name = name;
    return Element(attribs);
}

auto Element::withAtomicNumber(std::size_t atomicNumber) const -> Element
{
    auto attribs = attributes();
    attribs.atomicNumber = atomicNumber;
    return Element(attribs);
}

auto Element::withAtomicWeight(double atomicWeight) const -> Element
{
    auto attribs = attributes();
    attribs.atomicWeight = atomicWeight;
    return Element(attribs);
}

auto Element::withElectronegativity(double electronegativity) const -> Element
{
    auto attribs = attributes();
    attribs.electronegativity = electronegativity;
    return Element(attribs);
}

auto Element::withTags(std::set<std::string> tags) const -> Element
{
    auto attribs = attributes();
    attribs.tags = tags;
    return Element(attribs);
}

auto operator<(const Element& lhs, const Element& rhs) -> bool
{
    return lhs.atomicNumber() < rhs.atomicNumber();
}

auto operator==(const Element& lhs, const Element& rhs) -> bool
{
    return lhs.attributes() == rhs.attributes();
}

} // namespace Atomik
