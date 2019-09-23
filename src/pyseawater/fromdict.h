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
 * number of atoms maps. If the dictionary's values are not of type amount, the
 * amount's internal value type is extracted.
 *
 * @tparam MapElementAmount
 *     Type of STL element to amount map
 * @tparam Value
 *     Amount's internal value type, e.g. double for mass fraction type and int
 *     for number of atoms type, respectively.
 *
 * @param[in] elemenDict
 *     Python dictionary that contains pairs of element and amount
 *
 * @returns
 *     Element to amount map
 */
template<typename MapElementAmount, typename Value>
std::shared_ptr<MapElementAmount> FromDict(const bp::dict& elementDict)
{
    using Amount = typename MapElementAmount::mapped_type;

    bp::list items = elementDict.items();

    MapElementAmount elementMap;
    for(int i = 0, n = bp::len(items); i < n; ++i)
    {
        bp::tuple item = bp::extract<bp::tuple>(items[i]);

        Element element = bp::extract<Element>(item[0]);

        bp::extract<Amount&> value{item[1]};
        if (value.check())
        {
            Amount& amount = value();
            elementMap.emplace(element, amount);
        }
        else
        {
            Value amount = bp::extract<Value>(item[1]);
            elementMap.emplace(element, amount);
        }
    }

    return std::make_shared<MapElementAmount>(elementMap);
}

} // namespace python
} // namespace seawater
