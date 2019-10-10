/**
 *
 * Implementation of Python binding for Medium class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file medium.cxx
 * @date 2019-05-15
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include <boost/python.hpp>

#include "seawater/massfraction.h"
#include "seawater/medium.h"
#include "dict.h"

namespace bp = boost::python;

namespace seawater {
namespace python {

// wrap GetMassFractions member function: returns a Python dictionary
bp::dict GetMassFractionsWrapper(const Medium& medium)
{
    return ToDict<MassFractions>(medium.GetMassFractions());
}

// register Medium class
void RegisterMedium()
{
    bp::class_<Medium>
    {
        "Medium",
        "Propagation medium\n"
        "\n"
        "This class represents a particle propagation medium. The medium's\n"
        "components are a mapping of the chemical elements within the medium\n"
        "to their corresponding mass fractions.",
        bp::init<const MassFractions&, double>
        {
            bp::args("self", "fractions", "density"),
            "Construct new medium.\n"
            "\n"
            "Parameters\n"
            "----------\n"
            "fractions : MassFractions\n"
            "    Mapping of chemical elements to mass fractions\n"
            "density : float\n"
            "    Mass density in g/cm3\n"
            "\n"
            "Raises\n"
            "------\n"
            "ValueError\n"
            "    If the sum of `fractions` is not equal to 1."
        }
    }
    .def(
        "fractions",
        GetMassFractionsWrapper,
        bp::args("self"),
        "Element mass fractions\n"
        "\n"
        "Returns\n"
        "-------\n"
        "Dict[Element, float]\n"
        "    Mapping of the chemical elements the medium consists of to\n"
        "    their corresponding mass fractions"
    )
    .add_property(
        "density",
        &Medium::GetDensity,
        "Mass density\n"
        "\n"
        "Returns\n"
        "-------\n"
        "float\n"
        "    Mass density in g/cm3"
    );
}

} // namespace python
} // namespace seawater
