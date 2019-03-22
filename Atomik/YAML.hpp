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

#pragma once

// C++ includes
#include <istream>
#include <string>

// yaml-cpp includes
#include <yaml-cpp/yaml.h>

// Atomik includes
#include <Atomik/Exception.hpp>

namespace Atomik {

/// A class used to serialize/deserialize other types based on yaml format.
class yaml : public YAML::Node
{
public:
    /// Construct an object of type yaml.
    yaml();

    /// Construct an object of type yaml from a given input string.
    yaml(const char* input);

    /// Construct an object of type yaml from a given input string.
    yaml(const std::string& input);

    /// Construct an object of type yaml from a given input stream.
    yaml(std::istream& input);

    /// Construct an object of type yaml from a given Node object.
    yaml(const Node& node);

    /// Return the node at given key. Runtime error if key does not exist.
    template <typename Key>
    auto at(const Key& key) -> yaml
    {
        auto node = Node::operator[](key);
        error(!node, "Could not get YAML node with key ", key, ".");
        return node;
    }

    /// Return the node at given key. Runtime error if key does not exist.
    template <typename Key>
    auto at(const Key& key) const -> const yaml { return yaml::at(key); }

    /// Return the node at given key. No check is made to assert whether if key exists.
    template <typename Key>
    auto operator[](const Key& key) -> yaml { return Node::operator[](key); }

    /// Return the node at given key. No check is made to assert whether if key exists.
    template <typename Key>
    auto operator[](const Key& key) const -> const yaml { return Node::operator[](key); }

    /// Get the node's value casted to a given type.
    template <typename T>
    auto get() const -> T { return as<T>(); }

    /// Get the node's value and set to a given argument.
    template <typename T>
    auto get_to(T& val) const { val = as<T>(); }

    /// Implicitly convert this yaml object into another type.
    template <typename T>
    operator T() { return as<T>(); }
};

} // namespace Atomik

namespace YAML {

template <typename T, std::enable_if_t<std::is_arithmetic_v<T>>...>
auto operator>>(const Node& node, T& val) -> bool
{
    if(node && node.IsScalar())
    {
        val = node.as<T>();
        return true;
    }
    return false;
}

inline auto operator>>(const Node& node, std::string& val) -> bool
{
    if(node)
    {
        val = node.as<std::string>();
        return true;
    }
    return false;
}

template <typename T>
auto operator>>(const Node& node, std::vector<T>& val) -> bool
{
    if(node && node.IsSequence())
    {
        val = node.as<std::vector<T>>();
        return true;
    }
    return false;
}

template <typename Type>
struct convert
{
    static auto encode(const Type& obj)
    {
        Node node;
        node << obj;
        return node;
    }

    static auto decode(const Node& node, Type& obj)
    {
        bool success = node >> obj;
        Atomik::error(!success, "Could not understand YAML node:\n", node, "Check if there is any missing entry.");
        return success;
    }
};

} // namespace YAML