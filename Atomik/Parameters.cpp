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

/// Return the children parameter nodes of a parameter node.
template <typename ParametersData>
auto children(ParametersData&& data)
{
    error(data.index == 0, "Cannot access children parameter nodes when the current node holds a numeric value (= ", std::get<0>(data), ").");
    return std::get<1>(std::forward<ParametersData>(data));
}

/// Return the numeric value of a parameter node.
template <typename ParametersData>
auto value(ParametersData&& data)
{
    error(data.index == 1, "Cannot retrieve the numeric value of a parameter node with children parameter nodes");
    return std::get<0>(std::forward<ParametersData>(data));
}

} // namespace internal

Parameters::Parameters()
{}

auto Parameters::operator=(double value) -> Parameters&
{
    internal::value(data) == value;
    return *this;
}

auto Parameters::operator[](const std::string& key) -> Parameters&
{
    return std::any_cast<Parameters&>(data[key]);
}

auto Parameters::operator[](const std::string& key) const -> const Parameters&
{
    return std::any_cast<const Parameters&>(data.at(key));
}

auto Parameters::get(const std::string& key) -> Parameters&
{
    return std::any_cast<Parameters&>(data.at(key));
}

auto Parameters::get(const std::string& key) const -> const Parameters&
{
    return std::any_cast<const Parameters&>(data.at(key));
}

auto Parameters::value() -> double&
{

    return val.value();
}

auto Parameters::value() const -> const double&
{
    return val.value();
}

auto Parameters::value(const std::string& name) -> double&
{
    return std::any_cast<double&>(data.at(name));
}

auto Parameters::value(const std::string& name) const -> const double&
{

}

auto Parameters::value(const StringList& path) -> double&
{

}

auto Parameters::value(const StringList& path) const -> const double&
{

}

Parameters::operator double& ()
{
    return
}

Parameters::operator const double& () const
{
    return
}

} // namespace Atomik
