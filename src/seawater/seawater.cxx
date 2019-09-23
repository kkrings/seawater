/**
 *
 * Implementation of seawater function
 *
 * (c) 2019
 * Kai Krings
 *
 * @file seawater.cxx
 * @date 2019-05-14
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#include "seawater/seawater.h"
#include "seawater/element.h"
#include "seawater/massfraction.h"
#include "seawater/numatoms.h"
#include "seawater/medium.h"

// chemical elements of pure water
static const seawater::Element hydrogen{"H", 1, 1.01};
static const seawater::Element oxygen{"O", 8, 15.999};

// most abundant chemical elements dissolved in ocean standard seawater
static const seawater::Element sodium{"Na", 11, 22.990};
static const seawater::Element magnesium{"Mg", 12, 24.305};
static const seawater::Element calcium{"Ca", 20, 40.078};
static const seawater::Element potassium{"K", 19, 39.098};
static const seawater::Element sulfur{"S", 16, 32.065};
static const seawater::Element chlorine{"Cl", 17, 35.453};

seawater::Medium seawater::GetSeaWater(
    double practicalSalinity, double massDensity)
{
    Molecule water = {{hydrogen, 2}, {oxygen, 1}};

    MassFractions salt = {
        {sodium, 10.78145e-3},
        {magnesium, 1.28372e-3},
        {calcium, 0.41208e-3},
        {potassium, 0.3991e-3},
        {chlorine, 19.35271e-3}
        };

    salt += 2.71235e-3 * Molecule{{{sulfur, 1}, {oxygen, 4}}};

    double norm = 0.;
    for (const auto& fraction : salt)
    {
        norm += fraction.second.GetValue();
    }

    double absoluteSalinity = practicalSalinity * 35.16504e-3 / 35e-3;

    MassFractions fractions = (
        (1. - absoluteSalinity)*water + absoluteSalinity/norm*salt);

    return Medium(fractions, massDensity);
}
