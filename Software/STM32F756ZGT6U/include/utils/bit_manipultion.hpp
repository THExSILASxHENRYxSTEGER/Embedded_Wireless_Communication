/**
 * @file bit_manipulation.hpp
 * @brief Helper functions for bit manipulation.
 */
#pragma once

#include <cstdint>
#include <concepts>
#include <type_traits>

#include "utils/enum_utils.hpp"

/**
 * @brief Analogue of |= on regular unsigned 32 bit registers.
 *
 * @param reg The register to be manipulated.
 * @param bits The bits to be set.
 */
inline void set_bits(volatile std::uint32_t& reg, std::uint32_t bits)
{
    reg = reg | bits;
}

/**
 * @brief Analogue of |= on enum type registers.
 *
 * @param reg The enum type register to be manipulated.
 * @param bits The bits to be set.
 */
template<RegisterEnum E>
inline void set_bits(volatile std::uint32_t& reg, E bits)
{
    reg = reg | to_underlying(bits);
}

/**
 * @brief Analogue of &= ~mask on regular unsigned 32 bit registers.
 *
 * @param reg The register to be manipulated.
 * @param bits The bits to be inverted and set.
 */
inline void clear_bits(volatile std::uint32_t& reg, std::uint32_t bits)
{
    reg = reg & ~bits;
}

/**
 * @brief Analogue of &= ~mask on enum type registers.
 *
 * @param reg The enum type register to be manipulated.
 * @param bits The bits to be inverted and set.
 */
template<RegisterEnum E>
inline void clear_bits(volatile std::uint32_t& reg, E bits)
{
    reg = reg & ~to_underlying(bits);
}

/**
 * @brief Analogue of ^= (i.e. toggle bits).
 *
 * @param reg The register to be manipulated.
 * @param bits The bits to be toggled.
 */
inline void toggle_bits(volatile std::uint32_t& reg, std::uint32_t bits)
{
    reg = reg ^ bits;
}

/**
 * @brief Analogue of ^= (i.e. toggle bits) on enum type registers.
 *
 * @param reg The enum type register to be manipulated.
 * @param bits The bits to be toggled.
 */
template<RegisterEnum E>
inline void toggle_bits(volatile std::uint32_t& reg, E bits)
{
    reg = reg ^ to_underlying(bits);
}

/**
 * @brief Read only test to see if a bit is set within a register.
 *
 * @param reg The register to be checked.
 * @param bits The bits to be checked.
 */
inline bool test_bits(volatile std::uint32_t& reg, std::uint32_t bits)
{
    return (reg & bits) == bits;
}

/**
 * @brief Read only test to see if a bit is set within an enum type register.
 *
 * @param reg The enum type register to be checked.
 * @param bits The bits to be checked.
 */template<RegisterEnum E>
inline bool test_bits(volatile std::uint32_t& reg, E bits)
{
    return (reg & to_underlying(bits)) == to_underlying(bits);
}