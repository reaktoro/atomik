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

#pragma once

// C++ includes
#include <any>
#include <string>
#include <unordered_map>
#include <variant>

// Atomik includes
#include <Atomik/StringList.hpp>


// // Scenario 1: existing nodes
// parameters["HKF"]["CO2(aq)"]["Gf"] = 1.0;

// parameters["HKF CO2(aq) Gf"] = 1.0;


// double& val = parameters["HKF"]["CO2(aq)"]["Gf"];

// // Scenario 2: inserting nodes
// parameters.insert("HKF").insert("CO2(aq)").insert("Gf") = 1.0;

// parameters.insert("HKF CO2(aq) Gf") = 1.0;
// parameters.value("hkf", "CO2(aq)", "Gf")
// parameters.get("a", "b")


namespace Atomik {

/// A type used to store thermodynamic and chemical model parameters.
class Parameters
{
public:
    /// Construct a default Parameters object.
    Parameters();

    /// Insert a new parameter child node with given key.
    auto insert(const std::string& key) -> Parameters&;

    /// Assign a value to this Parameters object.
    /// @throws std::runtime_error In case this Parameters object has children parameters.
    auto operator=(double value) -> Parameters&;

    /// Assign a vector of values to this Parameters object.
    /// @throws std::runtime_error In case this Parameters object has children parameters.
    auto operator=(std::vector<double> values) -> Parameters&;

    /// Return the child Parameters object with a given key.
    /// @throw std::runtime_error In case this Parameters object has no children parameters or no child with given key.
    auto operator[](const std::string& key) -> Parameters&;

    /// Return the child Parameters object with a given key.
    /// @throw std::runtime_error In case this Parameters object has no children parameters or no child with given key.
    auto operator[](const std::string& key) const -> const Parameters&;

    /// Return the child Parameters object with a given key.
    /// @throw std::runtime_error In case this Parameters object has no children parameters or no child with given key.
    auto operator[](const char* key) -> Parameters&;

    /// Return the child Parameters object with a given key.
    /// @throw std::runtime_error In case this Parameters object has no children parameters or no child with given key.
    auto operator[](const char* key) const -> const Parameters&;

    /// Return the child Parameters object with a given key.
    /// @throw std::runtime_error In case this Parameters object has no children parameters or no child with given key.
    auto get(const std::string& key) -> Parameters&;

    /// Return the child Parameters object with a given key.
    /// @throw std::runtime_error In case this Parameters object has no children parameters or no child with given key.
    auto get(const std::string& key) const -> const Parameters&;

    /// Return the numeric value of this Parameters object.
    /// @throw std::runtime_error In case this Parameters object has children parameters.
    auto value() -> double&;

    /// Return the numeric value of this Parameters object.
    /// @throw std::runtime_error In case this Parameters object has children parameters.
    auto value() const -> const double&;

    /// Return the numeric values of this Parameters object.
    /// @throw std::runtime_error In case this Parameters object has children parameters.
    auto values() -> std::vector<double>&;

    /// Return the numeric values of this Parameters object.
    /// @throw std::runtime_error In case this Parameters object has children parameters.
    auto values() const -> const std::vector<double>&;

    /// Return (implicitly) the value of this Parameters object.
    /// @throw std::runtime_error In case this Parameters object has children parameters.
    operator double& ();

    /// Return (implicitly) the value of this Parameters object.
    /// @throw std::runtime_error In case this Parameters object has children parameters.
    operator const double& () const;

    /// Return (implicitly) the values of this Parameters object.
    /// @throw std::runtime_error In case this Parameters object has children parameters.
    operator std::vector<double>& ();

    /// Return (implicitly) the values of this Parameters object.
    /// @throw std::runtime_error In case this Parameters object has children parameters.
    operator const std::vector<double>& () const;

private:
    /// The child parameters of this Parameters object
    std::variant<double, std::vector<double>,
        std::unordered_map<std::string, std::any>> data;
};

} // namespace Atomik
