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

// Atomik includes
#include <Atomik/ForwardDecl.hpp>
#include <Atomik/YAML.hpp>

namespace YAML {

using namespace Atomik;

auto operator<<(Node& node, const Formula& obj) -> Node&;

auto operator<<(Node& node, const Element& obj) -> Node&;

auto operator<<(Node& node, const Elements& obj) -> Node&;

auto operator<<(Node& node, const Substance& obj) -> Node&;

auto operator<<(Node& node, const Substances& obj) -> Node&;

auto operator>>(const Node& node, Formula& obj) -> bool;

auto operator>>(const Node& node, Element& obj) -> bool;

auto operator>>(const Node& node, Elements& obj) -> bool;

auto operator>>(const Node& node, Substance& obj) -> bool;

auto operator>>(const Node& node, Substances& obj) -> bool;

} // namespace YAML