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

namespace YAML {

/// A class used to serialize/deserialize other types based on yaml format.
class yaml : public Node
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

    /// Implicitly convert this yaml object into another type.
    template <typename T>
    operator T() { return as<T>(); }
};

/// Return a child node with given key. Check if key exists and raises error if it does not.
inline auto operator&(const Node& node, const std::string& key)
{
    auto child = node[key];
    Atomik::error(!child, "Could not get YAML node with key ", key, " .");
    return child;
}

template <typename T>
auto set(const Node& node, const std::string& key, T& value) -> void
{
    auto child = node & key;
    try {
        value = child.as<T>();
    }
    catch(...) {
        Atomik::error(true, "Could not convert YAML node with key ", key, " to requested value type.");
    }
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
        node >> obj;
        return true;
    }
};

} // namespace YAML

namespace Atomik {

// Ensure YAML namespace is resolved when using Atomik namespace.
using namespace YAML;

} // namespace Atomik
