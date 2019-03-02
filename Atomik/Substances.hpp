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

    /// Construct an Substances object with given substances.
    explicit Substances(std::vector<Substance> substances);

    /// Construct an Substances object with given substance formulas.
    explicit Substances(StringList formulas);

    /// Append a new substance to the list of substances.
    auto append(Substance substance) -> void;

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

    /// Return the chemical substances with a given tag.
    auto withTag(std::string tag) const -> Substances;

    /// Return the chemical substances without a given tag.
    auto withoutTag(std::string tag) const -> Substances;

    /// Return the chemical substances with given tags.
    auto withTags(const StringList& tags) const -> Substances;

    /// Return the chemical substances without given tags.
    auto withoutTags(const StringList& tags) const -> Substances;

    /// Return the chemical substances with a certain elemental composition.
    /// This method filters the substances composed of one or more given elements, as shown below.
    /// ~~~
    /// using namespace Atomik;
    /// Substances substances("H2O H+ OH- H2 O2 Na+ Cl- NaCl CO2 HCO3- CO3-2 CH4");
    /// Substances subs1 = substances.withElements("H O");          // {H2O, H2, O2}
    /// Substances subs2 = substances.withElements("H O C");        // {H2O, H2, O2, CO2, CH4}
    /// Substances subs3 = substances.withElements("H O C Z");      // {H2O, H+, OH-, H2, O2, CO2, HCO3-, CO3-2, CH4}
    /// Substances subs4 = substances.withElements("H O Na Cl");    // {H2O, H2, O2, NaCl}
    /// Substances subs5 = substances.withElements("H O Na Cl Z");  // {H2O H+ OH- H2 O2 Na+ Cl- NaCl}
    /// ~~~
    /// @param symbols The element symbols of interest.
    /// @see Substance::withElementsOf
    auto withElements(const StringList& symbols) const -> Substances;

    /// Return the chemical substances with a certain elemental composition.
    /// This method extracts the elements from a given set of chemical formulas and
    /// then filters the substances composed of one or more such elements, as shown below.
    /// ~~~
    /// using namespace Atomik;
    /// Substances substances("H2O H+ OH- H2 O2 Na+ Cl- NaCl CO2 HCO3- CO3-2 CH4");
    /// Substances subs1 = substances.withElementsOf("H2O");         // {H2O, H2, O2}
    /// Substances subs2 = substances.withElementsOf("H2O CO2");     // {H2O, H2, O2, CO2, CH4}
    /// Substances subs3 = substances.withElementsOf("H2O CO2 Z");   // {H2O, H+, OH-, H2, O2, CO2, HCO3-, CO3-2, CH4}
    /// Substances subs4 = substances.withElementsOf("H2O NaCl");    // {H2O, H2, O2, NaCl}
    /// Substances subs5 = substances.withElementsOf("H2O Na+ Cl-"); // {H2O H+ OH- H2 O2 Na+ Cl- NaCl}
    /// ~~~
    /// @param formulas The formulas of the substances from which elements are extracted.
    /// @see Substance::withElements
    auto withElementsOf(const StringList& formulas) const -> Substances;

    /// Alias of method Substances::withTag.
    auto tagged(const std::string& tag) const -> Substances;

    /// Alias of method Substances::withoutTag.
    auto untagged(const std::string& tag) const -> Substances;

    /// Alias of method Substances::withElements.
    auto containing(const StringList& elements) const -> Substances;

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
