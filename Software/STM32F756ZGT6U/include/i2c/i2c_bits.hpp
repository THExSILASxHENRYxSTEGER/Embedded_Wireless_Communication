#pragma once

#include <cstdint>

namespace i2c
{

  /** I2C clock standard mode values for 100kHz at 16 MHz sysclk*/
  namespace TIMING_CONST
  {
    namespace SYSCLK_16_MHZ
    {
      namespace Sm_100_KHZ
      {
        const std::uint32_t PRESC = 0x3;
        const std::uint32_t SCLL = 0x13;
        const std::uint32_t SCLH = 0xF;
        const std::uint32_t SDADEL = 0x2;
        const std::uint32_t SCLDEL = 0x4;
      }  
    }
  }

  /**
   * @brief I2C Slave Mster address_Range
   * 
   */
  namespace I2C_Address
  {
    const std::uint32_t MAX_ADDRESS_7_BIT = 0x7F;
    const std::uint32_t MAX_ADDRESS_10_BIT = 0x1FF;
  }

  /**
   * @brief I2C Control Register 1 (I2C_CR1) bits.
   *
   * Use these values to manipulate the I2C_CR1 register.
   */
  enum class CR1 : std::uint32_t
  {
    PE        = 1u << 0,   // Peripheral enable
    TXIE      = 1u << 1,   // TX interrupt enable
    RXIE      = 1u << 2,   // RX interrupt enable
    ADDRIE    = 1u << 3,   // Address match interrupt enable
    NACKIE    = 1u << 4,   // NACK received interrupt enable
    STOPIE    = 1u << 5,   // STOP detection interrupt enable
    TCIE      = 1u << 6,   // Transfer complete interrupt enable
    ERRIE     = 1u << 7,   // Errors interrupt enable
    DNF0      = 1u << 8,   // Digital noise filter bit 0
    DNF1      = 1u << 9,   // Digital noise filter bit 1
    DNF2      = 1u << 10,  // Digital noise filter bit 2
    DNF3      = 1u << 11,  // Digital noise filter bit 3
    ANFOFF    = 1u << 12,  // Analog noise filter off
    SWRST     = 1u << 13,  // Software reset
    TXDMAEN   = 1u << 14,  // DMA transmission requests enable
    RXDMAEN   = 1u << 15,  // DMA reception requests enable
    SBC       = 1u << 16,  // Slave byte control
    NOSTRETCH = 1u << 17,  // Clock stretching disable
    WUPEN     = 1u << 18,  // Wakeup from Stop mode enable
    GCEN      = 1u << 19,  // General call enable
    SMBHEN    = 1u << 20,  // SMBus host address enable
    SMBDEN    = 1u << 21,  // SMBus device default address enable
    ALERTEN   = 1u << 22,  // SMBus alert enable
    PECEN     = 1u << 23,  // PEC enable
  };

  /**
   * @brief I2C Control Register 2 (I2C_CR2) bits.
   *
   * Use these values to manipulate the I2C_CR2 register.
   */
  enum class CR2 : std::uint32_t
  {
    SADD0     = 1u << 0,   // Slave address bit 0 (10-bit mode)
    SADD1     = 1u << 1,   // Slave address bit 1
    SADD2     = 1u << 2,   // Slave address bit 2
    SADD3     = 1u << 3,   // Slave address bit 3
    SADD4     = 1u << 4,   // Slave address bit 4
    SADD5     = 1u << 5,   // Slave address bit 5
    SADD6     = 1u << 6,   // Slave address bit 6
    SADD7     = 1u << 7,   // Slave address bit 7
    SADD8     = 1u << 8,   // Slave address bit 8
    SADD9     = 1u << 9,   // Slave address bit 9
    RD_WRN    = 1u << 10,  // Transfer direction (0=write, 1=read)
    ADD10     = 1u << 11,  // 10-bit addressing mode enable
    HEAD10R   = 1u << 12,  // 10-bit address header only read direction
    START     = 1u << 13,  // START generation
    STOP      = 1u << 14,  // STOP generation
    NACK      = 1u << 15,  // NACK generation
    NBYTES0   = 1u << 16,  // Number of bytes to transfer bit 0
    NBYTES1   = 1u << 17,  // Number of bytes to transfer bit 1
    NBYTES2   = 1u << 18,  // Number of bytes to transfer bit 2
    NBYTES3   = 1u << 19,  // Number of bytes to transfer bit 3
    NBYTES4   = 1u << 20,  // Number of bytes to transfer bit 4
    NBYTES5   = 1u << 21,  // Number of bytes to transfer bit 5
    NBYTES6   = 1u << 22,  // Number of bytes to transfer bit 6
    NBYTES7   = 1u << 23,  // Number of bytes to transfer bit 7
    RELOAD    = 1u << 24,  // NBYTES reload mode
    AUTOEND   = 1u << 25,  // Automatic end mode
    PECBYTE   = 1u << 26,  // Packet error checking byte transfer
  };

  /** Index of NBYTES to shift the actual number generated on the fly */
  inline std::uint32_t NBYTES_INDEX = 16;

  /**
   * @brief I2C Own Address Register 1 (I2C_OAR1) bits.
   *
   * Use these values to manipulate the I2C_OAR1 register.
   */
  enum class OAR1 : std::uint32_t
  {
    OA1_0     = 1u << 0,   // Own address 1 bit 0 (10-bit mode)
    OA1_1     = 1u << 1,   // Own address 1 bit 1
    OA1_2     = 1u << 2,   // Own address 1 bit 2
    OA1_3     = 1u << 3,   // Own address 1 bit 3
    OA1_4     = 1u << 4,   // Own address 1 bit 4
    OA1_5     = 1u << 5,   // Own address 1 bit 5
    OA1_6     = 1u << 6,   // Own address 1 bit 6
    OA1_7     = 1u << 7,   // Own address 1 bit 7
    OA1_8     = 1u << 8,   // Own address 1 bit 8
    OA1_9     = 1u << 9,   // Own address 1 bit 9
    OA1MODE   = 1u << 10,  // Own address 1 10-bit mode enable
    OA1EN     = 1u << 15,  // Own address 1 enable
  };

  /**
   * @brief I2C Own Address Register 2 (I2C_OAR2) bits.
   *
   * Use these values to manipulate the I2C_OAR2 register.
   */
  enum class OAR2 : std::uint32_t
  {
    OA2_1     = 1u << 1,   // Own address 2 bit 1
    OA2_2     = 1u << 2,   // Own address 2 bit 2
    OA2_3     = 1u << 3,   // Own address 2 bit 3
    OA2_4     = 1u << 4,   // Own address 2 bit 4
    OA2_5     = 1u << 5,   // Own address 2 bit 5
    OA2_6     = 1u << 6,   // Own address 2 bit 6
    OA2_7     = 1u << 7,   // Own address 2 bit 7
    OA2MSK0   = 1u << 8,   // Own address 2 masks bit 0
    OA2MSK1   = 1u << 9,   // Own address 2 masks bit 1
    OA2MSK2   = 1u << 10,  // Own address 2 masks bit 2
    OA2EN     = 1u << 15,  // Own address 2 enable
  };

  /**
   * @brief I2C Timing Register (I2C_TIMINGR) bits.
   *
   * Use these values to manipulate the I2C_TIMINGR register.
   */
  enum class TIMINGR : std::uint32_t
  {
    SCLL0     = 1u << 0,   // SCL low period bit 0
    SCLL1     = 1u << 1,   // SCL low period bit 1
    SCLL2     = 1u << 2,   // SCL low period bit 2
    SCLL3     = 1u << 3,   // SCL low period bit 3
    SCLL4     = 1u << 4,   // SCL low period bit 4
    SCLL5     = 1u << 5,   // SCL low period bit 5
    SCLL6     = 1u << 6,   // SCL low period bit 6
    SCLL7     = 1u << 7,   // SCL low period bit 7
    SCLH0     = 1u << 8,   // SCL high period bit 0
    SCLH1     = 1u << 9,   // SCL high period bit 1
    SCLH2     = 1u << 10,  // SCL high period bit 2
    SCLH3     = 1u << 11,  // SCL high period bit 3
    SCLH4     = 1u << 12,  // SCL high period bit 4
    SCLH5     = 1u << 13,  // SCL high period bit 5
    SCLH6     = 1u << 14,  // SCL high period bit 6
    SCLH7     = 1u << 15,  // SCL high period bit 7
    SDADEL0   = 1u << 16,  // Data hold time bit 0
    SDADEL1   = 1u << 17,  // Data hold time bit 1
    SDADEL2   = 1u << 18,  // Data hold time bit 2
    SDADEL3   = 1u << 19,  // Data hold time bit 3
    SCLDEL0   = 1u << 20,  // Data setup time bit 0
    SCLDEL1   = 1u << 21,  // Data setup time bit 1
    SCLDEL2   = 1u << 22,  // Data setup time bit 2
    SCLDEL3   = 1u << 23,  // Data setup time bit 3
    PRESC0    = 1u << 28,  // Timing prescaler bit 0
    PRESC1    = 1u << 29,  // Timing prescaler bit 1
    PRESC2    = 1u << 30,  // Timing prescaler bit 2
    PRESC3    = 1u << 31,  // Timing prescaler bit 3
  };

  /**
   * @brief I2C Timeout Register (I2C_TIMEOUTR) bits.
   *
   * Use these values to manipulate the I2C_TIMEOUTR register.
   */
  enum class TIMEOUTR : std::uint32_t
  {
    TIMEOUTA0  = 1u << 0,   // Bus timeout A bit 0
    TIMEOUTA1  = 1u << 1,   // Bus timeout A bit 1
    TIMEOUTA2  = 1u << 2,   // Bus timeout A bit 2
    TIMEOUTA3  = 1u << 3,   // Bus timeout A bit 3
    TIMEOUTA4  = 1u << 4,   // Bus timeout A bit 4
    TIMEOUTA5  = 1u << 5,   // Bus timeout A bit 5
    TIMEOUTA6  = 1u << 6,   // Bus timeout A bit 6
    TIMEOUTA7  = 1u << 7,   // Bus timeout A bit 7
    TIMEOUTA8  = 1u << 8,   // Bus timeout A bit 8
    TIMEOUTA9  = 1u << 9,   // Bus timeout A bit 9
    TIMEOUTA10 = 1u << 10,  // Bus timeout A bit 10
    TIDLE      = 1u << 12,  // Idle clock timeout detection
    TIMOUTEN   = 1u << 15,  // Clock timeout enable
    TIMEOUTB0  = 1u << 16,  // Bus timeout B bit 0
    TIMEOUTB1  = 1u << 17,  // Bus timeout B bit 1
    TIMEOUTB2  = 1u << 18,  // Bus timeout B bit 2
    TIMEOUTB3  = 1u << 19,  // Bus timeout B bit 3
    TIMEOUTB4  = 1u << 20,  // Bus timeout B bit 4
    TIMEOUTB5  = 1u << 21,  // Bus timeout B bit 5
    TIMEOUTB6  = 1u << 22,  // Bus timeout B bit 6
    TIMEOUTB7  = 1u << 23,  // Bus timeout B bit 7
    TIMEOUTB8  = 1u << 24,  // Bus timeout B bit 8
    TIMEOUTB9  = 1u << 25,  // Bus timeout B bit 9
    TIMEOUTB10 = 1u << 26,  // Bus timeout B bit 10
    TEXTEN     = 1u << 31,  // Extended clock timeout enable
  };

  /**
   * @brief I2C Interrupt and Status Register (I2C_ISR) bits.
   *
   * Use these values to manipulate the I2C_ISR register.
   */
  enum class ISR : std::uint32_t
  {
    TXE       = 1u << 0,   // Transmit data register empty
    TXIS      = 1u << 1,   // Transmit interrupt status
    RXNE      = 1u << 2,   // Receive data register not empty
    ADDR      = 1u << 3,   // Address matched (slave mode)
    NACKF     = 1u << 4,   // NACK received flag
    STOPF     = 1u << 5,   // STOP detection flag
    TC        = 1u << 6,   // Transfer complete
    TCR       = 1u << 7,   // Transfer complete reload
    BERR      = 1u << 8,   // Bus error
    ARLO      = 1u << 9,   // Arbitration lost
    OVR       = 1u << 10,  // Overrun / underrun
    PECERR    = 1u << 11,  // PEC error in reception
    TIMEOUT   = 1u << 12,  // Timeout or Tlow detection flag
    ALERT     = 1u << 13,  // SMBus alert
    BUSY      = 1u << 15,  // Bus busy
    DIR       = 1u << 16,  // Transfer direction (slave mode; 0=write, 1=read)
    ADDCODE0  = 1u << 17,  // Address match code bit 0
    ADDCODE1  = 1u << 18,  // Address match code bit 1
    ADDCODE2  = 1u << 19,  // Address match code bit 2
    ADDCODE3  = 1u << 20,  // Address match code bit 3
    ADDCODE4  = 1u << 21,  // Address match code bit 4
    ADDCODE5  = 1u << 22,  // Address match code bit 5
    ADDCODE6  = 1u << 23,  // Address match code bit 6
  };

  /**
   * @brief I2C Interrupt Clear Register (I2C_ICR) bits.
   *
   * Use these values to manipulate the I2C_ICR register.
   */
  enum class ICR : std::uint32_t
  {
    ADDRCF    = 1u << 3,   // Address matched clear flag
    NACKCF    = 1u << 4,   // NACK clear flag
    STOPCF    = 1u << 5,   // STOP detection clear flag
    BERRCF    = 1u << 8,   // Bus error clear flag
    ARLOCF    = 1u << 9,   // Arbitration lost clear flag
    OVRCF     = 1u << 10,  // Overrun / underrun clear flag
    PECCF     = 1u << 11,  // PEC error clear flag
    TIMOUTCF  = 1u << 12,  // Timeout clear flag
    ALERTCF   = 1u << 13,  // SMBus alert clear flag
  };

  /**
   * @brief I2C PEC Register (I2C_PECR) bits.
   *
   * Use these values to manipulate the I2C_PECR register.
   */
  enum class PECR : std::uint32_t
  {
    PEC0      = 1u << 0,   // Packet error checking register bit 0
    PEC1      = 1u << 1,   // Packet error checking register bit 1
    PEC2      = 1u << 2,   // Packet error checking register bit 2
    PEC3      = 1u << 3,   // Packet error checking register bit 3
    PEC4      = 1u << 4,   // Packet error checking register bit 4
    PEC5      = 1u << 5,   // Packet error checking register bit 5
    PEC6      = 1u << 6,   // Packet error checking register bit 6
    PEC7      = 1u << 7,   // Packet error checking register bit 7
  };
  
}