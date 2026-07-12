#pragma once

#include <cstdint>

namespace usart
{

  /**
   * @brief USART registers 
   * 
   * To access, activate, and control the usart peripheral 
   * bit manipulation of these registers is necessary.
   */
  struct USART_REGS
  {
    volatile uint32_t CR1;    // 0x00 Control register 1
    volatile uint32_t CR2;    // 0x04 Control register 2
    volatile uint32_t CR3;    // 0x08 Control register 3
    volatile uint32_t BRR;    // 0x0C Baud rate register
    volatile uint32_t GTPR;   // 0x10 Guard time and prescaler register
    volatile uint32_t RTOR;   // 0x14 Receiver timeout register
    volatile uint32_t RQR;    // 0x18 Request register
    volatile uint32_t ISR;    // 0x1C Interrupt and status register
    volatile uint32_t ICR;    // 0x20 Interrupt flag clear register
    volatile uint32_t RDR;    // 0x24 Receive data register
    volatile uint32_t TDR;    // 0x28 Transmit data register
  };

}