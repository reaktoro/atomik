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

auto operator<<(Node& node, const Formula& obj) -> void
{
    node["label"]        = obj.label();
    node["symbols"]      = obj.symbols();
    node["coefficients"] = obj.coefficients();
}

auto operator<<(Node& node, const Element& obj) -> void
{
    node["symbol"]            = obj.symbol();
    node["name"]              = obj.name();
    node["atomicNumber"]      = obj.atomicNumber();
    node["atomicWeight"]      = obj.atomicWeight();
    node["electronegativity"] = obj.electronegativity();
    node["tags"]              = obj.tags();
}

auto operator<<(Node& node, const Elements& obj) -> void
{
    node = obj.data();
}

auto operator<<(Node& node, const Substance& obj) -> void
{
    node["formula"] = obj.formula();
    node["name"]    = obj.name();
    node["tags"]    = obj.tags();
}

auto operator<<(Node& node, const Substances& obj) -> void
{
    node = obj.data();
}

auto operator>>(const Node& node, FormulaData& obj) -> void
{
    set(node, "label"       , obj.label);
    set(node, "symbols"     , obj.symbols);
    set(node, "coefficients", obj.coefficients);
}

auto operator>>(const Node& node, Formula& obj) -> void
{
    obj = Formula(node.as<FormulaData>());
}

auto operator>>(const Node& node, ElementData& obj) -> void
{
    set(node, "symbol"           , obj.symbol);
    set(node, "name"             , obj.name);
    set(node, "atomicNumber"     , obj.atomicNumber);
    set(node, "atomicWeight"     , obj.atomicWeight);
    set(node, "electronegativity", obj.electronegativity);
    set(node, "tags"             , obj.tags);
}

auto operator>>(const Node& node, Element& obj) -> void
{
    obj = Element(node.as<ElementData>());
}

auto operator>>(const Node& node, Elements& obj) -> void
{
    obj = Elements(node.as<std::vector<Element>>());
}

auto operator>>(const Node& node, SubstanceData& obj) -> void
{
    set(node, "formula", obj.formula);
    set(node, "name"   , obj.name);
    set(node, "tags"   , obj.tags);
}

auto operator>>(const Node& node, Substance& obj) -> void
{
    obj = Substance(node.as<SubstanceData>());
}

auto operator>>(const Node& node, Substances& obj) -> void
{
    obj = Substances(node.as<std::vector<Substance>>());
}

} // YAML

namespace Atomik {

auto to_json(json& j, const Formula& obj)
{
    j["label"]        = obj.label();
    j["symbols"]      = obj.symbols();
    j["coefficients"] = obj.coefficients();
}

auto to_json(json& j, const Element& obj)
{
    j["symbol"]            = obj.symbol();
    j["name"]              = obj.name();
    j["atomicNumber"]      = obj.atomicNumber();
    j["atomicWeight"]      = obj.atomicWeight();
    j["electronegativity"] = obj.electronegativity();
    j["tags"]              = obj.tags();
}

auto to_json(json& j, const Elements& obj)
{
    for (const auto& element : obj)
        j.push_back(element);
}

auto to_json(json& j, const Substance& obj)
{
    j["formula"] = obj.formula();
    j["name"]    = obj.name();
    j["tags"]    = obj.tags();
}

auto to_json(json& j, const Substances& obj)
{
    for (const auto& substance : obj)
        j.push_back(substance);
}

auto from_json(const json& j, FormulaData& obj) -> void
{
    j.at("label").get_to(obj.label);
    j.at("symbols").get_to(obj.symbols);
    j.at("coefficients").get_to(obj.coefficients);
}

auto from_json(const json& j, Formula& obj) -> void
{
    obj = Formula(j.get<FormulaData>());
}

auto from_json(const json& j, ElementData& obj) -> void
{
    j.at("symbol").get_to(obj.symbol);
    j.at("name").get_to(obj.name);
    j.at("atomicNumber").get_to(obj.atomicNumber);
    j.at("atomicWeight").get_to(obj.atomicWeight);
    j.at("electronegativity").get_to(obj.electronegativity);
    j.at("tags").get_to(obj.tags);
}

auto from_json(const json& j, Element& obj) -> void
{
    obj = Element(j.get<ElementData>());
}

auto from_json(const json& j, Elements& obj) -> void
{
    for(const auto& item : j)
        obj.append(item.get<Element>());
}

auto from_json(const json& j, SubstanceData& obj) -> void
{
    j.at("formula").get_to(obj.formula);
    j.at("name").get_to(obj.name);
    j.at("tags").get_to(obj.tags);
}

auto from_json(const json& j, Substance& obj) -> void
{
    obj = Substance(j.get<SubstanceData>());
}

auto from_json(const json& j, Substances& obj) -> void
{
    for(const auto& item : j)
        obj.append(item.get<Substance>());
}

} // Atomik