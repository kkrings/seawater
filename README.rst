Standard Seawater
=================

.. image:: https://travis-ci.com/kkrings/seawater.svg?branch=master
   :target: https://travis-ci.com/kkrings/seawater

.. documentation start

This project provides a small C++11 library for calculating the chemical
composition of seawater given a practical salinity.

The composition is based on the six most important (by reference salinity)
materials dissolved in *Standard Seawater*, according to F. J. Millero et al.,
Deep Sea Research Part I: Oceanographic Research Papers 55.1 (2008), pp. 50-72.

The C++11 library consists of a simple set of C++ classes that represent
chemical elements, element mass fractions, numbers of atoms, molecules, and
mixtures. These classes can be used for creating a seawater material for
detector simulations with e.g. `Geant4`_.

This project also provides a Python interface to the C++ library.

.. _Geant4:
   http://geant4.web.cern.ch/

.. documentation stop

Install instructions and other details are given in the project's `docs`_.

.. _docs:
   https://kkrings.github.io/seawater/
