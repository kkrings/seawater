/**
 *
 * Implementation of Python binding for Element class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file element.cxx
 * @date 2019-04-25
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include "seawater/element.h"

#include <boost/noncopyable.hpp>
#include <boost/python.hpp>

namespace bp = boost::python;

namespace seawater {
namespace python {

// register Element class
void RegisterElement()
{
    bp::class_<Element>
    {
        "Element",
        "Chemical element\n"
        "\n"
        "This class represents a chemical element, which has a specific\n"
        "atomic charge and weight. Each element is identified by a specific\n"
        "symbol.",
        bp::init<const std::string&, int, double>
        {
            bp::args("self", "symbol", "charge", "weight"),
            "Construct a new element.\n"
            "\n"
            "Parameters\n"
            "----------\n"
            "symbol : string\n"
            "    Element's symbol\n"
            "charge : int\n"
            "    Element's atomic charge\n"
            "weight : float\n"
            "    Element's atomic weight"
        }
    }
    .add_property(
        "symbol",
        &Element::GetSymbol,
        "str: Symbol representing the chemical element"
    )
    .add_property(
        "charge",
        &Element::GetCharge,
        "int: Atomic charge Z"
    )
    .add_property(
        "weight",
        &Element::GetWeight,
        "float: Atomic weight A"
    )
    .add_static_property(
        "min_charge",
        &Element::GetMinCharge,
        "int: Minimum allowed atomic charge"
    )
    .add_static_property(
        "min_weight",
        &Element::GetMinWeight,
        "float: Minimum allowed atomic weight"
    )
    .def(
        bp::self < bp::self
    )
    .def(
        bp::self > bp::self
    );
}

} // namespace python
} // namespace seawater
