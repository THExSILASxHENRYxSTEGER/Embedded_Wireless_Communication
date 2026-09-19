#include "global/global_vars.hpp"
#include "i2c/i2c.hpp"
#include "utils/enum_utils.hpp"
#include "utils/bit_manipultion.hpp"

namespace i2c
{
  I2C::I2C(const std::uint32_t i2c_address)
  :
    i2c_regs_(reinterpret_cast<volatile I2C_REGS*>(i2c_address))
  {}
  
  bool I2C::init( 
    std::uint32_t SCLL, 
    std::uint32_t SCLH, 
    std::uint32_t SDADEL, 
    std::uint32_t SCLDEL,
    std::uint32_t PRESC
  )
  {
    // Disable the i2c peripheral to make initializations
    clear_bits(i2c_regs_->CR1, CR1::PE);

    // Set analog noise filter
    clear_bits(
      i2c_regs_->CR1, 
      CR1::ANFOFF | CR1::DNF0 | CR1::DNF1 | CR1::DNF2 | CR1::DNF3
    );

    // Configure value to be written to timing register
    std::uint32_t timing = SCLL;
    timing |= SCLH << global_vars::QUART_REG_SZ;
    timing |= SDADEL << global_vars::HALF_REG_SZ;
    timing |= SCLDEL << (global_vars::HALF_REG_SZ + global_vars::EIGTH_REG_SZ);
    timing |= PRESC << (global_vars::REG_SZ - global_vars::EIGTH_REG_SZ);

    // adjust timing register
    i2c_regs_->TIMINGR = timing;

    // Enable the i2c peripheral
    set_bits(i2c_regs_->CR1, CR1::PE);

    // Set 7 bit address mode and write direction
    clear_bits(i2c_regs_->CR2, CR2::ADD10 | CR2::RD_WRN);

    // Send one confirmation byte
    set_bits(
      i2c_regs_->CR2, 
      CR2::NBYTES0
    );

    // Set Autoend to stop after one byte transfer automatically
    set_bits(i2c_regs_->CR2, CR2::AUTOEND);
    
    // Iterate over all possible i2c slave addresses and check for ACK
    for(std::uint32_t addr = 0; addr <= I2C_Address::MAX_ADDRESS_7_BIT; addr++)
    {
      // Clean current address
      clear_bits(i2c_regs_->CR2, I2C_Address::MAX_ADDRESS_7_BIT << CR2::SADD0);
      // Set i as current i2c slave address
      set_bits(i2c_regs_->CR2, addr << CR2::SADD0);
      // set start bit to 1
      set_bits(i2c_regs_->CR2, CR2::START);
      // check for NACKF and ADDR bit set at the same time and check shich one was actuvated
      while(!test_bits(i2c_regs_->ISR, ISR::TXIS) && !test_bits(i2c_regs_->ISR, ISR::NACKF));
      // address was confirmed hence keep it
      if (test_bits(i2c_regs_->ISR, ISR::TXIS))
      {
        // Save the found slave address
        slave_addr_ = addr;
        // Terminate the probe transaction cleanly: a data byte is expected
        push('\0');
      
        // Fully clear NBYTES 
        clear_bits(
          i2c_regs_->CR2,
          CR2::NBYTES0 | CR2::NBYTES1 | CR2::NBYTES2 | CR2::NBYTES3 |
          CR2::NBYTES4 | CR2::NBYTES5 | CR2::NBYTES6 | CR2::NBYTES7
        );
        return true;
      }
      set_bits(i2c_regs_->ICR, ICR::NACKCF);
    }
    return false;
  }
  
  void I2C::push(char c)
  {
    // Wait for TXI bit to be cleared
    while (!test_bits(i2c_regs_->ISR, ISR::TXIS));
    // Push byte to the I2C transmit fifo
    i2c_regs_->TXDR = static_cast<std::uint32_t>(c) + (i2c_regs_->TXDR & static_cast<char>(0));
  }
  
  void I2C::send_string(const char* str)
  {
    // Retreive the length of the string
    std::uint32_t len = -1;
    while (str[++len] != '\0');
    // Initiate a write I2C transcation
    set_write(len);
    // Iterate over the buffer and push chars
    for(std::uint32_t i = 0; i < len; i++)
    {
      push(str[i]);
      // Reinitiate I2C transaction
      if (i > 0 && i % 255 == 0)
        set_write(len-i);
    }
  }

  void I2C::send_string(input_buffer::INPUT_BUFFER<global_vars::MAX_INPUT_LEN>& ib)
  {
    // Retreive the length of the buffer
    std::uint32_t len = ib.size();
    set_write(len);
    // Iterate over the buffer and push chars
    for(std::uint32_t i = 0; i < ib.size(); i++)
    {
      // Reinitiate I2C transaction
      if (i > 0 && i % 255 == 0)
      {
        if (test_bits(i2c_regs_->ISR, ISR::TCR)) 
        {
          set_write(len-255);
        } else {
          return;
        } 
      }
      // Push a byte to the I2C buffer
      push(ib[i]);
    }
    // Empty the buffer
    //ib.clear();
  }

  void I2C::set_write(std::uint32_t len)
  {
    // Clear the number of bits specified for the previous write
    clear_bits(
      i2c_regs_->CR2,
      CR2::NBYTES0 | CR2::NBYTES1 | CR2::NBYTES2 | CR2::NBYTES3 |
      CR2::NBYTES4 | CR2::NBYTES5 | CR2::NBYTES6 | CR2::NBYTES7
    );
    if (len <= 255)
    {
      // Set the number of bytes to be sent in the next I2C transaction
      set_bits(i2c_regs_->CR2, len << NBYTES_INDEX);
      // Clear RELOAD bit for last byte transfer
      clear_bits(
        i2c_regs_->CR2, 
        CR2::RELOAD
      );
      // Declare AUTOEND once the last byte is written
      set_bits(i2c_regs_->CR2, CR2::AUTOEND);
    } else {
      clear_bits(i2c_regs_->CR2, CR2::AUTOEND);
      // Set the number of bytes to be sent to the maximum of 255
      set_bits(
        i2c_regs_->CR2, 
        CR2::NBYTES0 | CR2::NBYTES1 | CR2::NBYTES2 | CR2::NBYTES3 | 
        CR2::NBYTES4 | CR2::NBYTES5 | CR2::NBYTES6 | CR2::NBYTES7
      );
      set_bits(
        i2c_regs_->CR2,
        CR2::RELOAD
      );
    }
      // Clean current address
      clear_bits(i2c_regs_->CR2, I2C_Address::MAX_ADDRESS_7_BIT << CR2::SADD0);
      // Set i as current i2c slave address
      set_bits(i2c_regs_->CR2, slave_addr_ << CR2::SADD0);
      set_bits(i2c_regs_->CR2, CR2::START);
  }

}
