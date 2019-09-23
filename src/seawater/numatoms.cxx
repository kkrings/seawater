/**
 *
 * Implementation of NumAtoms class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file numatoms.cxx
 * @date 2019-05-28
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include "seawater/numatoms.h"

#include <sstream>
#include <stdexcept>

#include "seawater/massfraction.h"

seawater::NumAtoms::NumAtoms(int value)
    : value_{value}
{
    if (value_ < GetMin())
    {
        std::ostringstream message;

        message << "The given number of atoms of "
                << value_
                << " is smaller than the mininum allowed value of "
                << GetMin()
                << ".";

        throw std::invalid_argument(message.str());
    }
}

double seawater::GetWeight(const seawater::Molecule& molecule)
{
    double weight = 0.;

    for (const auto& atom : molecule)
    {
        weight += atom.second.GetValue() * atom.first.GetWeight();
    }

    return weight;
}

seawater::MassFractions seawater::GetMassFractions(
    const seawater::Molecule& molecule)
{
    double weight = GetWeight(molecule);

    MassFractions fractions;
    for (const auto& atom : molecule)
    {
        fractions.emplace(
            atom.first,
            atom.second.GetValue() * atom.first.GetWeight() / weight);
    }

    return fractions;
}
