# -*- coding: utf-8 -*-

"""Tests for `pyseawater.Medium`

"""
import unittest

import pyseawater


class MediumTestCase(unittest.TestCase):
    """Test cases for `pyseawater.Medium`

    """
    def setUp(self):
        """Initialize water medium.

        """
        self.hydrogen = pyseawater.Element('H', 1, 1.)
        self.oxygen = pyseawater.Element('O', 8, 16.)

        self.fractions = pyseawater.mass_fractions(
            pyseawater.Molecule({self.hydrogen: 2, self.oxygen: 1}))

        self.medium = pyseawater.Medium(self.fractions, density=1.)

    def test_fractions(self):
        """Test medium's mass fractions.

        """
        fractions = self.medium.fractions()

        fractions = {
            (element.symbol, element.charge, element.weight): fraction
            for element, fraction in fractions.items()
            }

        reference = pyseawater._fractions2dict(self.fractions)

        reference = {
            (element.symbol, element.charge, element.weight): fraction
            for element, fraction in reference.items()
            }

        self.assertDictEqual(fractions, reference)

    def test_density(self):
        """Test medium's density.

        """
        self.assertEqual(self.medium.density, 1.)


class MediumExceptionTestCase(unittest.TestCase):
    """Test cases for `pyseawater.Medium`

    """
    def setUp(self):
        self.hydrogen = pyseawater.Element('H', 1, 1.)
        self.oxygen = pyseawater.Element('O', 8, 16.)

    def test_sum_massfractions_below_one(self):
        """Test for expected exception from initialization.

        """
        fractions = pyseawater.MassFractions({
            self.hydrogen: 0.4,
            self.oxygen: 0.4
            })

        with self.assertRaises(ValueError):
            pyseawater.Medium(fractions, density=1.)

    def test_sum_massfractions_above_one(self):
        """Test for expected exception from initialization.

        """
        fractions = pyseawater.MassFractions({
            self.hydrogen: 0.6,
            self.oxygen: 0.6
            })

        with self.assertRaises(ValueError):
            pyseawater.Medium(fractions, density=1.)
