/**
 * Implementation of Medium class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file medium.cxx
 * @date 2019-05-28
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include "seawater/medium.h"

#include <cmath>
#include <limits>
#include <sstream>
#include <stdexcept>

namespace {

void CheckTotalFraction(const seawater::MassFractions& fractions)
{
    double totalFraction = 0.;

    for (const auto& fraction : fractions)
    {
        totalFraction += fraction.second.GetValue();
    }

    auto epsilon = std::numeric_limits<double>::epsilon();

    if (std::fabs(totalFraction - 1.) > epsilon)
    {
        std::ostringstream message;

        message << "The total mass fraction of "
                << totalFraction
                << " is not equal to 1.";

        throw std::invalid_argument(message.str());
    }
}

} // namespace

seawater::Medium::Medium(
    const seawater::MassFractions& fractions, double density)
    : fractions_{fractions},
    density_{density}
{
    CheckTotalFraction(fractions);
}
