#!/usr/bin/env python
# -*- coding: utf-8 -*-

r"""Unit tests for `pyseawater.seawater`

"""
import unittest

import pyseawater


class SeawaterTestCase(unittest.TestCase):
    r"""Test cases for the `pyseawater.seawater` function

    """
    def test_composition(self):
        r"""Test the chemical composition of seawater.

        """
        seawater = pyseawater.seawater(35e-3).fractions()

        fractions = sorted(
            seawater.items(), key=lambda entry: entry[1], reverse=True)

        symbols = [e.symbol for e, f in fractions]
        expected = ["O", "H", "Cl", "Na", "Mg", "S", "Ca", "K"]

        message = (
            "The sequence of the chemical elements of seawater, sorted by "
            "mass fraction, is not equal to the expectation."
            )

        self.assertListEqual(symbols, expected, message)

    def test_density(self):
        r"""Test the mass density attribute.

        """
        seawater = pyseawater.seawater(density=1.04)

        message = (
            "The seawaters density of {} is not equal to the expected value "
            " of 1.04."
            ).format(seawater.density)

        self.assertEqual(seawater.density, 1.04, message)


if __name__ == "__main__":
    # Execute the unit tests.
    unittest.main()
