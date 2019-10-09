# -*- coding: utf-8 -*-

"""Tests for `pyseawater.NumAtoms` and `pyseawater.Molecule`.

"""
import unittest

import pyseawater


class NumAtomsTestCase(unittest.TestCase):
    """Test cases for `pyseawater.NumAtoms`

    """
    def test_min_value(self):
        """Test static property `min_value`.

        """
        self.assertEqual(
            pyseawater.NumAtoms.min_value, 1,
            "The static property `min_value` is not equal ``1``.")

    def test_value(self):
        """Test property `value`.

        """
        atoms = pyseawater.NumAtoms(1)

        self.assertEqual(
            atoms.value, 1,
            "The property `value` is not equal the expected value ``1``.")

    def test_value_exceptions(self):
        """Test expected exceptions from initialization.

        """
        message = "A `value` of ``0`` did not raise an exception."

        with self.assertRaises(ValueError, msg=message):
            pyseawater.NumAtoms(0)


class MoleculeTestCase(unittest.TestCase):
    """Test cases for `pyseawater.Molecule`

    """
    def test_init(self):
        """Test molecule to dictionary conversions.

        """
        molecule = pyseawater.molecule2dict(
            pyseawater.Molecule({pyseawater.Element('H', 1, 1.): 2}))

        molecule = {
            (element.symbol, element.charge, element.weight): numatoms
            for element, numatoms in molecule.items()
            }

        self.assertDictEqual(molecule, {('H', 1, 1.): 2})

    def test_multiplication(self):
        """Test multiplication of scale and molecule.

        """
        fractions = pyseawater.massfractions2dict(
            1. * pyseawater.Molecule({pyseawater.Element('H', 1, 1.): 2}))

        fractions = {
            (element.symbol, element.charge, element.weight): fraction
            for element, fraction in fractions.items()
            }

        self.assertDictEqual(fractions, {('H', 1, 1.): 1.})