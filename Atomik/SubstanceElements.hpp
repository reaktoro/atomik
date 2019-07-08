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

// Atomik includes
#include <Atomik/Elements.hpp>

namespace Atomik {

/// A type used to represent the elements in a chemical substance.
class SubstanceElements
{
public:
    /// Auxiliary type for the data of an object ot type SubstanceElements.
    struct Args
    {
        /// The elements that compose the substance.
        const Elements& elements;

        /// The oxidation states of the elements in the substance.
        const std::vector<double>& coefficients;

        /// The oxidation states of the elements in the substance.
        const std::vector<double>& oxidationStates;
    };

    /// Construct a default SubstanceElements object.
    SubstanceElements();

    /// Construct a SubstanceElements object with given arguments.
    SubstanceElements(const Args& args);

    /// Return the elements in the substance.
    auto elements() const -> const Elements&;

    /// Return the symbols of the elements in the substance.
    auto symbols() const -> const std::vector<std::string>&;

    /// Return the coefficients of the elements in the substance.
    auto coefficients() const -> const std::vector<double>&;

    /// Return the oxidation states of the elements in the substance.
    auto oxidationStates() const -> const std::vector<double>&;

    /// Return the molar mass of the substance (in unit of kg/mol).
    auto molarMass() const -> double;

private:
    struct Impl;

    std::shared_ptr<Impl> pimpl;
};

/// Return an iterator to the begin of the elements container.
auto begin(const SubstanceElements& elements) { return elements.elements().begin(); }

/// Return an iterator to the end of the elements container.
auto end(const SubstanceElements& elements) { return elements.elements().end(); }

} // namespace Atomik
