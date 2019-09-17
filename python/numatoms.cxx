/**
 *
 * Implementation of Python binding for NumAtoms class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file numatoms.cxx
 * @date 2019-06-06
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include <boost/python.hpp>

#include "seawater/numatoms.h"
#include "fromdict.h"

namespace bp = boost::python;

namespace seawater {
namespace python {

// register NumAtoms class
void RegisterNumAtoms()
{
    bp::class_<
        NumAtoms
    >
    {
        "NumAtoms",
        "Number of atoms\n"
        "\n"
        "This class represents the number of atoms of a chemical element\n"
        "within a molecule.",
        bp::init<int>
        {
            (bp::arg("self"), bp::arg("value")=1),
            "Construct new number of atoms.\n"
            "\n"
            "Parameters\n"
            "----------\n"
            "value : int\n"
            "    Number of atoms\n"
            "\n"
            "Raises\n"
            "------\n"
            "ValueError\n"
            "    If `value` is smaller than `min_value`."
        }
    }
    .add_static_property(
        "min_value",
        &NumAtoms::GetMin,
        "int: The minimum allowed number of atoms is equal to 1."
    )
    .add_property(
        "value",
        &NumAtoms::GetValue,
        "int: Number of atoms"
    );

    bp::class_<Molecule>
    {
        "Molecule",
        "A molecule is represented by an element to number of atoms map.",
        bp::no_init
    }
    .def(
        "__init__",
        bp::make_constructor(
            FromDict<Molecule, int>,
            bp::default_call_policies(),
            bp::args("atoms")
        ),
        "Convert `atoms` into element to number of atoms map.\n"
        "\n"
        "Parameters\n"
        "----------\n"
        "atoms : Dict[Element, NumAtoms]\n"
        "    Mapping of chemical elements to number of atoms; values should\n"
        "    be of type `NumAtoms` or `int`."
    )
    .def(
        double() * bp::self
    );

    bp::def(
        "weight",
        GetWeight,
        bp::args("molecule"),
        "Atomic weight\n"
        "\n"
        "Calculate the atomic weight of the given molecule.\n"
        "\n"
        "Parameters\n"
        "----------\n"
        "molecule : Molecule\n"
        "    Molecule\n"
        "\n"
        "Returns\n"
        "-------\n"
        "float\n"
        "    Atomic weight"
    );

    bp::def(
        "mass_fractions",
        GetMassFractions,
        bp::args("molecule"),
        "Element mass fractions\n"
        "\n"
        "Transform the given molecule into an element to mass fraction map.\n"
        "\n"
        "Parameters\n"
        "----------\n"
        "molecule : Molecule\n"
        "    Molecule\n"
        "\n"
        "Returns\n"
        "-------\n"
        "MassFractions\n"
        "    Element to mass fraction map"
    );
}

} // namespace python
} // namespace seawater
