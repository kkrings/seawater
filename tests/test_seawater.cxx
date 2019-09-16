/**
 *
 * Unit tests for seawater function
 *
 * (c) 2019
 * Kai Krings
 *
 * @file test_seawater.cxx
 * @date 2019-09-16
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include <gtest/gtest.h>

#include "seawater/seawater.h"

/**
 * Test if the element mass fraction of hydrogen in seawater changes as
 * expected if the practical salinity is changed.
 */
TEST(SeawaterTestCase, TestGetSeawater)
{
    auto water = seawater::GetSeaWater(35e-3);
    auto waterFractions = water.GetMassFractions();
    ASSERT_EQ(waterFractions.cbegin()->first->GetSymbol(), "H");

    auto moreSalt = seawater::GetSeaWater(36e-3);
    auto moreSaltFractions = moreSalt.GetMassFractions();
    ASSERT_EQ(moreSaltFractions.cbegin()->first->GetSymbol(), "H");

    EXPECT_GT(
        waterFractions.cbegin()->second.GetValue(),
        moreSaltFractions.cbegin()->second.GetValue());

    auto lessSalt = seawater::GetSeaWater(34e-3);
    auto lessSaltFractions = lessSalt.GetMassFractions();
    ASSERT_EQ(lessSaltFractions.cbegin()->first->GetSymbol(), "H");

    EXPECT_LT(
        waterFractions.cbegin()->second.GetValue(),
        lessSaltFractions.cbegin()->second.GetValue());
}
