// Atomik is a library that implements basic chemical concepts such as elements, substances, and reactions.
//
// Copyright (C) 2014-2019 Allan Leal and Atomik Contributors
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

#include "YAML.hpp"

// yaml includes
#include <yaml-cpp/yaml.h>

// Atomik includes
#include <Atomik/ChemicalFormula.hpp>
#include <Atomik/Element.hpp>
#include <Atomik/Elements.hpp>
#include <Atomik/Substance.hpp>
#include <Atomik/Substances.hpp>

namespace YAML {

template <typename T>
auto operator<<(T& val, const Node& node)
{
    if(node) val = node.as<T>();
}

using namespace Atomik;

template<>
struct convert<ElementAttributes>
{
    static auto encode(const ElementAttributes& obj)
    {
        Node node;
        node["symbol"] = obj.symbol;
        node["name"] = obj.name;
        node["atomicNumber"] = obj.atomicNumber;
        node["atomicWeight"] = obj.atomicWeight;
        node["electronegativity"] = obj.electronegativity;
        node["tags"] = obj.tags;
        return node;
    }

    static auto decode(const Node& node, ElementAttributes& obj)
    {
        obj.symbol << node["symbol"];
        obj.name << node["name"];
        obj.atomicNumber << node["atomicNumber"];
        obj.atomicWeight << node["atomicWeight"];
        obj.electronegativity << node["electronegativity"];
        obj.tags << node["tags"];
        return true;
    }
};

template<>
struct convert<SubstanceAttributes>
{
    static auto encode(const SubstanceAttributes& obj)
    {
        Node node;
        node["formula"] = obj.formula;
        node["name"] = obj.name;
        node["tags"] = obj.tags;
        return node;
    }

    static auto decode(const Node& node, SubstanceAttributes& obj)
    {
        obj.formula << node["formula"];
        obj.name << node["name"];
        obj.tags << node["tags"];
        return true;
    }
};

template<>
struct convert<Element>
{
    static auto encode(const Element& obj)
    {
        Node node;
        node["symbol"] = obj.symbol();
        node["name"] = obj.name();
        node["atomicNumber"] = obj.atomicNumber();
        node["atomicWeight"] = obj.atomicWeight();
        node["electronegativity"] = obj.electronegativity();
        node["tags"] = obj.tags();
        return node;
    }

    static auto decode(const Node& node, Element& obj)
    {
        auto attributes = node.as<ElementAttributes>();
        obj = Element(attributes);
        return true;
    }
};

template<>
struct convert<Elements>
{
    static auto encode(const Elements& obj)
    {
        Node node;
        for(auto element : obj)
            node.push_back(element);
        return node;
    }

    static auto decode(const Node& node, Elements& obj)
    {
        for(auto child : node)
            obj.append(child.as<Element>());
        return true;
    }
};

template<>
struct convert<Substance>
{
    static auto encode(const Substance& obj)
    {
        Node node;
        node["formula"] = obj.formula().str();
        node["name"] = obj.name();
        node["tags"] = obj.tags();
        return node;
    }

    static auto decode(const Node& node, Substance& obj)
    {
        auto attributes = node.as<SubstanceAttributes>();
        obj = Substance(attributes);
        return true;
    }
};

template<>
struct convert<Substances>
{
    static auto encode(const Substances& obj)
    {
        Node node;
        for(auto substance : obj)
            node.push_back(substance);
        return node;
    }

    static auto decode(const Node& node, Substances& obj)
    {
        for(auto child : node)
            obj.append(child.as<Substance>());
        return true;
    }
};

} // namespace YAML

namespace Atomik {

/// Cast an yaml node of type any to YAML::Node
inline auto cast(const std::any& node)
{
    return std::any_cast<YAML::Node>(node);
}

yaml::yaml()
: node(YAML::Node())
{}

yaml::yaml(const char* input)
: node(YAML::Load(input))
{}

yaml::yaml(const std::string& input)
: node(YAML::Load(input))
{}

yaml::yaml(std::istream& input)
: node(YAML::Load(input))
{}

yaml::operator Element() const
{
    return cast(node).as<Element>();
}

yaml::operator Elements() const
{
    return cast(node).as<Elements>();
}

yaml::operator Substance() const
{
    return cast(node).as<Substance>();
}

yaml::operator Substances() const
{
    return cast(node).as<Substances>();
}

auto yaml::operator=(const Element& obj) -> yaml&
{
    YAML::Node yamlnode(obj);
    node = yamlnode;
    return *this;
}

auto yaml::operator=(const Elements& obj) -> yaml&
{
    YAML::Node yamlnode(obj);
    node = yamlnode;
    return *this;
}

auto yaml::operator=(const Substance& obj) -> yaml&
{
    YAML::Node yamlnode(obj);
    node = yamlnode;
    return *this;
}

auto yaml::operator=(const Substances& obj) -> yaml&
{
    YAML::Node yamlnode(obj);
    node = yamlnode;
    return *this;
}

} // Atomik