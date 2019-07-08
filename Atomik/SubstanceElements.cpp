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

#include "SubstanceElements.hpp"

namespace Atomik {

struct SubstanceElements::Impl
{
    /// The elements that compose the substance.
    Elements elements;

    /// The oxidation states of the elements in the substance.
    std::vector<double> coefficients;

    /// The oxidation states of the elements in the substance.
    std::vector<double> oxidationStates;

    /// The symbols of the elements in the substance.
    std::vector<std::string> symbols;

    /// The molar mass of the substance (in unit of kg/mol).
    double molarMass;

    /// Construct a default SubstanceElements::Impl instance
    Impl()
    {}

    /// Construct a SubstanceElements::Impl instance
    Impl(const Args& args)
    : elements(args.elements),
      coefficients(args.coefficients),
      oxidationStates(args.oxidationStates)
    {
        /// Collect the symbols of the elements
        for(auto&& element : elements)
            symbols.push_back(element.symbol());

        // Calculate the molar mass of the substance
        molarMass = 0.0;
        for(auto i = 0u; i < elements.size(); ++i)
            molarMass += coefficients[i] * elements[i].molarMass();
    }
};

SubstanceElements::SubstanceElements()
: pimpl(new Impl())
{}

SubstanceElements::SubstanceElements(const Args& args)
: pimpl(new Impl(args))
{}

auto SubstanceElements::elements() const -> const Elements&
{
    return pimpl->elements;
}

auto SubstanceElements::symbols() const -> const std::vector<std::string>&
{
    return pimpl->symbols;
}

auto SubstanceElements::coefficients() const -> const std::vector<double>&
{
    return pimpl->coefficients;
}

auto SubstanceElements::oxidationStates() const -> const std::vector<double>&
{
    return pimpl->oxidationStates;
}

auto SubstanceElements::molarMass() const -> double
{
    return pimpl->molarMass;
}

} // namespace Atomik
