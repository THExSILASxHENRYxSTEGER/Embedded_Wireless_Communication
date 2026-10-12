#pragma once

#include <cstdint>

namespace lcd
{
  /**
   * @brief HD44780 instruction opcodes.
   *
   * Each value is the highest set bit of the corresponding instruction.
   * Combine with the matching option enum (e.g. ENTRY_MODE_SET,
   * FUNCTION_SET) using bitwise OR to build the full command byte.
   */
  enum class INSTRUCTION : std::uint32_t
  {
    CLEAR_DISPLAY   = 1u << 0, /**< Clear the display and reset the address counter. */
    RETURN_HOME     = 1u << 1, /**< Move the cursor to the home position and undo any display shift. */
    ENTRY_MODE_SET  = 1u << 2, /**< Set the cursor move direction and display shift behavior. */
    DISPLAY_CONTROL = 1u << 3, /**< Control display, cursor, and blink on/off. */
    CURSOR_SHIFT    = 1u << 4, /**< Move the cursor or shift the display without changing DDRAM. */
    FUNCTION_SET    = 1u << 5, /**< Set interface data length, number of lines, and font. */
    SET_CGRAM_ADDR  = 1u << 6, /**< Set the CGRAM (custom character) address. */
    SET_DDRAM_ADDR  = 1u << 7, /**< Set the DDRAM (display data) address, i.e. the cursor position. */
  };

  /**
   * @brief Option flags for the ENTRY_MODE_SET instruction.
   */
  enum class ENTRY_MODE_SET : std::uint32_t
  {
    SHIFT     = 1u << 0, /**< Shift the display on each write (accompanied display shift). */
    INCREMENT = 1u << 1, /**< Increment the cursor after each write; if unset, decrement. */
  };

  /**
   * @brief Option flags for the DISPLAY_CONTROL instruction.
   */
  enum class DISPLAY_ON_OFF_CONTROL : std::uint32_t
  {
    BLINK  = 1u << 0, /**< Blink the character at the cursor position. */
    CURSOR = 1u << 1, /**< Show the cursor underline. */
    ON     = 1u << 2, /**< Turn the display on; if unset, the display is off (DDRAM is retained). */
  };

  /**
   * @brief Option flags for the CURSOR_SHIFT instruction.
   */
  enum class CURSOR_OR_DISPLAY_SHIFT : std::uint32_t
  {
    RL = 1u << 2, /**< Shift direction: right if set, left if unset. */
    SC = 1u << 3, /**< Shift target: display if set, cursor if unset. */
  };

  /**
   * @brief Option flags for the FUNCTION_SET instruction.
   */
  enum class FUNCTION_SET : std::uint32_t
  {
    FONT        = 1u << 2, /**< Character font: 5x10 dots if set, 5x8 dots if unset. */
    NLINES      = 1u << 3, /**< Number of display lines: two if set, one if unset. */
    DATA_LENGTH = 1u << 4, /**< Interface data length: 8-bit if set, 4-bit if unset. */
  };

  /**
   * @brief Backlight control bit on the PCF8574 expander.
   */
  enum class BACKLIGHT : std::uint32_t
  {
    OFF  = 0,      /**< Backlight off. */
    ON   = 1u << 3, /**< Backlight on. */
  };

  /**
   * @brief Control line bits as wired from the PCF8574 to the HD44780.
   */
  enum class FLAG : std::uint32_t
  {
    RS = 1u << 0, /**< Register select: data register if set, instruction register if unset. */
    RW = 1u << 1, /**< Read/write: read if set, write if unset. */
    EN = 1u << 2, /**< Enable: data is latched on the falling edge of this line. */
  };

  /**
   * @brief Physical layout constants of the connected display.
   */
  namespace DISPLAY
  {
    /** Number of characters per display line. */
    constexpr std::uint32_t LINE_LEN   = 20;

    /** Number of display lines. */
    constexpr std::uint32_t N_LINES    = 2;

    /** Row index of the first line. */
    constexpr std::uint32_t FIRST_ROW  = 0;

    /** Row index of the second line. */
    constexpr std::uint32_t SECOND_ROW = 1;

    /** Row index of the third line. */
    constexpr std::uint32_t THIRD_ROW  = 2;

    /** Row index of the fourth line. */
    constexpr std::uint32_t FOURTH_ROW = 3;
  }

}