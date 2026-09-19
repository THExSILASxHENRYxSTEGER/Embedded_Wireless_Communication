#pragma once

#include <cstdint>

namespace i2c
{
  
  /**
   * @brief I2C peripheral registers.
   *
   * To enable, use, disable, etc. the I2C peripheral these registers need to be manipulated.
   */
  struct I2C_REGS
  {
    volatile std::uint32_t CR1;       // Control Register 1
    volatile std::uint32_t CR2;       // Control Register 2
    volatile std::uint32_t OAR1;      // Own Address Register 1
    volatile std::uint32_t OAR2;      // Own Address Register 2
    volatile std::uint32_t TIMINGR;   // Timing Register
    volatile std::uint32_t TIMEOUTR;  // Timeout Register
    volatile std::uint32_t ISR;       // Interrupt & Status Register
    volatile std::uint32_t ICR;       // Interrupt Clear Register
    volatile std::uint32_t PECR;      // PEC Register
    volatile std::uint32_t RXDR;      // Receive Data Register
    volatile std::uint32_t TXDR;      // Transmit Data Register
  };
}