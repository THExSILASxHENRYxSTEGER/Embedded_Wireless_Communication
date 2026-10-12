#pragma once

#include "basic_timer/basic_timer.hpp"
#include "global/global_vars.hpp"
#include "i2c/i2c.hpp"
#include "input_buffer/input_buffer.hpp"

namespace lcd
{
  /**
   * @brief LCD interface class.
   * 
   * Data is displayed on an LCD that uses a PCF8574 connected to an HD44780.
   * Communication relies on the I2C protocol.
   */
  class LCD
  {
    public:

      /**
       * @brief Construct a new LCD object.
       * 
       * This class handles communication with the physical display.
       * The LCD display communicates exclusively via I2C and 
       * needs to wait a set amount of time between instructions.
       * 
       * @param i2c The I2C peripheral connected to the PCF8574 chip.
       * @param basic_timer The timer to set waiting times after each display instruction.
       */
      LCD(i2c::I2C& i2c, basic_timer::BasicTimer& basic_timer);
      
      /**
       * @brief Turn the backlight of the LCD on and off.
       * 
       * @param on If true set the backlight on else off.
       */
      void backlight(bool on);

      /**
       * @brief Print a string to the LCD display.
       * 
       * @param message The null-terminated string to be printed.
       */
      void print(char* message);

      /**
       * @brief Print the contents of an input buffer to the LCD display.
       * 
       * Prints the characters currently held in the buffer, continuing
       * from the last printed position (see @c text_idx_).
       * 
       * @param ib The input buffer whose contents are to be printed.
       */
      void print(input_buffer::INPUT_BUFFER<global_vars::MAX_INPUT_LEN>& ib);

      /**
       * @brief Write a single raw byte to the PCF8574 over I2C.
       * 
       * The backlight bit is combined with the data before transmission.
       * 
       * @param data The byte to be written to the PCF8574 expander.
       */
      void write_i2c(char data);

      /**
       * @brief Pulse the enable (E) line of the HD44780.
       * 
       * Latches the data currently present on the data lines into the display
       * by toggling the enable bit high and then low, honoring the required
       * wait times.
       * 
       * @param data The byte (data and control bits) to be latched.
       */
      void pulse(char data);

      /**
       * @brief Write a 4-bit nibble to the display.
       * 
       * Places the nibble on the data lines and pulses the enable line.
       * 
       * @param data The byte whose upper nibble is to be written.
       */
      void write_4bits(char data);

      /**
       * @brief Send a full byte to the display in 4-bit mode.
       * 
       * Splits the byte into high and low nibbles and writes them in sequence.
       * 
       * @param data The byte to be sent.
       * @param mode The register select mode (command or data).
       */
      void send(char data, char mode);

      /**
       * @brief Send a command instruction to the display.
       * 
       * Convenience wrapper around send() that selects command mode.
       * 
       * @param command The HD44780 command byte (e.g. clear display, set cursor).
       */
      void command(char command);

      /**
       * @brief Initialize the LCD display.
       * 
       * Executes the HD44780 initialization sequence to put the display into
       * 4-bit mode and configure it for use.
       */
      void init();
      
      /** @brief Default destructor. */
      ~LCD() = default;
    
    private:

      /** I2C interface to the PCF8574 */
      i2c::I2C& i2c_;

      /** Timer to uphold instruction wait durations of HD44780 */
      basic_timer::BasicTimer& basic_timer_;

      /** The backlight value */
      std::uint8_t backlight_;

      /** The current index of the text in the input buffer */
      std::uint8_t text_idx = 0;
  };  

  /** LCD instance */
  inline LCD lcd(i2c::i2c2, basic_timer::basic_timer_6);
}