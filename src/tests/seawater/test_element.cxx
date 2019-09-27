/**
 *
 * Unit tests for Element class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file test_element.cxx
 * @date 2019-08-26
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include <stdexcept>

#include <gtest/gtest.h>

#include "seawater/element.h"

/**
 * Test the static member function GetMinCharge.
 */
TEST(ElementTestCase, TestMinCharge)
{
    EXPECT_EQ(seawater::Element::GetMinCharge(), 1);
}

/**
 * Test the static member function GetMinWeight.
 */
TEST(ElementTestCase, TestMinWeight)
{
    EXPECT_DOUBLE_EQ(seawater::Element::GetMinWeight(), 1.);
}

/**
 * Test the constant member variable symbol_.
 */
TEST(ElementTestCase, TestSymbol)
{
    seawater::Element hydrogen{"H", 1, 1.};
    EXPECT_EQ(hydrogen.GetSymbol(), "H");
}

/**
 * Test the constant member variable charge_.
 */
TEST(ElementTestCase, TestCharge)
{
    seawater::Element hydrogen{"H", 1, 1.};
    EXPECT_EQ(hydrogen.GetCharge(), 1);
}

/**
 * Test expected exceptions from initialization.
 */
TEST(ElementTestCase, TestChargeException)
{
    EXPECT_THROW(seawater::Element("H", 0, 1.), std::invalid_argument);
}

/**
 * Test the constant member variable weight_.
 */
TEST(ElementTestCase, TestWeight)
{
    seawater::Element hydrogen{"H", 1, 1.};
    EXPECT_DOUBLE_EQ(hydrogen.GetWeight(), 1.);
}

/**
 * Test expected exceptions from initialization.
 */
TEST(ElementTestCase, TestWeightException)
{
    EXPECT_THROW(seawater::Element("H", 1, 0.), std::invalid_argument);
}

/**
 * Test the less than operator.
 */
TEST(ElementTestCase, TestLTOperator)
{
    seawater::Element hydrogen{"H", 1, 1.};
    seawater::Element oxygen{"O", 8, 16.};

    EXPECT_LT(hydrogen, oxygen)
        << "Hydrogen is expected to be smaller than oxygen "
        << "in terms of charge.";
}
/**
 * Test the greater than operator.
 */
TEST(ElementTestCase, TestGTOperator)
{
    seawater::Element hydrogen{"H", 1, 1.};
    seawater::Element oxygen{"O", 8, 16.};

    EXPECT_GT(oxygen, hydrogen)
        << "Oxygen is expected to be greater than hydrogen "
        << "in terms of charge.";
}
