# -*- coding: utf-8 -*-

"""Unit tests for `pyseawater.seawater`

"""
import unittest

import pyseawater


class SeawaterElementsTestCase(unittest.TestCase):
    """Test seawater's elements.

    """
    @classmethod
    def setUpClass(cls):
        seawater = pyseawater.seawater(salinity=35e-3, density=1.)
        cls.elements = {e.symbol: e for e in seawater.fractions().keys()}

    @staticmethod
    def message(attr):
        return "Element's {} is not equal to the expected value.".format(attr)

    def test_hydrogen(self):
        """Test for hydrogen.

        """
        self.assertIn("H", self.elements)
        hydrogen = self.elements["H"]
        self.assertEqual(hydrogen.symbol, "H", self.message("symbol"))
        self.assertEqual(hydrogen.charge, 1, self.message("charge"))
        self.assertEqual(hydrogen.weight, 1.01, self.message("weight"))

    def test_oxygen(self):
        """Test for oxygen.

        """
        self.assertIn("O", self.elements)
        oxygen = self.elements["O"]
        self.assertEqual(oxygen.symbol, "O", self.message("symbol"))
        self.assertEqual(oxygen.charge, 8, self.message("charge"))
        self.assertEqual(oxygen.weight, 15.999, self.message("weight"))

    def test_sodium(self):
        """Test for sodium.

        """
        self.assertIn("Na", self.elements)
        sodium = self.elements["Na"]
        self.assertEqual(sodium.symbol, "Na", self.message("symbol"))
        self.assertEqual(sodium.charge, 11, self.message("charge"))
        self.assertEqual(sodium.weight, 22.99, self.message("weight"))

    def test_magnesium(self):
        """Test for magnesium.

        """
        self.assertIn("Mg", self.elements)
        magnesium = self.elements["Mg"]
        self.assertEqual(magnesium.symbol, "Mg", self.message("symbol"))
        self.assertEqual(magnesium.charge, 12, self.message("charge"))
        self.assertEqual(magnesium.weight, 24.305, self.message("weight"))

    def test_calcium(self):
        """Test for calcium.

        """
        self.assertIn("Ca", self.elements)
        calcium = self.elements["Ca"]
        self.assertEqual(calcium.symbol, "Ca", self.message("symbol"))
        self.assertEqual(calcium.charge, 20, self.message("charge"))
        self.assertEqual(calcium.weight, 40.078, self.message("weight"))

    def test_potassium(self):
        """Test for potassium.

        """
        self.assertIn("K", self.elements)
        potassium = self.elements["K"]
        self.assertEqual(potassium.symbol, "K", self.message("symbol"))
        self.assertEqual(potassium.charge, 19, self.message("charge"))
        self.assertEqual(potassium.weight, 39.098, self.message("weight"))

    def test_sulfur(self):
        """Test for sulfur.

        """
        self.assertIn("S", self.elements)
        sulfur = self.elements["S"]
        self.assertEqual(sulfur.symbol, "S", self.message("symbol"))
        self.assertEqual(sulfur.charge, 16, self.message("charge"))
        self.assertEqual(sulfur.weight, 32.065, self.message("weight"))

    def test_chlorine(self):
        """Test chlorine.

        """
        self.assertIn("Cl", self.elements)
        chlorine = self.elements["Cl"]
        self.assertEqual(chlorine.symbol, "Cl", self.message("symbol"))
        self.assertEqual(chlorine.charge, 17, self.message("charge"))
        self.assertEqual(chlorine.weight, 35.453, self.message("weight"))


class SeawaterFractionsTestCase(unittest.TestCase):
    """Test seawater's mass fractions

    """
    def test_ordering(self):
        """Test mass fractions' odering.

        """
        seawater = pyseawater.seawater(salinity=35e-3).fractions()

        fractions = sorted(
            seawater.items(), key=lambda entry: entry[1], reverse=True)

        symbols = [e.symbol for e, f in fractions]
        expected = ["O", "H", "Cl", "Na", "Mg", "S", "Ca", "K"]

        message = (
            "The sequence of the chemical elements of seawater, sorted by "
            "mass fraction, is not equal to the expectation."
            )

        self.assertListEqual(symbols, expected, message)


class SeawaterSalinityTestCase(unittest.TestCase):
    """Test seawater's salinity.

    """
    @classmethod
    def setUpClass(cls):
        """Reference hydrogen mass fraction

        """
        seawater = pyseawater.seawater(salinity=35e-3).fractions()
        hydrogen = {element.symbol: element for element in seawater}["H"]
        cls.fraction = seawater[hydrogen]

    def test_more_salt(self):
        """Test hydrogen's mass fraction for more salt.

        """
        seawater = pyseawater.seawater(salinity=36e-3).fractions()
        hydrogen = {element.symbol: element for element in seawater}["H"]
        message = "Hydrogen's mass fraction is not smaller for more salt."
        self.assertLess(seawater[hydrogen], self.fraction, message)

    def test_less_salt(self):
        """Test hydrogen's mass fraction for less salt.

        """
        seawater = pyseawater.seawater(salinity=34e-3).fractions()
        hydrogen = {element.symbol: element for element in seawater}["H"]
        message = "Hydrogen's mass fraction is not larger for less salt."
        self.assertGreater(seawater[hydrogen], self.fraction, message)


class SeawaterDensityTestCase(unittest.TestCase):
    """Test seawater's mass density

    """
    def test_density(self):
        """Test seawater's mass density.

        """
        seawater = pyseawater.seawater(density=1.04)
        message = "Density is not equal to the expected value of 1.04."
        self.assertEqual(seawater.density, 1.04, message)
