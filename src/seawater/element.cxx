/**
 *
 * Implementation of chemical element class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file element.cxx
 * @date 2019-04-24
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include "seawater/element.h"

#include <sstream>
#include <stdexcept>

void seawater::Element::CheckParameters()
{
    if (charge_ < GetMinCharge())
    {
        std::ostringstream message;

        message << "The given atomic charge of "
                << charge_
                << " is not greater equal "
                << GetMinCharge()
                << ".";

        throw std::invalid_argument(message.str());
    }

    if (weight_ < GetMinWeight())
    {
        std::ostringstream message;

        message << "The given atomic weight of "
                << weight_
                << " is not greater equal "
                << GetMinWeight()
                << ".";

        throw std::invalid_argument(message.str());
    }
}
