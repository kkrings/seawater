# Standard Seawater

This project proves a small C++ library for calculating the chemical
composition of seawater given a practical salinity. 

The composition is based on the six most important (by reference salinity)
materials dissolved in *Standard Seawater*, according to F. J. Millero et al.,
Deep Sea Research Part I: Oceanographic Research Papers 55.1 (2008), pp. 50-72.
These materials are sodium, magnesium, calcium, potassium, chlorine, and
sulfate ions.

## Installation

Because there is no release available yet, you have clone the Git repository:

```sh
git clone https://github.com/kkrings/seawater.git
```

The project's compilation is based on [CMake](https://cmake.org/) and requires
at least version 3.10:

```sh
mkdir seawater/build
cd seawater/build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

The actual installation is done via `make install`, which install the library
globally (usually to `/usr/local`) and requires `sudo`. A different install
location can be specified via the `cmake` command line
argument `-DCMAKE_INSTALL_PREFIX`.

### How to use the *seawater* library in your own project

The installation via `make install` copies the exported `seawater` target
to `$CMAKE_INSTALL_PREFIX/lib/cmake` and the target can be included and used in
your own project as shown below:

```cmake
find_package(Seawater 0.1.0 REQUIRED)
add_executable(example example.cxx)
target_link_libraries(example seawater::seawater)
```

### How to execute the provided unit tests

The provided unit tests use [googletest](https://github.com/google/googletest),
which is added as an external submodule to this project. This means you have to
call `git clone` with the command line argument `--recursive` in order to clone
the *googletest* project into your working copy. The test executable is
configured via the `cmake` command line argument `-DBUILD_TESTING=ON`. After
compilation via `make`, the unit tests can be executed via `ctest`.

#### How to create a coverage report

The custom build type `-DCMAKE_BUILD_TYPE=Coverage` is provided for creating a
coverage report. After executing `make`, the coverage report is created via

```sh
lcov -d . -z
ctest
lcov -c -d . -o test.info
lcov -r test.info '*/tests/*' '/usr/include/*' -o coverage.info
genhtml -o coverage coverage.info
```
