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
#include <string>
#include <vector>

// Atomik includes
#include <Atomik/Substance.hpp>

namespace Atomik {

// Forward declarations
class StringList;

/// A type used as a collection of chemical substances.
class Substances
{
public:
    /// Construct a default Substances object.
    Substances();

    /// Construct an Substances object with given data.
    explicit Substances(std::vector<Substance> substances);

    /// Return the internal collection of Substance objects.
    auto data() const -> const std::vector<Substance>&;

    /// Return the number of chemical substances in the collection.
    auto size() const -> std::size_t;

    /// Return the Substance object with given index.
    auto operator[](std::size_t index) const -> const Substance&;

    /// Return the index of the first chemical substance with given name.
    /// If there is no chemical substance with given name, return number of substances.
    auto indexWithName(std::string name) const -> std::size_t;

    /// Return the index of the first chemical substance with given formula.
    /// If there is no chemical substance with given formula, return number of substances.
    auto indexWithFormula(std::string formula) const -> std::size_t;

    /// Return the first chemical substance with given name.
    /// @throw std::runtime_error When there is no substance with given name.
    auto getWithName(std::string name) const -> Substance;

    /// Return the first chemical substance with given formula.
    /// @throw std::runtime_error When there is no substance with given formula.
    auto getWithFormula(std::string formula) const -> Substance;

    /// Return the chemical substances with given names.
    auto withNames(const StringList& names) const -> Substances;

    /// Return the chemical substances with given formulas.
    auto withFormulas(const StringList& names) const -> Substances;

    /// Return the chemical substances with given type.
    auto withType(std::string type) const -> Substances;

    /// Return the chemical substances with a given tag.
    auto withTag(std::string tag) const -> Substances;

    /// Return the chemical substances without a given tag.
    auto withoutTag(std::string tag) const -> Substances;

    /// Return the chemical substances with given tags.
    auto withTags(const StringList& tags) const -> Substances;

    /// Return the chemical substances without given tags.
    auto withoutTags(const StringList& tags) const -> Substances;

    /// Append a new substance to the list of substances.
    auto append(Substance substance) -> void;

    /// Return begin const iterator of this Substances instance
    inline auto begin() const { return data().begin(); }

    /// Return begin iterator of this Substances instance
    inline auto begin() { return data().begin(); }

    /// Return end const iterator of this Substances instance
    inline auto end() const { return data().end(); }

    /// Return end iterator of this Substances instance
    inline auto end() { return data().end(); }

    /// Return all chemical substances from the periodic table.
    static auto PeriodicTable() -> Substances;

private:
    /// The chemical substances stored in the database.
    std::vector<Substance> m_substances;
};

} // namespace Atomik
