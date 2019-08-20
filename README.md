# Standard Seawater

This project proves a small C++ library for calculating the chemical
composition of seawater given a practical salinity. 

The composition is based on the six most important (by reference salinity)
materials dissolved in *Standard Seawater*, according to F. J. Millero et al.,
Deep Sea Research Part I: Oceanographic Research Papers 55.1 (2008),
pp. 50-72. These materials are sodium, magnesium, calcium, potassium, chlorine,
and sulfate ions.

## Installation

Because there is no release available yet, you have clone the Git repository:

```sh
git clone https://github.com/kkrings/seawater.git
```

The project's compilation is based on [CMake](https://cmake.org/) and requires
at least version 3.12:

```sh
mkdir seawater/build
cd seawater/build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

The actual installation is done via `make install`, which install the library
globally (usually to `/usr/local`) and requires `sudo`. A different install
location can be specified via the `cmake` command line
argument `-DCMAKE_INSTALL_PREFIX=...`.

### Python bindings

The C++ library can also be exported to Python by specifying the `cmake`
command line argument `-DSEAWATER_BUILD_PYBINDINGS=ON`. The Python bindings are
based on [Boost](https://www.boost.org/)'s `Boost.Python` library and require
at least version 1.67.
