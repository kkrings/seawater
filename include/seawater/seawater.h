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
