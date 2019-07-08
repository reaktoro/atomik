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
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

namespace Atomik {

/// A type used to represent the chemical formula of a substance.
class SubstanceFormula
{
public:
    /// A type used to represent the data needed to construct a SubstanceFormula object.
    struct Args
    {
        /// The chemical formula of the substance.
        const std::string& formula;

        /// The element symbols and their coefficients in the substance, e.g., {{"H", 2}, {"O", 1}} for `H2O`.
        const std::unordered_map<std::string, double>& elements;
    };

    /// Construct a default SubstanceFormula object.
    SubstanceFormula();

    /// Construct a SubstanceFormula object with given formula.
    SubstanceFormula(const std::string& formula);

    /// Construct a SubstanceFormula object with given data.
    SubstanceFormula(const Args& args);

    /// Return the chemical formula of the substance.
    auto formula() const -> const std::string&;

    /// Return element symbols and their coefficients in the substance.
    auto elements() const -> const std::unordered_map<std::string, double>&;

    /// Return the element symbols in the chemical formula.
    auto symbols() const -> const std::vector<std::string>&;

    /// Return the coefficients of the element symbols in the chemical formula.
    auto coefficients() const -> const std::vector<double>&;

    /// Return the coefficient of an element in the chemical formula.
    /// @param symbol The symbol of the element.
    auto coefficient(const std::string& symbol) const -> double;

    /// Return the electric charge of the chemical formula.
    auto charge() const -> double;

    /// Return true if another chemical formula is equivalent to this one.
    /// Equivalency is defined as two formulas with the same elemental composition.
    /// For example, `Ca++` and `Ca+2`; and `CaCO3` and `Ca(CO3)`.
    auto equivalent(const SubstanceFormula& other) const -> bool;

    /// Convert this SubstanceFormula object into a string.
    operator std::string() const;

private:
    struct Impl;

    std::shared_ptr<Impl> pimpl;
};

/// Compare two SubstanceFormula objects for less than
auto operator<(const SubstanceFormula& lhs, const SubstanceFormula& rhs) -> bool;

/// Compare two SubstanceFormula objects for equality
auto operator==(const SubstanceFormula& lhs, const SubstanceFormula& rhs) -> bool;

} // namespace Atomik
