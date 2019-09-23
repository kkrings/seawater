/**
 *
 * Definition of MassFraction class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file massfraction.h
 * @date 2019-05-28
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#pragma once

#include <map>

#include "seawater/element.h"

namespace seawater {

//---Mass fraction-------------------------------------------------------------

/**
 * @brief Mass fraction
 *
 * This class represents the mass fraction of either a substance or a chemical
 * element within a mixture.
 */
class MassFraction
{
    public:
        /**
         * @brief Minimum mass fraction
         *
         * A mass fraction should be larger than 0.
         *
         * @return
         *     Minimum mass fraction
         */
        static constexpr double GetMin()
        {
            return 0.;
        }

        /**
         * @brief Maximum mass fraction
         *
         * A mass fraction should be smaller or equal to 1.
         *
         * @return
         *     Maximum mass fraction
         */
        static constexpr double GetMax()
        {
            return 1.;
        }

        /**
         * Construct new mass fraction.
         *
         * @param[in] value
         *     Mass fraction
         */
        MassFraction(double value = 1.)
            : value_{value}
        {
            CheckValue();
        }

        /// This class uses the default copy constructor.
        MassFraction(const MassFraction&) = default;
        /// This class uses the default move constructor.
        MassFraction(MassFraction&&) = default;

        /// This class uses the default copy assign operator.
        MassFraction& operator=(const MassFraction&) = default;
        /// This class uses the default move assign operator.
        MassFraction& operator=(MassFraction&&) = default;

        /// This class uses the default destructor.
        ~MassFraction() = default;

        /**
         * Access mass fraction.
         *
         * @return
         *     Mass fraction
         */
        double GetValue() const
        {
            return value_;
        }

        /**
         * Update mass fraction.
         *
         * @param[in] value
         *     New mass fraction
         */
        void SetValue(double value)
        {
            value_ = value;
            CheckValue();
        }

    private:
        /// Mass fraction
        double value_;

        /// Check if the mass fraction is within the allowed range.
        void CheckValue();
};

/// Addition assignment of two mass fractions
// inline MassFraction& operator+=(MassFraction& left, const MassFraction& right)
// {
//     left.SetValue(left.GetValue() + right.GetValue());
//     return left;
// }

/// Multiplication assignment of scale and mass fraction
// inline MassFraction& operator*=(MassFraction& fraction, double scale)
// {
//     fraction.SetValue(scale * fraction.GetValue());
//     return fraction;
// }

//---Element to mass fraction mapping------------------------------------------

/// Mapping of chemical elements to mass fractions
using MassFractions = std::map<Element, MassFraction>;

/**
 * @brief Addition assignment of two element to mass fraction maps
 *
 * Join two element to mass fraction maps; if an element is contained in both
 * maps, the mass fractions are added together.
 */
MassFractions& operator+=(MassFractions& left, const MassFractions& right);

/// Addition of two element to mass fraction maps
inline MassFractions operator+(
    const MassFractions& left, const MassFractions& right)
{
    MassFractions fractions = left;
    fractions += right;
    return fractions;
}

/**
 * @brief Multiplication assignment of scale and element to mass fraction map
 *
 * Each mass fraction in the given element to mass fraction map is multiplied
 * by the given scale.
 */
MassFractions& operator*=(MassFractions& fractions, double scale);

/// Multiplication of scale and element to mass fraction map
inline MassFractions operator*(double scale, const MassFractions& right)
{
    MassFractions fractions = right;
    fractions *= scale;
    return fractions;
}

} // namespace seawater
