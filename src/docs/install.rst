Installation
============

This project provides the C++ library `seawater`, which can also be exported to
Python in form of the Python module `pyseawater`.


Requirements
------------

The installation requires:

* `CMake`_ 3.12 or above, and
* a compiler that supports C++11.

Optionally, the Python bindings require:

* Python 2.7 or above, and
* `Boost`_'s Python library 1.67 or above.


C++ library
-----------

From within the project's directory, run the following commands:

.. code-block:: bash

   mkdir build
   cd build
   cmake -DCMAKE_BUILD_TYPE=Release ..
   make

The library is installed via ``make install``. Note that a global installation
requires `sudo`. A different install location can be specified via the `cmake`
command line argument ``CMAKE_INSTALL_PREFIX``. The library's `cmake` target is
copied to the subdirectory ``lib/cmake`` under the install prefix and can be
included and used in your own project as shown below:

.. code-block:: cmake

   find_package(Seawater 0.1.0 REQUIRED)
   add_executable(example example.cxx)
   target_link_libraries(example seawater::seawater)


Python module
-------------

The following example shows how to add the Python module to a dedicated active
virtual Python environment, which was created via the `virtualenvwrapper`_:

.. code-block:: bash

   cmake \
      -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_INSTALL_PREFIX=$VIRTUAL_ENV \
      -DBUILD_PYMODULE=ON \
      ..
   make install

Make sure that the C++ library can be found when importing the Python module:

.. code-block:: bash

   export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$VIRTUAL_ENV/lib"


.. Links
.. _CMake:
   https://cmake.org/

.. _Boost:
   https://www.boost.org/

.. _virtualenvwrapper:
   https://virtualenvwrapper.readthedocs.io/en/stable/
