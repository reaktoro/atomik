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
namespace internal {

/// An alias type for the complex variant type used in Parameters class.
using Node = std::variant<double, std::vector<double>, std::unordered_map<std::string, std::any>>;

/// Return the children parameter nodes of a parameter node.
template <typename ParametersData>
auto children(ParametersData&& data)
{
    error(data.index() == 0, "Cannot access children parameter nodes when the current node holds a numeric value (= ", std::get<0>(data), ").");
    error(data.index() == 1, "Cannot access children parameter nodes when the current node holds numeric values.");
    return std::get<1>(std::forward<ParametersData>(data));
}

/// Return the children parameter nodes of a parameter node.
auto child(Node& data, const std::string& key) -> std::any&
{
    // error(data.index() == 0, "Cannot access child parameter with name `", key, "` when the current node holds a numeric value (= ", std::get<0>(data), ").");
    // error(data.index() == 1, "Cannot access child parameter with name `", key, "` when the current node holds numeric values.");
    error(std::get<2>(data).count(key) == 0, "Cannot access child parameter with name `", key, "`, which has not yet been inserted.");
    return std::get<2>(data)[key];
}

/// Return the children parameter nodes of a parameter node.
auto child(const Node& data, const std::string& key) -> const std::any&
{
    error(data.index() == 0, "Cannot access child parameter with name `", key, "` when the current node holds a numeric value (= ", std::get<0>(data), ").");
    error(data.index() == 1, "Cannot access child parameter with name `", key, "` when the current node holds numeric values.");
    error(std::get<2>(data).count(key) == 0, "Cannot access child parameter with name `", key, "`, which has not yet been inserted.");
    return std::get<2>(data).at(key);
}

/// Return the numeric value of a parameter node.
template <typename ParametersData>
auto value(ParametersData&& data) -> decltype(auto)
{
    // error(data.index() == 2, "Cannot retrieve the numeric value of a parameter node with children parameter nodes.");
    // return std::get<0>(std::forward<ParametersData>(data));
    return std::get<0>(data);
}

/// Return the numeric values of a parameter node.
template <typename ParametersData>
auto values(ParametersData&& data) -> decltype(auto)
{
    error(data.index() == 0, "Cannot retrieve the numeric values of a parameter node that has only one numeric value. Use Parameters::value() instead.");
    error(data.index() == 2, "Cannot retrieve the numeric values of a parameter node that has children parameter nodes.");
    return std::get<1>(std::forward<ParametersData>(data));
}

} // namespace internal

Parameters::Parameters()
: data(0.0)
{}

auto Parameters::operator=(double value) -> Parameters&
{
    // error(data.index() == 2,
    //     "Cannot overwrite current parameter node with a "
    //     "numeric value, as this would destroy its "
    //     "children parameter nodes.");

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

// auto Parameters::begin() const
// {
//     return internal::children(data).begin();
// }

// auto Parameters::begin()
// {
//     return internal::children(data).begin();
// }

// auto Parameters::end() const
// {
//     return internal::children(data).end();
// }

// auto Parameters::end()
// {
//     return internal::children(data).end();
// }

} // namespace Atomik
