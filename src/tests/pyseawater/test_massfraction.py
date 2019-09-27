#!/usr/bin/env python
# -*- coding: utf-8 -*-

r"""Unit tests for `pyseawater.MassFraction`

"""
import unittest

import pyseawater


class MassFractionTestCase(unittest.TestCase):
    r"""Test cases for `pyseawater.MassFraction`

    """
    def test_min_value(self):
        r"""Test static property `min_value`.

        """
        self.assertEqual(
            pyseawater.MassFraction.min_value, 0.,
            "The static property `min_value` is not equal to ``0.``.")

    def test_max_value(self):
        r"""Test static property `max_value`.

        """
        self.assertEqual(
            pyseawater.MassFraction.max_value, 1.,
            "The static property `max_value` is not equal to ``1.``.")

    def test_value_init(self):
        r"""Test property `value` after initialization.

        """
        fraction = pyseawater.MassFraction(0.5)

        self.assertEqual(
            fraction.value, 0.5,
            "The property `value` is not equal to ``0.5``.")

    def test_exception_too_small_value_init(self):
        r"""Test expected exception from initialization.

        """
        message = "A `value` of ``0.`` did not raise an exception."

        with self.assertRaises(ValueError, msg=message):
            pyseawater.MassFraction(0.)

    def test_exception_too_large_value_init(self):
        r"""Test expected exception from initialization.

        """
        message = "A `value` of ``1.1`` did not raise an exception."

        with self.assertRaises(ValueError, msg=message):
            pyseawater.MassFraction(1.1)

    def test_value_setter(self):
        r"""Test `value` setter.

        """
        fraction = pyseawater.MassFraction(1.)
        fraction.value = 0.5

        self.assertEqual(
            fraction.value, 0.5,
            "The property `value` is not equal to ``0.5``.")

    def test_exception_too_small_value_setter(self):
        r"""Test expected exception from `value` setter.

        """
        fraction = pyseawater.MassFraction(1.)

        message = "A `value` of ``0.`` did not raise an exception."

        with self.assertRaises(ValueError, msg=message):
            fraction.value = 0.

    def test_exception_too_large_value_setter(self):
        r"""Test expected exception from `value` setter.

        """
        fraction = pyseawater.MassFraction(1.)

        message = "A `value` of ``1.1`` did not raise an exception."

        with self.assertRaises(ValueError, msg=message):
            fraction.value = 1.1


if __name__ == "__main__":
    # Execute the unit tests.
    unittest.main()
