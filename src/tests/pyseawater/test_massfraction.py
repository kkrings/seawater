# -*- coding: utf-8 -*-

"""Tests for `pyseawater.MassFraction` and `pyseawater.MassFractions`

"""
import unittest

import pyseawater


class MassFractionTestCase(unittest.TestCase):
    """Test cases for `pyseawater.MassFraction`

    """
    def test_min_value(self):
        """Test static property `min_value`.

        """
        self.assertEqual(
            pyseawater.MassFraction.min_value, 0.,
            "The static property `min_value` is not equal to ``0.``.")

    def test_max_value(self):
        """Test static property `max_value`.

        """
        self.assertEqual(
            pyseawater.MassFraction.max_value, 1.,
            "The static property `max_value` is not equal to ``1.``.")

    def test_value_init(self):
        """Test property `value` after initialization.

        """
        fraction = pyseawater.MassFraction(0.5)

        self.assertEqual(
            fraction.value, 0.5,
            "The property `value` is not equal to ``0.5``.")

    def test_exception_too_small_value_init(self):
        """Test expected exception from initialization.

        """
        message = "A `value` of ``0.`` did not raise an exception."

        with self.assertRaises(ValueError, msg=message):
            pyseawater.MassFraction(0.)

    def test_exception_too_large_value_init(self):
        """Test expected exception from initialization.

        """
        message = "A `value` of ``1.1`` did not raise an exception."

        with self.assertRaises(ValueError, msg=message):
            pyseawater.MassFraction(1.1)

    def test_value_setter(self):
        """Test `value` setter.

        """
        fraction = pyseawater.MassFraction(1.)
        fraction.value = 0.5

        self.assertEqual(
            fraction.value, 0.5,
            "The property `value` is not equal to ``0.5``.")

    def test_exception_too_small_value_setter(self):
        """Test expected exception from `value` setter.

        """
        fraction = pyseawater.MassFraction(1.)

        message = "A `value` of ``0.`` did not raise an exception."

        with self.assertRaises(ValueError, msg=message):
            fraction.value = 0.

    def test_exception_too_large_value_setter(self):
        """Test expected exception from `value` setter.

        """
        fraction = pyseawater.MassFraction(1.)

        message = "A `value` of ``1.1`` did not raise an exception."

        with self.assertRaises(ValueError, msg=message):
            fraction.value = 1.1


class MassFractionsTestCase(unittest.TestCase):
    """Test cases for `pyseawater.MassFractions`.

    """
    def test_init(self):
        """Test element to mass fraction map to dictionary conversions.

        """
        fractions = pyseawater.massfractions2dict(
            pyseawater.MassFractions({pyseawater.Element('H', 1, 1.): 1.}))

        fractions = {
            (element.symbol, element.charge, element.weight): fraction
            for element, fraction in fractions.items()
            }

        self.assertDictEqual(fractions, {('H', 1, 1.): 1.})

    def test_addition(self):
        """Test addition of two element to mass fraction maps.

        """
        hydrogen = pyseawater.Element('H', 1, 1.)
        oxygen = pyseawater.Element('O', 8, 16.)

        fractions = pyseawater.massfractions2dict(
            pyseawater.MassFractions({hydrogen: 0.25}) +
            pyseawater.MassFractions({hydrogen: 0.25}) +
            pyseawater.MassFractions({oxygen: 0.5}))

        fractions = {
            (element.symbol, element.charge, element.weight): fraction
            for element, fraction in fractions.items()
            }

        self.assertDictEqual(
            fractions, {('H', 1, 1.): 0.5, ('O', 8, 16.): 0.5})

    def test_multiplication(self):
        """Test multiplication of scale and element to mass fraction map.

        """
        hydrogen = pyseawater.Element('H', 1, 1.)

        fractions = pyseawater.massfractions2dict(
            2. * pyseawater.MassFractions({hydrogen: 0.5}))

        fractions = {
            (element.symbol, element.charge, element.weight): fraction
            for element, fraction in fractions.items()
            }

        self.assertDictEqual(fractions, {('H', 1, 1.): 1.})
