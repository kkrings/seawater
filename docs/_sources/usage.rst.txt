.. _usage:

Getting started
===============

This page exemplary shows how to use the provided C++ library and its Python
interface.


C++ library
-----------

A chemical element is created via the :cpp:class:`seawater::Element` class by
specifying the element's symbol, atomic charge, and atomic weight,
respectively:

.. code-block:: cpp

   #include <seawater/element.h>

   seawater::Element hydrogen{"H", 1, 1.};
   seawater::Element oxygen{"O", 8, 16.};

A material is created via the :cpp:type:`seawater::MassFractions` alias, which
maps chemical elements to mass fractions:

.. code-block:: cpp

   #include <seawater/massfraction.h>

   seawater::MassFractions water = {{hydrogen, 0.11}, {oxygen, 0.89}};

A molecule is created via the :cpp:type:`seawater::Molecule` alias, which maps
chemical elements to numbers of atoms:

.. code-block:: cpp

   #include <seawater/numatoms.h>

   seawater::Molecule water = {{hydrogen, 2}, {oxygen, 1}};

A propagation medium of type :cpp:class:`seawater::Medium` requires such a
mapping of chemical elements to mass fractions and the medium's density in:

.. code-block:: cpp

   #include <seawater/medium.h>

   seawater::Medium medium{seawater::GetMassFractions(water), 1.};

A mixture of two materials is created via multiplication and addition:

.. code-block:: cpp

   seawater::Molecule salt = {
      {seawater::Element{"Na", 11, 23.}, 1},
      {seawater::Element{"Cl", 17, 35.}, 1}
      };

   seawater::MassFractions saltwater = 0.97*water + 0.03*salt;


Python module
-------------

The following code blocks shows the usage of the :mod:`pyseawater` module:

.. code-block:: python

   import pyseawater

   hydrogen = pyseawater.Element("H", 1, 1.)
   oxygen = pyseawater.Element("O", 8, 16.)


The :class:`pyseawater.MassFractions` and :class:`pyseawater.Molecule` classes
wrap their corresponding C++ type aliases, but their container functionalities
are not exported. They are supposed to be used for converting dictionaries,
mapping chemical elements, for creating a mixture of materials:

.. code-block:: python

   water = pyseawater.Molecule({hydrogen: 2, oxygen: 1})

   salt = pyseawater.Molecule({
      pyseawater.Element("Na", 11, 23.): 1,
      pyseawater.Element("Cl", 17, 35.): 1
      })

   saltwater = 0.97*water + 0.03*salt

or a propagation medium:

.. code-block:: python

   medium = pyseawater.Medium(saltwater, density=1.)
