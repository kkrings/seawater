/**
 *
 * Register the seawater Python module
 *
 * (c) 2019
 * Kai Krings
 *
 * @file module.cxx
 * @date 2019-04-25
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include <boost/python.hpp>

namespace bp = boost::python;

namespace seawater {
namespace python {

// forward declarations of Python bindings
void RegisterElement();
void RegisterMassFraction();
void RegisterNumAtoms();
void RegisterMedium();
void RegisterSeawater();

} // namespace python
} // namespace seawater

BOOST_PYTHON_MODULE(pyseawater)
{
    bp::docstring_options docstrings{true, true, false};

    seawater::python::RegisterElement();
    seawater::python::RegisterMassFraction();
    seawater::python::RegisterNumAtoms();
    seawater::python::RegisterMedium();
    seawater::python::RegisterSeawater();
}
