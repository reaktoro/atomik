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


namespace Atomik {

/// A type used to store thermodynamic and chemical model parameters.
class Parameters
{
private:
    /// Construct a default Parameters object.
    Parameters();

    /// Assign a value to this Parameters object.
    /// @throws std::runtime_error In case this Parameters object has children parameters.
    auto operator=(double value) -> Parameters&;

    /// Return the child Parameters object with a given key.
    auto operator[](const std::string& key) -> Parameters&;

    /// Return the child Parameters object with a given key.
    auto operator[](const std::string& key) const -> const Parameters&;

    /// Return the child Parameters object with a given key.
    /// @throw std::runtime_error In case no parameters with given key exist.
    auto get(const std::string& key) -> Parameters&;

    /// Return the child Parameters object with a given key.
    /// @throw std::runtime_error In case no parameters with given key exist.
    auto get(const std::string& key) const -> const Parameters&;

    /// Return the numeric value of this Parameters object.
    /// @throw std::runtime_error In case this Parameters object has children parameters.
    auto value() -> double&;

    /// Return the numeric value of this Parameters object.
    /// @throw std::runtime_error In case this Parameters object has children parameters.
    auto value() const -> const double&;

    /// Return the numeric value of a child parameter with given name.
    auto value(const std::string& name) -> double&;

    /// Return the numeric value of a child parameter with given name.
    auto value(const std::string& name) const -> const double&;

    /// Return the numeric value of a descendant parameter with given path.
    auto value(const StringList& path) -> double&;

    /// Return the numeric value of a descendant parameter with given path.
    auto value(const StringList& path) const -> const double&;

    /// Return (implicitly) the value of this Parameters object.
    /// @throw std::runtime_error In case this Parameters object has children parameters.
    operator double& ();

    /// Return (implicitly) the value of this Parameters object.
    /// @throw std::runtime_error In case this Parameters object has children parameters.
    operator const double& () const;

    /// Return begin const iterator of this Parameters instance
    /// @throw std::runtime_error In case this Parameters object has no children parameters.
    inline auto begin() const;

    /// Return begin iterator of this Parameters instance
    /// @throw std::runtime_error In case this Parameters object has no children parameters.
    inline auto begin();

    /// Return end const iterator of this Parameters instance
    /// @throw std::runtime_error In case this Parameters object has no children parameters.
    inline auto end() const;

    /// Return end iterator of this Parameters instance
    /// @throw std::runtime_error In case this Parameters object has no children parameters.
    inline auto end();

public:
    /// The child parameters of this Parameters object
    std::variant<double, std::unordered_map<std::string, std::any>> data;
};

} // namespace Atomik
