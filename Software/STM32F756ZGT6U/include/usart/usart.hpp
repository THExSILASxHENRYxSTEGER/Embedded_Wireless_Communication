#pragma once

#include "usart/usart_regs.hpp"
#include "global/addresses.hpp"
#include "global/global_vars.hpp"
#include "input_buffer/input_buffer.hpp"

#include <cstdint>

namespace usart {

  class USART
  {
    public:

      /**
       * @brief Construct a new USART/UART object which controls (enable, disable, etc.) 
       * the USART/UART capabilities of one of the available 8 usarts/uarts on the stm32f756.
       * 
       * @param usart_address 
       */
      USART(const std::uint32_t usart_address);
      
      /**
       * @brief Initialize the USART/UART to be able to transmit and receive bytes.
       * 
       * @param f_ck The actual system clock frequency.
       * @param baud_rate The actual baud rate to be set.
       */
      void init(std::uint32_t f_ck, std::uint32_t baud_rate);
      
      /**
       * @brief Push one byte into the USART/UART transmit FIFO buffer.
       * 
       * @param c The byte to be transmitted.
       */
      void send(char c);

      /**
       * @brief Send an entire string to the USART/UART transmit FIFO buffer one byte at a time.
       * 
       * @param str The string to be send to the USART/UART transmit FIFO buffer.
       */
      void send_string(const char* str);

      /**
       * @brief Read a byte from the receive FIFO buffer into @ib which is an internal buffer for storage and access.
       * 
       * @param ib The internal buffer to save read characters into.
       */
      void read(input_buffer::INPUT_BUFFER<global_vars::MAX_INPUT_LEN>& ib);

      ~USART() = default;
    
    private:

      /** Registers to manipulate the USART */
      volatile USART_REGS* usart_regs_;
  };
    
  /** USART 1 peripheral instance. */
  inline USART usart_1(addresses::USART1);
  /** USART 2 peripheral instance. */
  inline USART usart_2(addresses::USART2);
  /** USART 3 peripheral instance. */
  inline USART usart_3(addresses::USART3);
  /** UART 4 peripheral instance. */
  inline USART uart_4(addresses::UART4);
  /** UART 5 peripheral instance. */
  inline USART uart_5(addresses::UART5);
  /** USART 6 peripheral instance. */
  inline USART usart_6(addresses::USART6);
  /** UART 7 peripheral instance. */
  inline USART uart_7(addresses::UART7);
  /** UART 8 peripheral instance. */
  inline USART uart_8(addresses::UART8);
}
