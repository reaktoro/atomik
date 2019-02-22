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

#include "ChemicalFormula.hpp"

// C++ includes
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <string>
#include <unordered_map>
using std::pair;
using std::string;
using std::unordered_map;

// Atomik includes
#include <Atomik/Utils.hpp>

namespace Atomik {
namespace internal {

auto parseElementAtom(string::iterator begin, string::iterator end) -> pair<string, string::iterator>
{
    if(!isupper(*begin))
        throw std::runtime_error("***Atomik Error*** The first character in a chemical formula must be in uppercase.");
    if(begin == end) return {"", begin};
    auto endelement = std::find_if(begin + 1, end, [](char c){return isupper(c) || !isalpha(c);});
    string element = string(begin, endelement);
    return {element, endelement};
}

auto parseNumAtoms(string::iterator begin, string::iterator end) -> pair<double, string::iterator>
{
    if(begin == end) return {1.0, begin};
    if(!(isdigit(*begin) || *begin == '.')) return {1.0, begin};
    auto endnumber = std::find_if(begin, end, [](char c){return !(isdigit(c) || c == '.');});
    double number = atof(string(begin, endnumber).c_str());
    return {number, endnumber};
}

auto findMatchedParenthesis(string::iterator begin, string::iterator end) -> string::iterator
{
    if(begin == end) return end;
    int level = 0;
    for(auto iter = begin+1; iter < end; ++iter)
    {
        level = (*iter == '(') ? level + 1 : level;
        level = (*iter == ')') ? level - 1 : level;
        if(*iter == ')' && level == -1)
            return iter;
    }
    return end;
}

auto parseFormula(string::iterator begin, string::iterator end, unordered_map<string, double>& result, double scalar) -> void
{
    if(begin == end) return;

    if(*begin != '(' && *begin != '.' && !isupper(*begin))
    {
        parseFormula(begin + 1, end, result, scalar);
    }
    else if(*begin == '(')
    {
        string::iterator begin1 = begin + 1;
        string::iterator end1   = findMatchedParenthesis(begin, end);

        auto res = parseNumAtoms(end1 + 1, end);

        const double number = res.first;

        string::iterator begin2 = res.second;
        string::iterator end2   = end;

        parseFormula(begin1, end1, result, scalar * number);
        parseFormula(begin2, end2, result, scalar);
    }
    else if(*begin == '.')
    {
        auto res = parseNumAtoms(begin + 1, end);

        const double number = res.first;

        string::iterator begin1 = res.second;
        string::iterator end1   = end;

        parseFormula(begin1, end1, result, scalar * number);
    }
    else
    {
        auto res1 = parseElementAtom(begin, end);
        auto res2 = parseNumAtoms(res1.second, end);

        string element = res1.first;
        double natoms  = res2.first;

        if(result.count(element)) result[element] += scalar * natoms;
        else result[element] = scalar * natoms;

        string::iterator begin1 = res2.second;
        string::iterator end1   = end;

        parseFormula(begin1, end1, result, scalar);
    }
}

auto parseChargeModeSignNumber(std::string formula) -> double
{
    std::size_t ipos = formula.find_last_of('+');
    std::size_t ineg = formula.find_last_of('-');
    std::size_t imin = std::min(ipos, ineg);

    if(imin == std::string::npos)
        return 0.0;

    int sign = (imin == ipos) ? +1 : -1;

    if(imin + 1 == formula.size())
        return sign;

    std::string digits = formula.substr(imin + 1);

    return sign * std::stod(digits);
}

auto parseChargeModeMultipleSigns(std::string formula) -> double
{
    const auto sign = formula.back();
    const auto signval = sign == '+' ? 1 : (sign == '-' ? -1 : 0);
    const auto ilast = formula.size() - 1;
    if(sign != 0)
    {
        auto i = 0;
        while(formula[ilast - i] == sign && i <= ilast)
            ++i;
        const auto charge = i * signval;
        return charge;
    }
    else return 0;
}

auto parseChargeModeNumberSign(std::string formula) -> double
{
    if(formula.back() != ')') return 0.0;

    std::size_t iparbegin = formula.rfind('(');

    if(iparbegin == std::string::npos) return 0.0;

    const auto isign = formula.size() - 2;
    const auto sign = formula[isign] == '+' ? +1.0 : formula[isign] == '-' ? -1.0 : 0.0;

    if(sign == 0.0) return 0.0;

    std::string digits(formula.begin() + iparbegin + 1, formula.end() - 2);

    if(digits.empty()) return sign;

    return sign * std::stod(digits);
}

auto parseCharge(std::string formula) -> double
{
    double charge;

    charge = parseChargeModeMultipleSigns(formula); if(charge != 0.0) return charge;
    charge = parseChargeModeNumberSign(formula); if(charge != 0.0) return charge;
    charge = parseChargeModeSignNumber(formula); if(charge != 0.0) return charge;

    return 0.0;
}

auto parseFormula(std::string formula) -> std::unordered_map<std::string, double>
{
    std::unordered_map<std::string, double> result;

    // Parse the formula for elements and their coefficients (without charge)
    parseFormula(formula.begin(), formula.end(), result, 1.0);

    // Get the charge of the formula
    auto charge = parseCharge(formula);

    // Check if the formula contains charge
    if(charge)
        result.insert({"Z", charge});

    return result;
}

} // namespace internal

ChemicalFormula::ChemicalFormula()
{}

ChemicalFormula::ChemicalFormula(const char* formula)
: m_formula(formula)
{
    // Initialize the element symbols and coefficients
    const auto pairs = internal::parseFormula(formula);
    m_elements.reserve(pairs.size());
    m_coefficients.resize(pairs.size());

    for(auto&& [symbol, coeff] : pairs)
    {
        m_coefficients[m_elements.size()] = coeff;
        m_elements.push_back(symbol);
    }

    // Initialize the charge of the formula
    m_charge = internal::parseCharge(formula);
}

ChemicalFormula::ChemicalFormula(std::string formula)
: ChemicalFormula(formula.c_str())
{}

auto ChemicalFormula::elements() const -> std::vector<std::string> const&
{
    return m_elements;
}

auto ChemicalFormula::coefficients() const -> std::valarray<double> const&
{
    return m_coefficients;
}

auto ChemicalFormula::charge() const -> double
{
    return m_charge;
}

auto ChemicalFormula::coefficient(std::string symbol) const -> double
{
    auto i = index(m_elements, symbol);
    return i < m_elements.size() ? m_coefficients[i] : 0.0;
}

auto ChemicalFormula::str() const -> std::string
{
    return m_formula;
}

ChemicalFormula::operator std::string() const
{
    return m_formula;
}

auto operator<(const ChemicalFormula& lhs, const ChemicalFormula& rhs) -> bool
{
    return lhs.str() < rhs.str();
}

auto operator==(const ChemicalFormula& lhs, const ChemicalFormula& rhs) -> bool
{
    return lhs.str() == rhs.str();
}

auto equivalent(const ChemicalFormula& lhs, const ChemicalFormula& rhs) -> bool
{
    return lhs.elements() == rhs.elements() && lhs.charge() == rhs.charge();
}

} // namespace Atomik
