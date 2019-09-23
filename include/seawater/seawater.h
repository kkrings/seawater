/**
 *
 * Definition of seawater function
 *
 * (c) 2019
 * Kai Krings
 *
 * @file seawater.h
 * @date 2019-05-14
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#pragma once

#include "seawater/medium.h"

namespace seawater {

/**
 * @brief Seawater
 *
 * Construct seawater as a propagation medium given the practical salinity of
 * the ocean site of interest.
 *
 * Only the six most important (by reference salinity) materials dissolved in
 * Standard Seawater are taken into account, according to F. J. Millero et al.,
 * Deep Sea Research Part I: Oceanographic Research Papers 55.1 (2008), pp.
 * 50-72. These materials are sodium, magnesium, calcium, potassium, chlorine,
 * and sulfate ions and will be referred to as salt.
 *
 * After correcting for the missing materials dissolved in Standard Seawater
 * via renormalization, the element mass fractions of salt are scaled by
 *
 * @f[
 *     S_{R} = S_{P} \times 35.16504/35,
 * @f]
 *
 * where @f$S_{P}@f$ is the practical salinity of the ocean site of interest,
 * and combined with @f$1 - S_{R}@f$ of pure water.
 *
 * @param[in] practicalSalinity
 *     Practical salinity
 * @param[in] massDensity
 *     Mass density in g/cm3
 *
 * @return
 *     Seawater
 */
Medium GetSeaWater(double practicalSalinity = 35e-3, double massDensity = 1.);

} // namespace seawater
