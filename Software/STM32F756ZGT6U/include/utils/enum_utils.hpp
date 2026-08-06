#pragma once

#include <cstdint>
#include <concepts>
#include <type_traits>

/**
 * @brief Converts an enumeration value to its underlying integral type.
 *
 * @tparam E Enumeration type.
 * @param e Enumeration value.
 * @return The underlying integral representation of @p e.
 */
template<typename E>
constexpr auto to_underlying(E e)
{
    return static_cast<std::underlying_type_t<E>>(e);
}

/**
 * @brief Concept that ensures that @tp E is from an enum of underlying type uint32_t.
 * 
 * @tparam E Enumeration type.
 */
template<typename E>
concept RegisterEnum =
    std::is_enum_v<E> &&
    std::same_as<std::underlying_type_t<E>, std::uint32_t>;

/**
 * @brief Performs a bitwise OR between two enumeration values.
 *
 * @tparam E Enumeration type with a std::uint32_t underlying type.
 * @param lhs Left-hand operand.
 * @param rhs Right-hand operand.
 * @return The bitwise OR of @p lhs and @p rhs.
 */
template<RegisterEnum E>
constexpr E operator|(E lhs, E rhs)
{
    return static_cast<E>(to_underlying(lhs) | to_underlying(rhs));
}

/**
 * @brief Performs an in-place bitwise OR assignment.
 *
 * @tparam E Enumeration type with a std::uint32_t underlying type.
 * @param lhs Left-hand operand.
 * @param rhs Right-hand operand.
 * @return Reference to @p lhs.
 */
template<RegisterEnum E>
constexpr E& operator|=(E& lhs, E rhs)
{
    lhs = lhs | rhs;
    return lhs;
}

/**
 * @brief Sets the bits specified by an enumeration value in a memory-mapped register.
 *
 * Intended for use with volatile hardware registers.
 *
 * @tparam E Enumeration type with a std::uint32_t underlying type.
 * @param lhs Reference to the hardware register.
 * @param rhs Bit mask to set.
 * @return Reference to @p lhs.
 */
template<RegisterEnum E>
volatile std::uint32_t& operator|=(volatile std::uint32_t& lhs, E rhs)
{
    lhs = lhs | to_underlying(rhs);
    return lhs;
}

/**
 * @brief Multiplies an enumeration value by an unsigned integer.
 *
 * @tparam E Enumeration type with a std::uint32_t underlying type.
 * @param rhs Enumeration value.
 * @param lhs Unsigned integer.
 * @return The multiplication result.
 */
template<RegisterEnum E>
constexpr std::uint32_t operator*(E rhs, const std::uint32_t lhs)
{
    return lhs * to_underlying(rhs);
}

/**
 * @brief Left-shifts an enumeration value.
 *
 * @tparam E Enumeration type with a std::uint32_t underlying type.
 * @param lhs Enumeration value.
 * @param rhs Number of bit positions.
 * @return The shifted value.
 */
template<RegisterEnum E>
constexpr std::underlying_type_t<E> operator<<(E lhs, const std::uint32_t rhs)
{
    return to_underlying(lhs) << rhs;
}

/**
 * @brief Left-shifts an unsigned integer by an enumeration value.
 *
 * @tparam E Enumeration type with a std::uint32_t underlying type.
 * @param lhs Unsigned integer.
 * @param rhs Enumeration value specifying the shift amount.
 * @return The shifted value.
 */
template<RegisterEnum E>
constexpr std::underlying_type_t<E> operator<<(const std::uint32_t lhs, E rhs)
{
    return lhs << to_underlying(rhs);
}

/**
 * @brief Left-shifts one enumeration value by another.
 *
 * @tparam E1 Left-hand enumeration type.
 * @tparam E2 Right-hand enumeration type.
 * @param lhs Enumeration value to shift.
 * @param rhs Enumeration value specifying the shift amount.
 * @return The shifted value.
 */
template<RegisterEnum E1, RegisterEnum E2>
constexpr std::uint32_t operator<<(E1 lhs, E2 rhs)
{
    return to_underlying(lhs) << to_underlying(rhs);
}

/**
 * @brief Right-shifts an enumeration value.
 *
 * @tparam E Enumeration type with a std::uint32_t underlying type.
 * @param lhs Enumeration value.
 * @param rhs Number of bit positions.
 * @return The shifted value.
 */
template<RegisterEnum E>
constexpr std::underlying_type_t<E> operator>>(E lhs, const std::uint32_t rhs)
{
    return to_underlying(lhs) >> rhs;
}

/**
 * @brief Right-shifts an unsigned integer by an enumeration value.
 *
 * @tparam E Enumeration type with a std::uint32_t underlying type.
 * @param lhs Unsigned integer.
 * @param rhs Enumeration value specifying the shift amount.
 * @return The shifted value.
 */
template<RegisterEnum E>
constexpr std::underlying_type_t<E> operator>>(const std::uint32_t lhs, E rhs)
{
    return lhs >> to_underlying(rhs);
}

/**
 * @brief Right-shifts one enumeration value by another.
 *
 * @tparam E1 Left-hand enumeration type.
 * @tparam E2 Right-hand enumeration type.
 * @param lhs Enumeration value to shift.
 * @param rhs Enumeration value specifying the shift amount.
 * @return The shifted value.
 */
template<RegisterEnum E1, RegisterEnum E2>
constexpr std::uint32_t operator>>(E1 lhs, E2 rhs)
{
    return to_underlying(lhs) >> to_underlying(rhs);
}