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

#pragma once

// C++ includes
#include <any>
#include <istream>
#include <string>

namespace Atomik {

// Forward declarations
class Element;
class Elements;
class Substance;
class Substances;

/// A type used to serialize/deserialize Atomik types based on yaml format.
class yaml
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

    /// Convert this yaml object into an object of type Element.
    operator Element() const;

    /// Convert this yaml object into an object of type Elements.
    operator Elements() const;

    /// Convert this yaml object into an object of type Substance.
    operator Substance() const;

    /// Convert this yaml object into an object of type Substances.
    operator Substances() const;

    /// Convert an object of type Element into this object of type yaml.
    auto operator=(const Element& obj) -> yaml&;

    /// Convert an object of type Elements into this object of type yaml.
    auto operator=(const Elements& obj) -> yaml&;

    /// Convert an object of type Substance into this object of type yaml.
    auto operator=(const Substance& obj) -> yaml&;

    /// Convert an object of type Substances into this object of type yaml.
    auto operator=(const Substances& obj) -> yaml&;

private:
    /// The abstracted YAML node
    std::any node;
};

} // namespace Atomik