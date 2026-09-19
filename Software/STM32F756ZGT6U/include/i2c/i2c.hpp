#pragma once

#include "i2c/i2c_bits.hpp"
#include "i2c/i2c_regs.hpp"
#include "global/addresses.hpp"
#include "input_buffer/input_buffer.hpp"

#include <cstdint>

namespace i2c
{
  /**
   * @brief I2C peripheral class.
   * 
   */
  class I2C
  {
    public:
      
    /**
     * @brief Construct a new I2C peripheral controlling object.
     * 
     * @param i2c_address The physical memory address of the corresponding I2C peripheral.
     */
      I2C(const std::uint32_t i2c_address);

      /**
       * @brief Initialize the I2C peripheral and scan for a connected I2C slave address.
       * 
       * @param PRESC Timing prescaler.
       * @param SCLL System Clock low period.
       * @param SCLH System Clock high period.
       * @param SDADEL Data hold time.
       * @param SCLDEL Data setup time.
       * 
       * @return true The I2c initialization succeeded.
       * @return false The I2c initialization failed.
       */
      bool init(
        std::uint32_t PRESC, 
        std::uint32_t SCLL, 
        std::uint32_t SCLH, 
        std::uint32_t SDADEL, 
        std::uint32_t SCLDEL
      );

      /**
       * @brief Send an entire string to the I2C transmit buffer one byte at a time.
       * 
       * @param str The string to be sent via the I2C peripheral.
       * 
       * The String has to end with the '\0' character, otherwise this is undefined behavior.
       */
      void send_string(const char* str);

      /**
       * @brief Send an entire string to the I2C transmit buffer one byte at a time.
       * 
       * @param ib The input buffer abstracting the string to be sent via the I2C peripheral.
       */
      void send_string(input_buffer::INPUT_BUFFER<global_vars::MAX_INPUT_LEN>& ib);

      /**
       * @brief Push one byte corresponding to one keystroke into the I2C transmit buffer.
       * 
       * @param c The byte to be transmitted through the I2C transmit buffer.
       * 
       * This function writes exactly one byte into the NBYTES part of the CR2 register.
       * This function is specifically for keystrokes, where the time in between strokes that 
       * needs to be clock stretched is unknown and therefore sending one byte at a time is optimal.
       */
      void send_byte(char c);

      ~I2C() = default;

    private:
      
      /** The I2C peripheral registers */
      volatile I2C_REGS* i2c_regs_;

      /** I2C slave address
       * 
       * Currently, this class only supports one slave connection.
       * This is the address of that slave.
       */
      std::uint32_t slave_addr_;

      /**
       * @brief Push a character to the I2C transmit FIFO.
       * 
       * @param c The character to be pushed
       */
      void push(char c);

      /**
       * @brief Initialize an I2C write transaction.
       * 
       * @param len The length of the string to be written.
       * 
       * To write bytes to a slave, a transaction needs to be intiated.
       * That is, the bytes in CR2 NBYTES need to be set, and the AUTOEND,
       * RELOAD and the RESTART bits need to be set accordingly.
       */
      void set_write(std::uint32_t len);

  };

  /** I2C peripheral 1 */
  inline I2C i2c1(addresses::I2C1);
  /** I2C peripheral 2 */
  inline I2C i2c2(addresses::I2C2);
  /** I2C peripheral 3 */
  inline I2C i2c3(addresses::I2C3);
  /** I2C peripheral 4 */
  inline I2C i2c4(addresses::I2C4);
    
} 


// write 2 functions for i2c interface, one that prints a string of fixed length setting NBYTES to this length (atoreload etc.)
// and another for continuous typing which sets NBYTES to 1 always and just upon each char arrival prints this char