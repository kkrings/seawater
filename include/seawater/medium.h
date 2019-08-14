/**
 *
 * Definition of Medium class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file medium.h
 * @date 2019-05-12
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#pragma once

#include <map>
#include <sstream>
#include <stdexcept>

#include "massfraction.h"

namespace seawater {

/**
 * @brief Propagation medium
 *
 * This class represents a particle propagation medium. The medium's components
 * are a mapping of the chemical elements within the medium to their
 * corresponding mass fractions.
 */
class Medium
{
    public:
        /**
         * Construct new medium.
         *
         * @param[in] fractions
         *     Mapping of chemical elements to mass fractions
         * @param[in] density
         *     Mass density in g/cm3
         */
        Medium(const MassFractions& fractions, double density);

        /// This class is not default constructable.
        Medium() = delete;
        /// This uses the default copy constructor.
        Medium(const Medium&) = default;
        /// This class uses the default move constructor.
        Medium(Medium&&) = default;

        /// This class uses the default copy assign operator.
        Medium& operator=(const Medium&) = default;
        /// This class uses the default move assign operator.
        Medium& operator=(Medium&&) = default;

        /// This class uses the default destructor.
        ~Medium() = default;

        /**
         * Access element mass fractions.
         *
         * @return
         *     Mapping of the chemical elements the medium consists of to their
         *     corresponding mass fractions.
         */
        const MassFractions& GetMassFractions() const
        {
            return fractions_;
        }

        /**
         * Access mass density.
         *
         * @return
         *     Mass density in g/cm3
         */
        double GetDensity() const
        {
            return density_;
        }

    private:
        /// Element to mass fraction map
        const MassFractions fractions_;
        /// Mass density
        const double density_;
};

} // namespace seawater
