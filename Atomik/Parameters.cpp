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

#include "Parameters.hpp"

// Atomik includes
#include <Atomik/Exception.hpp>

namespace Atomik {

ParamValue::ParamValue()
: val(0.0)
{}

ParamValue::ParamValue(double value)
: val(value)
{}

ParamValue::ParamValue(std::vector<double> values)
: val(std::move(values))
{}

auto ParamValue::operator=(double value) -> ParamValue&
{
    val = value;
    return *this;
}

auto ParamValue::operator=(std::vector<double> values) -> ParamValue&
{
    val = std::move(values);
    return *this;
}

auto ParamValue::value() -> double&
{
    error(val.index() == 1, "This parameter consists comprises an array of numeric values, not a single value.");
    return std::get<0>(val);
}

auto ParamValue::value() const -> const double&
{
    error(val.index() == 1, "This parameter consists comprises an array of numeric values, not a single value.");
    return std::get<0>(val);
}

auto ParamValue::values() -> std::vector<double>&
{
    error(val.index() == 0, "This parameter consists of a single numeric value, not an array of values.");
    return std::get<1>(val);
}

auto ParamValue::values() const -> const std::vector<double>&
{
    error(val.index() == 0, "This parameter consists of a single numeric value, not an array of values.");
    return std::get<1>(val);
}

auto ParamValue::size() const -> std::size_t
{
    return values().size();
}

auto ParamValue::operator[](Index index) const -> const double&
{
    return values()[index];
}

auto ParamValue::operator[](Index index) -> double&
{
    return values()[index];
}

ParamValue::operator double& ()
{
    return value();
}

ParamValue::operator const double& () const
{
    return value();
}

ParamValue::operator std::vector<double>& ()
{
    return values();
}

ParamValue::operator const std::vector<double>& () const
{
    return values();
}

Parameters::Parameters()
{}

auto Parameters::set(const std::string& name) -> ParamValue&
{
    auto [iter, success] = index.insert({ name, index.size() });

    return success ? ( values.push_back(0.0), values.back() ) : values[iter->second];
}

auto Parameters::get(const std::string& name) -> ParamValue&
{
    auto iter = index.find(name);
    error(iter == index.end(), "There is no parameter with name `", name, "`.");
    return  values[iter->second];
}

} // namespace Atomik
