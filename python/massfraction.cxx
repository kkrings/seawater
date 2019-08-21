/**
 *
 * Implementation of Python binding for MassFraction class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file massfraction.cxx
 * @date 2019-06-06
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include <boost/python.hpp>

#include "seawater/massfraction.h"
#include "fromdict.h"

namespace bp = boost::python;

namespace seawater {
namespace python {

// register MassFraction class
void RegisterMassFraction()
{
    bp::class_<
        MassFraction
    >
    {
        "MassFraction",
        "Mass fraction\n"
        "\n"
        "This class represents the mass fraction of either a substance or a\n"
        "chemical element within a mixture.",
        bp::init<double>
        {
            (bp::arg("self"), bp::arg("value")=1.),
            "Construct new mass fraction.\n"
            "\n"
            "Parameters\n"
            "----------\n"
            "value : float\n"
            "    Mass fraction\n"
            "\n"
            "Raises\n"
            "------\n"
            "ValueError\n"
            "    If `value` is not in the range ``(min_value, max_value]``."
        }
    }
    .add_static_property(
        "min_value",
        &MassFraction::GetMin,
        "float: A mass fraction should be larger than 0."
    )
    .add_static_property(
        "max_value",
        &MassFraction::GetMax,
        "float: A mass fraction should be smaller or equal to 1."
    )
    .add_property(
        "value",
        &MassFraction::GetValue,
        &MassFraction::SetValue,
        "float: Mass fraction"
    );

    bp::class_<MassFractions>
    {
        "MassFractions",
        "Mapping of chemical elements to mass fractions",
        bp::no_init
    }
    .def(
        "__init__",
        bp::make_constructor(
            FromDict<MassFractions, double>,
            bp::default_call_policies(),
            bp::args("fractions")
        ),
        "Convert `fractions` into element to mass fraction map.\n"
        "\n"
        "Parameters\n"
        "----------\n"
        "fractions : Dict[Element, MassFraction]\n"
        "    Mapping of chemical elements to mass fractions; values should\n"
        "    be of type `MassFraction` or `float`."
    )
    .def(
        bp::self += bp::other<MassFractions>()
    )
    .def(
        bp::self + MassFractions()
    )
    .def(
        bp::self *= bp::other<double>()
    )
    .def(
        double() * bp::self
    );

}

} // namespace python
} // namespace seawater
