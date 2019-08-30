/**
 *
 * Unit tests for NumAtoms class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file test_numatoms.cxx
 * @date 2019-08-30
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include <memory>

#include <gtest/gtest.h>

#include "seawater/element.h"
#include "seawater/numatoms.h"

/**
 * Test the static member function GetMin.
 */
TEST(NumAtomsTestCase, TestGetMin)
{
    EXPECT_EQ(seawater::NumAtoms::GetMin(), 1);
}

/**
 * Test the member variable value_ after initialization.
 */
TEST(NumAtomsTestCase, TestValueInit)
{
    seawater::NumAtoms atoms{1};
    EXPECT_EQ(atoms.GetValue(), 1);
}

/**
 * Test expected exception from initialization.
 */
TEST(NumAtomsTestCase, TestExceptionValueInit)
{
    EXPECT_THROW(seawater::NumAtoms(0), std::invalid_argument);
}

/**
 * Test the free function GetWeight.
 */
TEST(MoleculeTestCase, TestGetWeight)
{
    auto hydrogen = std::make_shared<const seawater::Element>("H", 1, 1.);

    EXPECT_DOUBLE_EQ(
        seawater::GetWeight({{hydrogen, 1}}), hydrogen->GetWeight());

    EXPECT_DOUBLE_EQ(
        seawater::GetWeight({{hydrogen, 2}}), 2.*hydrogen->GetWeight());
}
