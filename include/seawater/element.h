/**
 *
 * Definition of chemical element class
 *
 * (c) 2019
 * Kai Krings
 *
 * @file element.h
 * @date 2019-04-24
 * @author Kai Krings <kai.krings@posteo.de>
 *
 */
#pragma once

#include <map>
#include <memory>
#include <string>

namespace seawater {

/**
 * @brief Chemical element
 *
 * This class represents a chemical element, which has a specific atomic
 * charge and weight. Each element is identified by a specific symbol.
 */
class Element
{
    public:
        /**
         * Access the minimum allowed atomic charge.
         *
         * @return
         *     Minimum atomic charge
         */
        static constexpr int GetMinCharge()
        {
            return 1;
        }

        /**
         * Access the minimum allowed atomic weight.
         *
         * @return
         *     Minimum atomic weight
         */
        static constexpr double GetMinWeight()
        {
            return 1.;
        }

        /**
         * Construct a new chemical element.
         *
         * @param[in] symbol
         *     Element's symbol
         * @param[in] charge
         *     Element's atomic charge
         * @param[in] weight
         *     Element's atomic weight
         */
        Element(
                const std::string& symbol,
                const int charge,
                const double weight)
            : symbol_{symbol},
            charge_{charge},
            weight_{weight}
        {
            CheckParameters();
        }

        /// This class is not default constructable.
        Element() = delete;
        /// This class is not copy constructable.
        Element(const Element&) = delete;
        /// This class uses the default move constructor.
        Element(Element&&) = default;

        /// This class is not copy assignable.
        Element& operator=(const Element&) = delete;
        /// This class uses the default move assign operator.
        Element& operator=(Element&&) = default;

        /// This class uses the default destructor.
        ~Element() = default;

        /**
         * @brief Two chemical elements compare by their charges.
         *
         * This operator is implemented in order to fill objects of this class
         * into std::map.
         *
         * @param[in] element
         *     Another chemical element
         *
         * @return
         *     A boolean specifying if this element's charge is smaller than
         *     the one of the other element.
         */
        bool operator<(const Element& element) const
        {
            return charge_ < element.GetCharge();
        }

        /**
         * @brief Two chemical elements compare by their charges.
         *
         * The operators '<' and '>' should be provided together.
         *
         * @param[in] element
         *     Another chemical element
         *
         * @return
         *     A boolean specifying if this element's charge is larger than
         *     the one of the other element.
         */
        bool operator>(const Element& element) const
        {
            return charge_ > element.GetCharge();
        }

        /**
         * Access the element's symbol.
         *
         * @return
         *     Element's symbol
         */
        std::string GetSymbol() const
        {
            return symbol_;
        }

        /**
         * Access the element's atomic charge.
         *
         * @return
         *     Element's atomic charge
         */
        int GetCharge() const
        {
            return charge_;
        }

        /**
         * Access the element's atomic weight.
         *
         * @return
         *     Element's atomic weight
         */
        double GetWeight() const
        {
            return weight_;
        }

    private:
        /// Element's symbol
        const std::string symbol_;
        /// Element's atomic charge
        const int charge_;
        /// Element's atomic weight
        const double weight_;

        /**
         * Check that both the specified atomic charge and weight are
         * equal or greater than their minimum allowed values.
         */
        void CheckParameters();
};

using ElementPtr = std::shared_ptr<Element>;
using ElementConstPtr = std::shared_ptr<const Element>;

} // namespace seawater
