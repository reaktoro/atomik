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

auto Parameters::set(const std::string& name) -> ParamValue&
{
    auto [iter, success] = index.insert({ name, index.size() });

    return success ? ( values.push_back(0.0), values.back() ) : values[iter->second];
}

auto Parameters::get(const std::string& name) -> ParamValue&
{
    auto iter = index.find(name);
    error(iter != index.end(), "There is no parameter with name `", name, "`.");
    return  values[iter->second];
}


/**
namespace internal {

/// An alias type for the complex variant type used in Parameters class.
using Node = std::variant<double, std::vector<double>, std::unordered_map<std::string, std::any>>;

/// Return the children parameter nodes of a parameter node.
template <typename ParametersData>
auto children(ParametersData&& data)
{
    error(data.index() == 0,
        "Cannot access children parameter nodes "
        "when the current node holds a numeric value.");
    error(data.index() == 1,
        "Cannot access children parameter nodes "
        "when the current node holds numeric values.");
    return std::get<1>(std::forward<ParametersData>(data));
}

/// Return the children parameter nodes of a parameter node.
template <typename ParameterData>
auto child(ParameterData&& data, const std::string& key) -> decltype(auto)
{
    error(data.index() == 0,
        "Cannot access child parameter with name `", key, "` "
        "when the current node holds a numeric value.");
    error(data.index() == 1,
        "Cannot access child parameter with name `", key, "` "
        "when the current node holds numeric values.");
    error(std::get<2>(data).count(key) == 0,
        "Cannot access child parameter with name `", key, "`, "
        "which has not yet been inserted.");
    return std::get<2>(data).at(key);
}

/// Return the numeric value of a parameter node.
template <typename ParametersData>
auto value(ParametersData&& data) -> decltype(auto)
{
    error(data.index() == 1,
        "Cannot retrieve the numeric value of "
        "a parameter node with a vector of values. "
        "Use method Parameters::values() instead.");
    error(data.index() == 2,
        "Cannot retrieve the numeric value of "
        "a parameter node with children parameter nodes.");
    return std::get<0>(data);
}

/// Return the numeric values of a parameter node.
template <typename ParametersData>
auto values(ParametersData&& data) -> decltype(auto)
{
    error(data.index() == 0,
        "Cannot retrieve the numeric values of "
        "a parameter node that has only one numeric value. "
        "Use method Parameters::value() instead.");
    error(data.index() == 2,
        "Cannot retrieve the numeric values of "
        "a parameter node that has children parameter nodes.");
    return std::get<1>(data);
}

} // namespace internal

Parameters::Parameters()
: data(0.0)
{}

auto Parameters::operator=(double value) -> Parameters&
{
    error(data.index() == 2,
        "Cannot overwrite current parameter node with a "
        "numeric value, as this would destroy its "
        "children parameter nodes.");
    data = value;
    return *this;
}

auto Parameters::operator=(std::vector<double> values) -> Parameters&
{
    error(data.index() == 2,
        "Cannot overwrite current parameter node with a "
        "numeric value, as this would destroy its "
        "children parameter nodes.");
    data = std::move(values);
    return *this;
}

auto Parameters::insert(const std::string& key) -> Parameters&
{
    if(data.index() != 2)
        data = std::unordered_map<std::string, std::any>();

    auto [iter, success] = std::get<2>(data).insert({key, Parameters()});

    return std::any_cast<Parameters&>(iter->second);
}

auto Parameters::operator[](const std::string& key) -> Parameters&
{
    return std::any_cast<Parameters&>(internal::child(data, key));
}

auto Parameters::operator[](const std::string& key) const -> const Parameters&
{
    return std::any_cast<const Parameters&>(internal::child(data, key));
}

auto Parameters::operator[](const char* key) -> Parameters&
{
    return std::any_cast<Parameters&>(internal::child(data, key));
}

auto Parameters::operator[](const char* key) const -> const Parameters&
{
    return std::any_cast<const Parameters&>(internal::child(data, key));
}

auto Parameters::get(const std::string& key) -> Parameters&
{
    return std::any_cast<Parameters&>(internal::child(data, key));
}

auto Parameters::get(const std::string& key) const -> const Parameters&
{
    return std::any_cast<const Parameters&>(internal::child(data, key));
}

auto Parameters::value() -> double&
{
    return internal::value(data);
}

auto Parameters::value() const -> const double&
{
    return internal::value(data);
}

auto Parameters::values() -> std::vector<double>&
{
    return internal::values(data);
}

auto Parameters::values() const -> const std::vector<double>&
{
    return internal::values(data);
}

Parameters::operator double& ()
{
    return value();
}

Parameters::operator const double& () const
{
    return value();
}

Parameters::operator std::vector<double>& ()
{
    return values();
}

Parameters::operator const std::vector<double>& () const
{
    return values();
}

//*/

} // namespace Atomik
