/**
 *
 * Implementation of Python binding for seawater function
 *
 * (c) 2019
 * Kai Krings
 *
 * @file seawater.cxx
 * @date 2019-05-16
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include "seawater/seawater.h"

#include <boost/python.hpp>

namespace bp = boost::python;

namespace seawater {
namespace python {

// register GetSeaWater function
void RegisterSeawater()
{
    bp::def(
        "seawater",
        GetSeaWater,
        (bp::arg("salinity")=35e-3, bp::arg("density")=1.),
        "Seawater\n"
        "\n"
        "Construct seawater as a propagation medium given the practical\n"
        "salinity of the ocean site of interest.\n"
        "\n"
        "Only the six most important (by reference salinity) materials\n"
        "dissolved in Standard Seawater are taken into account, according\n"
        "to [Millero2008]_. These materials are sodium, magnesium, calcium,\n"
        "potassium, chlorine, and sulfate ions and will be referred to as\n"
        "salt.\n"
        "\n"
        "After correcting for the missing materials dissolved in Standard\n"
        "Seawater via renormalization, the element mass fractions of salt\n"
        "are scaled by\n"
        "\n"
        ".. math::\n"
        "\n"
        "    S_{R} = S_{P} \\times 35.16504/35\n"
        "\n"
        "where :math:`S_{P}` is the practical salinity of the ocean site of\n"
        "interest, and combined with :math:`1 - S_{R}` of pure water.\n"
        "\n"
        ".. [Millero2008]\n"
        "    F. J. Millero et al., Deep Sea Research Part I: Oceanographic\n"
        "    Research Papers 55.1 (2008), pp. 50-72.\n"
        "\n"
        "Parameters\n"
        "----------\n"
        "salinity : float, optional\n"
        "    Practical salinity\n"
        "density : float, optional\n"
        "    Mass density in g/cm3\n"
        "\n"
        "Returns\n"
        "-------\n"
        "Medium\n"
        "    Seawater"
    );
}

} // namespace seawater
} // namespace straw
