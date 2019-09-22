/**
 *
 * Unit tests for Medium class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file test_medium.cxx
 * @date 2019-09-06
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include <memory>
#include <stdexcept>

#include <gtest/gtest.h>

#include "seawater/element.h"
#include "seawater/numatoms.h"
#include "seawater/medium.h"

/**
 * Test the member variables fractions_ and density_ after initialization.
 */
TEST(MediumTestCase, TestInit)
{
    auto hydrogen = std::make_shared<const seawater::Element>("H", 1, 1.);
    auto oxygen = std::make_shared<const seawater::Element>("O", 8, 16.);

    auto reference = seawater::GetMassFractions({{hydrogen, 2}, {oxygen, 1}});
    seawater::Medium water{reference, 1.};

    EXPECT_DOUBLE_EQ(water.GetDensity(), 1.);

    auto fractions = water.GetMassFractions();
    EXPECT_EQ(fractions.size(), 2);

    auto hydrogenFraction = fractions.find(hydrogen);
    ASSERT_NE(hydrogenFraction, std::end(fractions));

    EXPECT_DOUBLE_EQ(
        hydrogenFraction->second.GetValue(),
        reference.at(hydrogen).GetValue()
        );

    auto oxygenFraction = fractions.find(oxygen);
    ASSERT_NE(oxygenFraction, std::end(fractions));

    EXPECT_DOUBLE_EQ(
        oxygenFraction->second.GetValue(),
        reference.at(oxygen).GetValue()
        );
}

/**
 * Test expected exception from initialization.
 */
TEST(MediumTestCase, TestExceptionInit)
{
    auto hydrogen = std::make_shared<const seawater::Element>("H", 1, 1.);
    auto oxygen = std::make_shared<const seawater::Element>("O", 8, 16.);

    EXPECT_THROW(
        seawater::Medium({{hydrogen, 0.4}, {oxygen, 0.4}}, 1.),
        std::invalid_argument
        );

    EXPECT_THROW(
        seawater::Medium({{hydrogen, 0.6}, {oxygen, 0.6}}, 1.),
        std::invalid_argument
        );
}
