# -*- coding: utf-8 -*-

"""Unit tests for `pyseawater.Element`

"""
import unittest

import pyseawater


class ElementTestCase(unittest.TestCase):
    """Test cases for `pyseawater.Element`

    """
    def test_min_charge(self):
        """Test static property `min_charge`.

        """
        self.assertEqual(
            pyseawater.Element.min_charge, 1,
            "The static property `min_charge` is not equal ``1``.")

    def test_min_weight(self):
        """Test static property `min_weight`.

        """
        self.assertEqual(
            pyseawater.Element.min_weight, 1.,
            "The static property `min_weight` is not equal ``1.``.")

    def test_symbol(self):
        """Test property `symbol`.

        """
        hydrogen = pyseawater.Element('H', 1, 1.)

        self.assertEqual(
            hydrogen.symbol, 'H',
            "The property `symbol` is not equal the expected value ``'H'``.")

    def test_charge(self):
        """Test property `charge`.

        """
        hydrogen = pyseawater.Element('H', 1, 1.)

        self.assertEqual(
            hydrogen.charge, 1,
            "The property `charge` is not equal the expected value ``1``.")

    def test_charge_exception(self):
        """Test expected exceptions from initialization.

        """
        message = "A `charge` of ``0`` did not raise an exception."

        with self.assertRaises(ValueError, msg=message):
            pyseawater.Element('H', 0, 1.)

    def test_weight(self):
        """Test property `weight`.

        """
        hydrogen = pyseawater.Element('H', 1, 1.)

        self.assertEqual(
            hydrogen.weight, 1.,
            "The property `weight` is not equal the expected value ``1.``.")

    def test_weight_exceptions(self):
        """Test expected exceptions from initialization.

        """
        message = "A `weight` of ``0.`` did not raise an exception."

        with self.assertRaises(ValueError, msg=message):
            pyseawater.Element('H', 1, 0.)

    def test_lt_operator(self):
        """Test less than operator.

        """
        hydrogen = pyseawater.Element('H', 1, 1.)
        oxygen = pyseawater.Element('O', 8, 16.)

        message = (
            "Hydrogen is expected to be smaller than oxygen in terms of "
            "charge."
            )

        self.assertLess(hydrogen, oxygen, message)

    def test_gt_operator(self):
        """Test greater than operator.

        """
        hydrogen = pyseawater.Element('H', 1, 1.)
        oxygen = pyseawater.Element('O', 8, 16.)

        message = (
            "Oxygen is expected to be larger than hydrogen in terms of "
            "charge."
            )

        self.assertGreater(oxygen, hydrogen, message)
