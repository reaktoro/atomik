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

// C++ includes
#include <string>

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

} // namespace YAML

namespace Atomik {


// auto operator>>(std::istream& is, ChemicalFormula& formula) -> std::istream&
// {
//     std::string str;
//     is >> str;
//     formula = ChemicalFormula(str);
//     return is;
// }

// auto operator>>(std::istream& is, Element& element) -> std::istream&
// {
//     ElementAttributes data;
//     is >> data;
//     element = Element(data);
//     return is;
// }

// auto operator>>(std::istream& is, ElementAttributes& element) -> std::istream&
// {
//     is
//     >> element.symbol
//     >> element.name
//     >> element.atomic_number
//     >> element.atomic_weight
//     >> element.electronegativity;
//     return is;
// }

// auto operator<<(std::ostream& os, const ChemicalFormula& formula) -> std::ostream&
// {
//     os << formula.str();
//     return os;
// }

// auto operator<<(std::ostream& os, const Element& element) -> std::ostream&
// {
//     os << element.data();
//     return os;
// }

// auto operator<<(std::ostream& os, const ElementAttributes& element) -> std::ostream&
// {
//     os
//     << element.symbol << " "
//     << element.name << " "
//     << element.atomic_number << " "
//     << element.atomic_weight << " "
//     << element.electronegativity;
//     return os;
// }

} // namespace Atomik
