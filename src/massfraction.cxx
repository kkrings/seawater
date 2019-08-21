/**
 *
 * Implementation of MassFraction class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file massfraction.cxx
 * @date 2019-05-28
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include "seawater/massfraction.h"

#include <sstream>
#include <stdexcept>

void seawater::MassFraction::CheckValue()
{
    if (value_ <= GetMin() || value_ > GetMax())
    {
        std::ostringstream message;

        message << "The given mass fraction of "
                << value_
                << " is not within ("
                << GetMin()
                << ", "
                << GetMax()
                << "].";

        throw std::invalid_argument(message.str());
    }
}

seawater::MassFractions& seawater::operator+=(
    seawater::MassFractions& left,
    const seawater::MassFractions& right)
{
    for (const auto& fraction : right)
    {
        auto contained = left.find(fraction.first);

        if (contained != std::end(left))
        {
            contained->second += fraction.second;
        }
        else
        {
            left.insert(fraction);
        }
    }

    return left;
}

seawater::MassFractions& seawater::operator*=(
    seawater::MassFractions& fractions, double scale)
{
    for (auto& fraction : fractions)
    {
        fraction.second *= scale;
    }

    return fractions;
}
