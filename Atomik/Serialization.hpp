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

// yaml and json includes
#include <yaml-cpp/yaml.h>
#include <nlohmann/json.hpp>

namespace Atomik {

/// A type alias for YAML::Node
using yaml = YAML::Node;

/// A type alias for nlohmann::json
using json = nlohmann::json;

// Forward declarations (class)
class Element;
class Elements;
class Substance;
class Substances;

// Forward declarations (struct)
struct ElementAttributes;
struct SubstanceAttributes;

//=================================================================================================
// INPUT OPERATORS
//=================================================================================================

/// Initialize an object of type ElementAttributes from an yaml node.
auto operator>>(const yaml& node, ElementAttributes& obj);

/// Initialize an object of type SubstanceAttributes from an yaml node.
auto operator>>(const yaml& node, SubstanceAttributes& obj);

/// Initialize an object of type Element from an yaml node.
auto operator>>(const yaml& node, Element& obj);

/// Initialize an object of type Elements from an yaml node.
auto operator>>(const yaml& node, Elements& obj);

/// Initialize an object of type Substance from an yaml node.
auto operator>>(const yaml& node, Substance& obj);

/// Initialize an object of type Substances from an yaml node.
auto operator>>(const yaml& node, Substances& obj);

//=================================================================================================
// OUTPUT OPERATORS
//=================================================================================================

/// Save an object of type ElementAttributes to an yaml node.
auto operator<<(yaml& node, const ElementAttributes& obj);

/// Save an object of type SubstanceAttributes to an yaml node.
auto operator<<(yaml& node, const SubstanceAttributes& obj);

/// Save an object of type Element to an yaml node.
auto operator<<(yaml& node, const Element& obj);

/// Save an object of type Elements to an yaml node.
auto operator<<(yaml& node, const Elements& obj);

/// Save an object of type Substance to an yaml node.
auto operator<<(yaml& node, const Substance& obj);

/// Save an object of type Substances to an yaml node.
auto operator<<(yaml& node, const Substances& obj);

} // namespace Atomik
