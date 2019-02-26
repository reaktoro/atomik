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
#include <istream>
#include <ostream>

namespace Atomik {

// // Forward declarations (class)
// class ChemicalFormula;
// class Element;

// // Forward declarations (struct)
// struct ElementAttributes;

// //=================================================================================================
// // INPUT STREAM OPERATORS
// //=================================================================================================

// /// Initialize a ChemicalFormula object from an input stream.
// auto operator>>(std::istream& is, ChemicalFormula& formula) -> std::istream&;

// /// Initialize an Element object from an input stream.
// auto operator>>(std::istream& is, Element& element) -> std::istream&;

// /// Initialize an ElementAttributes object from an input stream.
// auto operator>>(std::istream& is, ElementAttributes& element) -> std::istream&;

// //=================================================================================================
// // OUTPUT STREAM OPERATORS
// //=================================================================================================

// /// Save a ChemicalFormula object to an output stream.
// auto operator<<(std::ostream& os, const ChemicalFormula& formula) -> std::ostream&;

// /// Save an Element object to an output stream.
// auto operator<<(std::ostream& os, const Element& element) -> std::ostream&;

// /// Save an ElementAttributes object to an output stream.
// auto operator<<(std::ostream& os, const ElementAttributes& element) -> std::ostream&;

} // namespace Atomik
