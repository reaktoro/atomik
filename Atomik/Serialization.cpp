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

#include "Serialization.hpp"

// Atomik includes
#include <Atomik/ChemicalFormula.hpp>
#include <Atomik/Element.hpp>

namespace Atomik {

auto operator>>(std::istream& is, ChemicalFormula& formula) -> std::istream&
{
    std::string str;
    is >> str;
    formula = ChemicalFormula(formula);
    return is;
}

auto operator>>(std::istream& is, Element& element) -> std::istream&
{
    ElementData data;
    is >> data;
    element = Element(data);
    return is;
}

auto operator>>(std::istream& is, ElementData& element) -> std::istream&
{
    is
    >> element.symbol
    >> element.name
    >> element.atomic_number
    >> element.atomic_weight
    >> element.electronegativity;
    return is;
}

auto operator<<(std::ostream& os, const ChemicalFormula& formula) -> std::ostream&
{
    os << formula.str();
    return os;
}

auto operator<<(std::ostream& os, const Element& element) -> std::ostream&
{
    os << element.data();
    return os;
}

auto operator<<(std::ostream& os, const ElementData& element) -> std::ostream&
{
    os
    << element.symbol << " "
    << element.name << " "
    << element.atomic_number << " "
    << element.atomic_weight << " "
    << element.electronegativity;
    return os;
}

} // namespace Atomik
