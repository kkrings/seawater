.. _composition:

Seawater composition
====================

The composition of seawater is based on the six most important (by reference
salinity :math:`S_{R}`) materials dissolved in *Standard Seawater*, according
to [Millero2008]_:

.. table::

   ========= ================== ============================
   Material  Reference salinity Most abundant compound
   ========= ================== ============================
   Sodium    10.78145           :math:`\mathrm{N}^{+}`
   Magnesium  1.28372           :math:`\mathrm{Mg}^{2+}`
   Calcium    0.41208           :math:`\mathrm{Ca}^{2+}`
   Potassium  0.39910           :math:`\mathrm{K}^{+}`
   Chlorine  19.35271           :math:`\mathrm{Cl}^{-}`
   Sulfate    2.71235           :math:`\mathrm{SO}_{4}^{2-}`
   ========= ================== ============================

After correcting for the missing materials via renormalization, the element
mass fractions are scaled by

.. math::

   S_{R} = S_{P} \times 35.16504/35,

where :math:`S_{P}` is the practical salinity of the ocean site of interest,
and combined with :math:`1 - S_{R}` of pure water.


The following examples show how to calculate the composition of seawater given
a practical salinity by using both the project's C++ and the Python interface,
respectively.

.. note::

   Here, composition refers to the mass fractions :math:`f_{i}` of all the
   elements seawater consists of. Moreover, an effective number of
   atoms :math:`n_{i}` is calculated for each element:

   .. math::

      n_{i} = f_{i} \times w_{\mathrm{tot}} / w_{i}.

   An effective total weight :math:`w_{\mathrm{tot}}` of seawater is chosen,
   which gives two hydrogen atoms.


C++ library
-----------

The following example shows how to obtain the composition of seawater in C++
by using the function :cpp:func:`seawater::GetSeaWater`:

.. code-block:: cpp

   #include <iomanip>
   #include <iostream>

   #include <seawater/element.h>
   #include <seawater/seawater.h>

   int main()
   {
       auto seawater = seawater::GetSeaWater(35e-3, 1.);

       const auto& fractions = seawater.GetMassFractions();
       seawater::Element hydrogen{"H", 1, 1.01};

       double weight  = (
           2. * hydrogen.GetWeight() /
           fractions.at(hydrogen).GetValue()
           );

       for (const auto& element : fractions)
       {
           double atoms = (
               element.second.GetValue() * weight /
               element.first.GetWeight()
               );

           std::cout << "Element "
                     << std::setw(2)
                     << element.first.GetSymbol()
                     << ": mass fraction = "
                     << std::setw(7)
                     << std::setprecision(4)
                     << std::fixed
                     << element.second.GetValue() * 100.
                     << "%, effective number of atoms = "
                     << std::scientific
                     << atoms
                     << std::endl;

       }
   }

The returned :cpp:class:`seawater::Medium` object could for example be used to
create a seawater material for detector simulations with `Geant4`_.

.. _Geant4:
   http://geant4.web.cern.ch/


Python module
-------------

The same result can also be obtained in Python by using
the :func:`pyseawater.seawater` function:

.. code-block:: python

   import pyseawater

   seawater = pyseawater.seawater(salinity=35e-3, density=1.)
   fractions = seawater.fractions()

   hydrogen = {
       element.symbol: element
       for element in fractions.keys()
       }["H"]

   weight = 2. * hydrogen.weight / fractions[hydrogen]

   for (element, fraction) in fractions.items():
       print(
           "Element {symbol:2}: "
           "mass fraction = {fraction:8.4%}, "
           "effective number of atoms = {atoms:.4e}".format(
               symbol=element.symbol,
               fraction=fraction,
               atoms=fraction * weight / element.weight
               )
           )


.. [Millero2008]
   F. J. Millero et al., Deep Sea Research Part I: Oceanographic Research
   Papers 55.1 (2008), pp. 50-72.
