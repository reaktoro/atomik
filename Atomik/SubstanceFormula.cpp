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

#include "SubstanceFormula.hpp"

// Atomik includes
#include <Atomik/Algorithms.hpp>
#include <Atomik/ChemicalFormula.hpp>
#include <Atomik/Exception.hpp>

namespace Atomik {

struct SubstanceFormula::Impl
{
    /// The chemical formula of the substance.
    std::string formula;

    /// The element symbols and their coefficients in the substance, e.g., {{"H", 2}, {"O", 1}} for `H2O`.
    std::unordered_map<std::string, double> elements;

    /// The element symbols in the chemical formula.
    std::vector<std::string> symbols;

    /// The coefficients of the element symbols in the chemical formula.
    std::vector<double> coefficients;

    /// Construct an object of type Impl.
    Impl()
    {
    }

    /// Construct an object of type Impl with given data.
    Impl(const Args& args)
    : formula(args.formula), elements(args.elements)
    {
        // Ensure formula is not empty.
        error(formula.empty(), "Data member SubstanceFormula::Data::formula cannot be empty.");

        // Ensure elements are not left empty - parse the chemical formula to initialize it if needed
        if(elements.empty())
            elements = parseChemicalFormula(formula);

        // Initialize symbols and coefficients
        symbols.reserve(elements.size());
        coefficients.reserve(elements.size());
        for(const auto& [symbol, coeff] : elements)
        {
            symbols.push_back(symbol);
            coefficients.push_back(coeff);
        }
    }
};

SubstanceFormula::SubstanceFormula()
: pimpl(new Impl())
{}

SubstanceFormula::SubstanceFormula(const std::string& formula)
: SubstanceFormula({ formula })
{
}

SubstanceFormula::SubstanceFormula(const Args& args)
: pimpl(new Impl(args))
{
}

auto SubstanceFormula::formula() const -> const std::string&
{
    return pimpl->formula;
}

auto SubstanceFormula::elements() const -> const std::unordered_map<std::string, double>&
{
    return pimpl->elements;
}

auto SubstanceFormula::symbols() const -> const std::vector<std::string>&
{
    return pimpl->symbols;
}

auto SubstanceFormula::coefficients() const -> const std::vector<double>&
{
    return pimpl->coefficients;
}

auto SubstanceFormula::coefficient(const std::string& symbol) const -> double
{
    const auto i = elements().find(symbol);
    return i != elements().end() ? i->second : 0.0;
}

auto SubstanceFormula::charge() const -> double
{
    return coefficient("Z");
}

auto SubstanceFormula::equivalent(const SubstanceFormula& other) const -> bool
{
    return elements() == other.elements();
}

SubstanceFormula::operator std::string() const
{
    return formula();
}

auto operator<(const SubstanceFormula& lhs, const SubstanceFormula& rhs) -> bool
{
    return lhs.formula() < rhs.formula();
}

auto operator==(const SubstanceFormula& lhs, const SubstanceFormula& rhs) -> bool
{
    return lhs.formula() == rhs.formula() && lhs.elements() == rhs.elements();
}

auto equivalent(const SubstanceFormula& lhs, const SubstanceFormula& rhs) -> bool
{
    return lhs.equivalent(rhs);
}

} // namespace Atomik
