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

One of the design goals is two have a simple set of C++ classes (also exported
to Python) that represent chemical elements and element mass fractions, which
can be used for creating a seawater material for detector simulations with
e.g. `Geant4`_.

.. _Geant4:
   http://geant4.web.cern.ch/


.. documentation stop

Install instructions and other details are given in the project's `docs`_.

.. _docs:
   https://kkrings.github.io/seawater/
