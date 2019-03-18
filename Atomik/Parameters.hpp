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
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

// Atomik includes
#include <Atomik/Index.hpp>
#include <Atomik/StringUtils.hpp>

namespace Atomik {

/// A type used to represent the possible value types of a parameter.
/// A parameter value can be of type `double` or `vector<double>` and this class
/// provides some convenience in dealing with these possibilities.
class ParamValue
{
public:
    /// Construct an object of type ParamValue with a default value of zero.
    ParamValue();

    /// Construct an object of type ParamValue with a given value.
    ParamValue(double value);

    /// Construct an object of type ParamValue with a given array of values.
    ParamValue(std::vector<double> values);

    /// Assign a value to this ParamValue object.
    /// @throws std::runtime_error In case this ParamValue object currently represents multiple values.
    auto operator=(double value) -> ParamValue&;

    /// Assign a vector of values to this ParamValue object.
    /// @throws std::runtime_error In case this ParamValue object currently represents a single value.
    auto operator=(std::vector<double> values) -> ParamValue&;

    /// Return the numeric value of this ParamValue object.
    /// @throw std::runtime_error In case this ParamValue object currently represents multiple values.
    auto value() -> double&;

    /// Return the numeric value of this ParamValue object.
    /// @throw std::runtime_error In case this ParamValue object currently represents multiple values.
    auto value() const -> const double&;

    /// Return the numeric values of this ParamValue object.
    /// @throw std::runtime_error In case this ParamValue object currently represents a single value.
    auto values() -> std::vector<double>&;

    /// Return the numeric values of this ParamValue object.
    /// @throw std::runtime_error In case this ParamValue object currently represents a single value.
    auto values() const -> const std::vector<double>&;

    /// Return the number of numeric values in this parameter.
    auto size() const -> std::size_t;

    /// Return the numeric value with a given index.
    /// @throw std::runtime_error In case this ParamValue object currently represents a single value.
    auto operator[](Index index) const -> const double&;

    /// Return the numeric value with a given index.
    /// @throw std::runtime_error In case this ParamValue object currently represents a single value.
    auto operator[](Index index) -> double&;

    /// Return (implicitly) the value of this ParamValue object.
    /// @throw std::runtime_error In case this ParamValue object currently represents multiple values.
    operator double& ();

    /// Return (implicitly) the value of this ParamValue object.
    /// @throw std::runtime_error In case this ParamValue object currently represents multiple values.
    operator const double& () const;

    /// Return (implicitly) the values of this ParamValue object.
    /// @throw std::runtime_error In case this ParamValue object currently represents a single value.
    operator std::vector<double>& ();

    /// Return (implicitly) the values of this ParamValue object.
    /// @throw std::runtime_error In case this ParamValue object currently represents a single value.
    operator const std::vector<double>& () const;

private:
    /// The type of a parameter value (either a single number, or a vector of numbers)
    std::variant<double, std::vector<double>> val;
};

/// A type used to manage a collection of model parameters.
/// This class can be used to conveniently store and modify parameters
/// of all  thermodynamic models in an application.
/// Below is an example of its usage:
/// ~~~
/// using namespace Atomik;

/// Parameters parameters;
/// parameters.set("SomeModel", "a") = 1.0;
/// parameters.set("SomeModel", "b") = { 1.0, 2.0, 3.0 };
///
/// cout << parameters.get("SomeModel", "a") << endl;
/// cout << parameters.get("SomeModel", "b")[0] << endl;
/// cout << parameters.get("SomeModel", "b")[1] << endl;
/// cout << parameters.get("SomeModel", "b")[2] << endl;
/// ~~~
class Parameters
{
public:
    /// Construct a default Parameters object.
    Parameters();

    /// Set a new parameter with given name.
    auto set(const std::string& name) -> ParamValue&;

    /// Set a new parameter with given subnames.
    template <typename... Args>
    auto set(const std::string& first, const Args&... others) -> ParamValue& { return set(stringfy(".", first, others...)); }

    /// Return a parameter with given name.
    auto get(const std::string& name) -> ParamValue&;

    /// Return a parameter with given subnames.
    template <typename... Args>
    auto get(const std::string& first, const Args&... others) -> ParamValue& { return get(stringfy(".", first, others...)); }

private:
    /// The values of the parameters.
    std::vector<ParamValue> values;

    /// The mapping from parameters names to their indices.
    std::unordered_map<std::string, Index> index;
};

} // namespace Atomik
