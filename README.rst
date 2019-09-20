Standard Seawater
=================

This project provides a small C++11 library for calculating the chemical
composition of seawater given a practical salinity.

The composition is based on the six most important (by reference salinity)
materials dissolved in *Standard Seawater*, according to F. J. Millero et al.,
Deep Sea Research Part I: Oceanographic Research Papers 55.1 (2008), pp. 50-72.
These materials are sodium, magnesium, calcium, potassium, chlorine, and
sulfate ions.


Installation
------------

The project's compilation is based on `CMake`_ and requires at least **version
3.12** and a compiler that supports C++11:

::

   mkdir build
   cd build
   cmake -DCMAKE_BUILD_TYPE=Release ..
   make

The project is installed via ``make install``; a global installation requires
*sudo*; a different install location can be specified via the *cmake* command
line argument ``-DCMAKE_INSTALL_PREFIX ...``.
The installation via ``make install`` copies the exported *seawater* library to
*$CMAKE_INSTALL_PREFIX/lib/cmake* and the library can be included and used in
your own project as shown below:

.. code:: cmake

   find_package(Seawater 0.1.0 REQUIRED)
   add_executable(example example.cxx)
   target_link_libraries(example seawater::seawater)


Python module
~~~~~~~~~~~~~

The C++ library can also be exported to Python by turning on the *cmake* option
``-BUILD_PYMODULE=ON``. The Python bindings are based on `Boost`_'s Python
library and require at least **version 1.67**. The following example shows how
to add the *pyseawater* module to a dedicated active virtual Python
environment, which was created via the `virtualenvwrapper`_:

.. code:: cmake

   cmake \
      -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_INSTALL_PREFIX=$VIRTUAL_ENV \
      -DBUILD_PYMODULE=ON \
      ..
   make install

By default, the C++ library will not be found when importing the Python module.
This can be fixed by appending the virtual Python environment to the
*$LD_LIBRARY_PATH*:

::

   export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$VIRTUAL_ENV/lib"


Unit tests
~~~~~~~~~~

The provided unit tests use `googletest`_, which is added as an external
submodule to this project. The test executable is configured via the *cmake*
command line argument ``-DBUILD_TESTING=ON``. After compilation via *make*, the
unit tests can be executed via *ctest*.
The custom build type ``-DCMAKE_BUILD_TYPE=Coverage`` is provided for creating
a coverage report via *lcov* and *genhtml*. The coverage report is created via
``make coverage``.


.. Links
.. _CMake:
   https://cmake.org/

.. _Boost:
   https://www.boost.org/

.. _virtualenvwrapper:
   https://virtualenvwrapper.readthedocs.io/en/stable/

.. _googletest:
   https://github.com/google/googletest/
