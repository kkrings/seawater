Development
===========

This page targets users that want to contribute to the development of this
project, which takes place on `GitHub`_. This page shows how to build the
provided unit tests, how to create a code coverage report, and how to build the
HTML documentation.

Unit tests
----------

The provided unit tests use `googletest`_, which is added as an external
submodule to this project. The test executable is configured via the *cmake*
command line argument ``BUILD_TESTS``. After compilation via *make*, the unit
tests can be executed via *ctest*:

.. code-block:: bash

   git clone --recursive https://github.com/kkrings/seawater
   mkdir seawater/build
   cd seawater/build
   cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON ..
   make
   ctest


Code coverage
-------------

The custom build type ``Coverage`` is provided for creating a code coverage
report via `lcov` and `genhtml`. The coverage report is created via ``make
coverage``:

.. code-block:: bash

   git clone --recursive https://github.com/kkrings/seawater
   mkdir seawater/build
   cd seawater/build
   cmake -DCMAKE_BUILD_TYPE=Coverage ..
   make coverage

The code coverage report will be created in the subdirectory `coverage`.


Documentation
-------------

The provided HTML documentation is based on `Doxygen`_ and  `Sphinx`_. The
Sphinx extension `Breathe`_ is used as a bridge between Doxygen and Sphinx:

.. code-block:: bash

   git clone --recursive https://github.com/kkrings/seawater
   mkdir seawater/build
   cd seawater/build
   cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_DOCS=ON ..
   make doxygen
   sphinx-build -c docs ../src/docs docs/html


.. Links
.. _GitHub:
   https://github.com/kkrings/seawater

.. _googletest:
   https://github.com/google/googletest/

.. _Doxygen:
   http://www.doxygen.nl/

.. _Sphinx:
   http://www.sphinx-doc.org/

.. _Breathe:
   https://breathe.readthedocs.io/
