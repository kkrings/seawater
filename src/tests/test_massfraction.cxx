/**
 *
 * Unit tests for MassFraction class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file test_massfraction.cxx
 * @date 2019-08-27
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include <memory>
#include <stdexcept>

#include <gtest/gtest.h>

#include "seawater/element.h"
#include "seawater/massfraction.h"

/**
 * Test the static member function GetMin.
 */
TEST(MassFractionTestCase, TestGetMin)
{
    EXPECT_DOUBLE_EQ(seawater::MassFraction::GetMin(), 0.);
}

/**
 * Test the static member function GetMax.
 */
TEST(MassFractionTestCase, TestGetMax)
{
    EXPECT_DOUBLE_EQ(seawater::MassFraction::GetMax(), 1.);
}

/**
 * Test the member variable value_ after initialization.
 */
TEST(MassFractionTestCase, TestValueInit)
{
    seawater::MassFraction fraction{0.5};
    EXPECT_DOUBLE_EQ(fraction.GetValue(), 0.5);
}

/**
 * Test expected exception from initialization.
 */
TEST(MassFractionTestCase, TestExceptionTooSmallValueInit)
{
    EXPECT_THROW(seawater::MassFraction(0.), std::invalid_argument);
}

/**
 * Test expected exception from initialization.
 */
TEST(MassFractionTestCase, TestExceptionTooLargeValueInit)
{
    EXPECT_THROW(seawater::MassFraction(1.1), std::invalid_argument);
}

/**
 * Test setter function of member variable value_.
 */
TEST(MassFractionTestCase, TestValueSetter)
{
    seawater::MassFraction fraction{1.};
    fraction.SetValue(0.5);
    EXPECT_DOUBLE_EQ(fraction.GetValue(), 0.5);
}

/**
 * Test expected exception from setter function of member variable value_.
 */
TEST(MassFractionTestCase, TestExceptionTooSmallValueSetter)
{
    seawater::MassFraction fraction{1.};
    EXPECT_THROW(fraction.SetValue(0.), std::invalid_argument);
}

/**
 * Test expected exception from setter function of member variable value_.
 */
TEST(MassFractionTestCase, TestExceptionTooLargeValueSetter)
{
    seawater::MassFraction fraction{1.};
    EXPECT_THROW(fraction.SetValue(1.1), std::invalid_argument);
}

/**
 * Test addition assignment of two mass fractions.
 */
TEST(MassFractionTestCase, TestAdditionAssignment)
{
    seawater::MassFraction fraction{0.25};
    fraction += seawater::MassFraction{0.25};
    EXPECT_DOUBLE_EQ(fraction.GetValue(), 0.5);
}

/**
 * Test multiplication assignment of scale and mass fraction.
 */
TEST(MassFractionTestCase, TestMultiplicationAssignment)
{
    seawater::MassFraction fraction{0.25};
    fraction *= 2.;
    EXPECT_DOUBLE_EQ(fraction.GetValue(), 0.5);
}

/**
 * Test addition of two element to mass fraction maps.
 */
TEST(MassFractionsTestCase, TestAddition)
{
    auto hydrogen = std::make_shared<seawater::Element>("H", 1, 1.);
    auto oxygen = std::make_shared<seawater::Element>("O", 8, 16.);

    auto fractions = (
        seawater::MassFractions({{hydrogen, 0.25}}) +
        seawater::MassFractions({{hydrogen, 0.25}}) +
        seawater::MassFractions({{oxygen, 0.5}})
        );

    auto hydrogenFraction = fractions.find(hydrogen);
    ASSERT_NE(hydrogenFraction, std::end(fractions));
    EXPECT_DOUBLE_EQ(hydrogenFraction->second.GetValue(), 0.5);

    auto oxygenFraction = fractions.find(oxygen);
    ASSERT_NE(oxygenFraction, std::end(fractions));
    EXPECT_DOUBLE_EQ(oxygenFraction->second.GetValue(), 0.5);
}

/**
 * Test multiplication of scale and element to mass fraction map.
 */
TEST(MassFractionsTestCase, TestMultiplication)
{
    auto hydrogen = std::make_shared<seawater::Element>("H", 1, 1.);
    auto fractions = 2. * seawater::MassFractions({{hydrogen, 0.5}});

    auto hydrogenFraction = fractions.find(hydrogen);
    ASSERT_NE(hydrogenFraction, std::end(fractions));
    EXPECT_DOUBLE_EQ(hydrogenFraction->second.GetValue(), 1.);
}
