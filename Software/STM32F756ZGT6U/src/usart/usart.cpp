#include "usart/usart.hpp"
#include "usart/usart_bits.hpp"
#include "utils/bit_manipultion.hpp"
#include "utils/enum_utils.hpp"

namespace usart
{
    USART::USART(const std::uint32_t usart_address)
    : 
      usart_regs_(reinterpret_cast<volatile USART_REGS*>(usart_address))
    {}

    void USART::init(std::uint32_t f_ck, std::uint32_t baud_rate)
    {
      // Set UE to zero for manipulation
      clear_bits(usart_regs_->CR1, USART_CR1::UE);
      // Set 8 data bits, 1 start bit and oversampling by 16
      std::uint32_t CR1_mask = USART_CR1::M0 | USART_CR1::M1 | USART_CR1::OVER8;
      clear_bits(usart_regs_->CR1, CR1_mask);
      // Set 1 start bit
      clear_bits(usart_regs_->CR2, USART_CR2::STOP0 | USART_CR2::STOP1);
      // Configure the baud rate
      std::uint32_t usart_div = static_cast<std::uint32_t>(f_ck/baud_rate);
      set_bits(usart_regs_->BRR, usart_div);
      // Enable USART
      set_bits(usart_regs_->CR1, USART_CR1::UE);
      // Enable Rx, Tx, and interrupt upon receive
      CR1_mask = USART_CR1::RE | USART_CR1::TE | USART_CR1::RXNEIE;
      set_bits(usart_regs_->CR1, CR1_mask);
    }

    void USART::send(char c)
    {
      // Wait for shift register to be empty
      while(!test_bits(usart_regs_->ISR, USART_ISR::TXE));
      // Write the char to the transmit data register
      usart_regs_->TDR = static_cast<std::uint32_t>(c) + (usart_regs_->TDR & static_cast<char>(0));
    }

    void USART::send_string(const char* str)
    {
      // Iterate over the string
      for (std::uint32_t i = 0; str[i]!='\0' ; i++)
      {
        // Push string index element into USART/UART transmit FIFO buffer.
        send(str[i]);
      }
      // Wait till transmission is complete
      while(!test_bits(usart_regs_->ISR, USART_ISR::TC));
    }

    void USART::read(input_buffer::INPUT_BUFFER<global_vars::MAX_INPUT_LEN>& ib)
    {
      // Read only if the receive FIFO actually has a new element available
      if (test_bits(usart_regs_->ISR, USART_ISR::RXNE))
      {
        // Read and save contents of the RDR register
        char c = static_cast<char>(usart_regs_->RDR);
        ib.push_back(c);
      }
      // Check for an overrun error and clear if it happened
      if (test_bits(usart_regs_->ISR, USART_ISR::ORE))
      {
        set_bits(usart_regs_->ICR, USART_ICR::ORECF);
        
      }
    }

} 
