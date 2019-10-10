/**
 *
 * Definition of conversion function from Python dictionaries to element maps
 *
 * (c) 2019
 * Kai Krings
 *
 * @file fromdict.h
 * @date 2019-06-06
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#pragma once

#include <memory>

#include <boost/python.hpp>

#include "seawater/element.h"

namespace bp = boost::python;

namespace seawater {
namespace python {

/**
 * @brief Extract element to amount map from Python dictionary.
 *
 * Extract pairs of element and amount from a Python dictionary and copy these
 * to a STL element to amount map, e.g. element to mass fraction or element to
 * number of atoms maps.
 *
 * @tparam ElementAmountMap
 *     Type of STL element to amount map
 * @tparam Value
 *     Amount's internal value type, e.g. double for mass fraction type and int
 *     for number of atoms type, respectively.
 *
 * @param[in] elementAmountDict
 *     Python dictionary that contains pairs of element and amount
 *
 * @returns
 *     Element to amount map
 */
template<typename ElementAmountMap, typename Value>
std::shared_ptr<ElementAmountMap> FromDict(const bp::dict& elementAmountDict)
{
    using Amount = typename ElementAmountMap::mapped_type;
    bp::list elements = elementAmountDict.keys();

    ElementAmountMap elementAmountMap;
    for(int i = 0, n = bp::len(elements); i < n; ++i)
    {
        bp::object element = elements[i];

        elementAmountMap.emplace(
            bp::extract<Element>(element),
            bp::extract<Value>(elementAmountDict[element]));
    }

    return std::make_shared<ElementAmountMap>(elementAmountMap);
}

/**
 * @brief Element to amount map to Python dictionary.
 *
 * Copy entries of element to amount map into a Python dictionary.
 *
 * @tparam ElementAmountMap
 *     Type of STL element to amount map
 *
 * @param[in] elementAmountMap
 *     Element to amount map
 *
 * @returns
 *     Python dictionary
 */
template<typename ElementAmountMap>
bp::dict ToDict(const ElementAmountMap& elementAmountMap)
{
    bp::dict elementAmountDict;
    for(const auto& elementAmountPair : elementAmountMap)
    {
        elementAmountDict[elementAmountPair.first] =
            elementAmountPair.second.GetValue();
    }

    return elementAmountDict;
}

} // namespace python
} // namespace seawater
