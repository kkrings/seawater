# -*- coding: utf-8 -*-

import os
import subprocess

import setuptools
from setuptools.command.build_ext import build_ext


# ---C++ extensions------------------------------------------------------------
class CMakeExtension(setuptools.Extension):
    """CMake-based C++ extension for Python

    The class allows to add a C++ extension to a Python project that
    uses CMake for configuring and building.

    """
    def __init__(self, name, sourcedir=""):
        setuptools.Extension.__init__(self, name, sources=[])
        self.sourcedir = os.path.abspath(sourcedir)


class CMakeBuild(build_ext):
    """Build the `pyseawater` Python module.

    This class calls CMake for configuring and building the `pyseawater`
    Python module.

    """
    def run(self):
        for extension in self.extensions:
            self.build_extension(extension)

    def build_extension(self, extension):
        output_directory = os.path.abspath(
            os.path.dirname(self.get_ext_fullpath(extension.name)))

        if self.debug:
            build_type = "Debug"
        else:
            build_type = "Release"

        cmake_args = [
            "-DCMAKE_BUILD_TYPE={}".format(build_type),
            "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY={}".format(output_directory),
            "-DBUILD_PYMODULE=ON"
            ]

        if not os.path.exists(self.build_temp):
            os.makedirs(self.build_temp)

        subprocess.check_call(
            ["cmake", extension.sourcedir] + cmake_args,
            cwd=self.build_temp)

        subprocess.check_call(
            ["cmake", "--build", "."],
            cwd=self.build_temp)


# ---Project setup-------------------------------------------------------------
setuptools.setup(
    name="pyseawater",
    version="0.1.0",
    author="Kai Krings",
    author_email="kai.krings@posteo.de",
    description="Chemical composition of seawater given a practical salinity",
    ext_modules=[CMakeExtension("pyseawater")],
    cmdclass={"build_ext": CMakeBuild})
