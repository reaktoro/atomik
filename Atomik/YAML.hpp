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

    /// Implicitly convert this yaml object into another type.
    template <typename T> operator T() { return as<T>(); }
};

} // namespace Atomik

namespace YAML {

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
        return node >> obj;
    }
};

} // namespace YAML