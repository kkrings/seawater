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
