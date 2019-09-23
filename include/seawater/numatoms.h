/**
 *
 * Definition of NumAtoms class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file numatoms.h
 * @date 2019-05-28
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#pragma once

#include <map>

#include "seawater/element.h"
#include "seawater/massfraction.h"

namespace seawater {

//---Number of atoms-----------------------------------------------------------

/**
 * @brief Number of atoms
 *
 * This class represents the number atoms of a chemical element within a
 * molecule.
 */
class NumAtoms
{
    public:
        /**
         * @brief Minimum number of atoms
         *
         * The minimum allowed number of atoms is equal to 1.
         *
         * @return
         *     Minimum number of atoms
         */
        static constexpr int GetMin()
        {
            return 1;
        }

        /**
         * Construct new number of atoms.
         *
         * @param[in] value
         *     Number of atoms
         */
        NumAtoms(int value = 1);

        /// This class uses the default copy constructor.
        NumAtoms(const NumAtoms&) = default;
        /// This class uses the default move constructor.
        NumAtoms(NumAtoms&&) = default;

        /// This class uses the default copy assign operator.
        NumAtoms& operator=(const NumAtoms&) = default;
        /// This class uses the default move assign operator.
        NumAtoms& operator=(NumAtoms&&) = default;

        /// This class uses the default destructor.
        ~NumAtoms() = default;

        /**
         * Access number of atoms
         *
         * @return
         *     Number of atoms
         */
        int GetValue() const
        {
            return value_;
        }

    private:
        /// Number of atoms
        int value_;
};

//---Molecule------------------------------------------------------------------

/// A molecule is represented by an element to number of atoms map.
using Molecule = std::map<Element, NumAtoms>;

/**
 * @brief Atomic weight
 *
 * Calculate the atomic weight of the given molecule.
 *
 * @param[in] molecule
 *     Molecule
 *
 * @return
 *     Atomic weight
 */
double GetWeight(const Molecule& molecule);

/**
 * @brief Element mass fractions
 *
 * Transform the given molecule into an element to mass fraction map.
 *
 * @param[in] molecule
 *    Molecule
 *
 * @return
 *    Element to mass fraction map
 */
MassFractions GetMassFractions(const Molecule& molecule);

/**
 * @brief Multiplication of scale and molecule.
 *
 * Transform the given molecule into an element to mass fraction map and
 * multiply the later with the given scale.
 */
inline MassFractions operator*(double scale, const Molecule& molecule)
{
    return scale * GetMassFractions(molecule);
}

} // namespace seawater
