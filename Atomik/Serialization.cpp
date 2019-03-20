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

#include "Serialization.hpp"

// Atomik includes
#include <Atomik/Element.hpp>
#include <Atomik/Elements.hpp>
#include <Atomik/Formula.hpp>
#include <Atomik/Substance.hpp>
#include <Atomik/Substances.hpp>

namespace YAML {

using namespace Atomik;

auto operator<<(Node& node, const Formula& obj) -> Node&
{
    node["label"] = obj.label();
    node["symbols"] = obj.symbols();
    node["coefficients"] = obj.coefficients();
    return node;
}

auto operator<<(Node& node, const Element& obj) -> Node&
{
    node["symbol"] = obj.symbol();
    node["name"] = obj.name();
    node["atomicNumber"] = obj.atomicNumber();
    node["atomicWeight"] = obj.atomicWeight();
    node["electronegativity"] = obj.electronegativity();
    node["tags"] = obj.tags();
    return node;
}

auto operator<<(Node& node, const Elements& obj) -> Node&
{
    for (auto element : obj)
        node.push_back(element);
    return node;
}

auto operator<<(Node& node, const Substance& obj) -> Node&
{
    node["formula"] = obj.formula();
    node["name"] = obj.name();
    node["tags"] = obj.tags();
    return node;
}

auto operator<<(Node& node, const Substances& obj) -> Node&
{
    for (auto substance : obj)
        node.push_back(substance);
    return node;
}

auto operator>>(const Node& node, FormulaData& obj) -> bool
{
    return
    node["label"] >> obj.label &&
    node["symbols"] >> obj.symbols &&
    node["coefficients"] >> obj.coefficients;
}

auto operator>>(const Node& node, Formula& obj) -> bool
{
    FormulaData data;
    bool res = node >> data;
    obj = Formula(data);
    return res;
}

auto operator>>(const Node& node, ElementData& obj) -> bool
{
    return
    node["symbol"] >> obj.symbol &&
    node["name"] >> obj.name &&
    node["atomicNumber"] >> obj.atomicNumber &&
    node["atomicWeight"] >> obj.atomicWeight &&
    node["electronegativity"] >> obj.electronegativity &&
    node["tags"] >> obj.tags;
}

auto operator>>(const Node& node, Element& obj) -> bool
{
    ElementData data;
    bool res = node >> data;
    obj = Element(data);
    return res;
}

auto operator>>(const Node& node, Elements& obj) -> bool
{
    Element elem;
    for(auto child : node)
        if(child >> elem)
            obj.append(elem);
        else return false;
    return true;
}

auto operator>>(const Node& node, SubstanceData& obj) -> bool
{
    return
    node["formula"] >> obj.formula &&
    node["name"] >> obj.name &&
    node["tags"] >> obj.tags;
}

auto operator>>(const Node& node, Substance& obj) -> bool
{
    SubstanceData data;
    bool res = node >> data;
    obj = Substance(data);
    return res;
}

auto operator>>(const Node& node, Substances& obj) -> bool
{
    Substance subs;
    for(auto child : node)
        if(child >> subs)
            obj.append(subs);
        else return false;
    return true;
}

} // Atomik