#include "basic_timer/basic_timer_bits.hpp"
#include "lcd/lcd.hpp"
#include "lcd/lcd_bits.hpp"
#include "utils/bit_manipultion.hpp"
#include "utils/enum_utils.hpp"

#include <functional>

namespace lcd
{
  LCD::LCD(i2c::I2C& i2c, basic_timer::BasicTimer& basic_timer)
  :
    i2c_(i2c),
    basic_timer_(basic_timer)
  {}
  
  void LCD::backlight(bool on)
  {
    // Store the requested backlight state
    if (on)
    {
      backlight_ = static_cast<std::uint8_t>(BACKLIGHT::ON);
    } else {
      backlight_ = static_cast<std::uint8_t>(BACKLIGHT::OFF);
    }
    // Send an empty byte so the new backlight state takes effect
    write_i2c(0);
  }

  void LCD::print(char* message)
  {
    // Clear the display before printing
    command(static_cast<char>(INSTRUCTION::CLEAR_DISPLAY));
    // Send each character as data until the null terminator
    for (std::uint32_t i = 0; message[i] != '\0'; i++)
      send(message[i], static_cast<char>(FLAG::RS)); 
  }

  void LCD::print(input_buffer::INPUT_BUFFER<global_vars::MAX_INPUT_LEN>& ib)
  {
    // Clear the display
    command(static_cast<char>(INSTRUCTION::CLEAR_DISPLAY));
    // Print at most as many characters as the display can show
    for (std::uint32_t i = 0; i < DISPLAY::LINE_LEN*DISPLAY::N_LINES; i++)
    {
      // Stop at the end of the buffer content
      if (ib[i] == '\0')
        return;
      // In case the lcd line breaks here dont show empty slot or new line 
      if ((i % DISPLAY::LINE_LEN == 0 && ib[i] == ' ') || ib[i] == '\n')
        continue;
      // Print the character to the lcd
      send(ib[i], static_cast<char>(FLAG::RS));
    }
  }

  void LCD::write_i2c(char data)
  {
    // Add the backlight bit to the data
    char value = data | BACKLIGHT::ON;
    // Transmit the byte to the PCF8574
    i2c_.send_byte(value);
  }

  void LCD::pulse(char data)
  {
    // Set EN high
    write_i2c(data | FLAG::EN);
    // Hold EN high
    basic_timer_.wait_for(5, basic_timer::DURATION::MILLI_SECONDS);
    
    // Set EN low, which latches the data
    write_i2c(data & ~FLAG::EN); 
    // Let the display process the data
    basic_timer_.wait_for(1, basic_timer::DURATION::MILLI_SECONDS);
  }

  void LCD::write_4bits(char data)
  {
    // Put the nibble on the data lines
    write_i2c(data);
    // Latch the nibble into the display
    pulse(data);
  }

  void LCD::send(char data, char mode)
  {
    // Send the high nibble
    write_4bits((data & 0xF0) | mode);
    // Send the low nibble
    write_4bits(((data << global_vars::EIGTH_REG_SZ) & 0xF0) | mode);
  }

  void LCD::command(char command)
  {
    // Mode 0 selects the instruction register
    send(command, 0);
  }

  void LCD::init()
  {
    // Reset sequence: send 0x3 three times to force 8-bit mode
    write_4bits(0x3 << global_vars::EIGTH_REG_SZ);
    basic_timer_.wait_for(0x5, basic_timer::DURATION::MILLI_SECONDS);
    write_4bits(0x3 << global_vars::EIGTH_REG_SZ);
    basic_timer_.wait_for(0x1, basic_timer::DURATION::MILLI_SECONDS);
    write_4bits(0x3 << global_vars::EIGTH_REG_SZ);
    // Switch to 4-bit mode
    write_4bits(0x2 << global_vars::EIGTH_REG_SZ);

    // 4-bit interface, two lines
    command(INSTRUCTION::FUNCTION_SET | FUNCTION_SET::NLINES);
    // Display on, cursor and blink off
    command(INSTRUCTION::DISPLAY_CONTROL | DISPLAY_ON_OFF_CONTROL::ON);
    // Clear the display
    command(
      static_cast<char>(INSTRUCTION::CLEAR_DISPLAY)
    );
    // Clear needs a long execution time
    basic_timer_.wait_for(0x2, basic_timer::DURATION::MILLI_SECONDS);

    // Move the cursor right after each write, no display shift
    command(INSTRUCTION::ENTRY_MODE_SET | ENTRY_MODE_SET::INCREMENT);
    // Move the cursor to the home position
    command(
      static_cast<char>(INSTRUCTION::RETURN_HOME)
    );
    // Return home needs a long execution time
    basic_timer_.wait_for(0x2, basic_timer::DURATION::MILLI_SECONDS);
  }
}