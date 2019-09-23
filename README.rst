.. documentation start

Standard Seawater
=================

This project provides a small C++11 library for calculating the chemical
composition of seawater given a practical salinity.

The composition is based on the six most important (by reference salinity)
materials dissolved in *Standard Seawater*, according to F. J. Millero et al.,
Deep Sea Research Part I: Oceanographic Research Papers 55.1 (2008), pp. 50-72.
These materials are sodium, magnesium, calcium, potassium, chlorine, and
sulfate ions.

The following example shows how to calculate the element mass fractions of the
elements Standard Seawater consists of, using the project's Python interface:

.. code:: python

   import pyseawater

   seawater = pyseawater.seawater(salinity=34.6288-3, density=1.0400322)
   fractions = seawater.fractions()

   for (element, fraction) in fractions.items():
      print("Element {}: mass fraction = {}".format(element.symbol, fraction)


.. documentation stop
Install instructions and other details are given in the project's
`documentation`_.


.. Links
.. _documentation:
   https://kkrings.github.io/seawater/
