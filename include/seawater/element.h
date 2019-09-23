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

/**
 * @brief Two chemical elements compare by their charges.
 *
 * This operator is implemented in order to fill objects of this class into
 * std::map.
 *
 * @param[in] left
 *     Left-hand side chemical element
 * @param[in] right
 *     Right-hand side chemical element
 *
 * @return
 *     A boolean specifying if the charge of the element on the left-hand side
 *     of the operator is smaller than the charge of the element on the
 *     right-hand side of the operator.
 */
inline bool operator<(const Element& left, const Element& right)
{
    return left.GetCharge() < right.GetCharge();
}

/**
 * @brief Two chemical elements compare by their charges.
 *
 * This operator is implemented in order to fill objects of this class into
 * std::map.
 *
 * @param[in] left
 *     Left-hand side chemical element
 * @param[in] right
 *     Right-hand side chemical element
 *
 * @return
 *     A boolean specifying if the charge of the element on the left-hand side
 *     of the operator is larger than the charge of the element on the
 *     right-hand side of the operator.
 */
inline bool operator>(const Element& left, const Element& right)
{
    return left.GetCharge() > right.GetCharge();
}

/// Shared pointer to element
using ElementPtr = std::shared_ptr<Element>;
/// Shared pointer to constant element
using ElementConstPtr = std::shared_ptr<const Element>;

} // namespace seawater
