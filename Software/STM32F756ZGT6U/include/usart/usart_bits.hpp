#pragma once

#include <cstdint>

namespace usart
{
  /*
   * USART Control Register 1 (USART_CR1)
   */
  namespace USART_CR1
  {
    constexpr uint32_t UE       = 1u << 0;   // USART Enable
    constexpr uint32_t UESM     = 1u << 1;   // USART Enable in Stop Mode
    constexpr uint32_t RE       = 1u << 2;   // Receiver Enable
    constexpr uint32_t TE       = 1u << 3;   // Transmitter Enable
    constexpr uint32_t IDLEIE   = 1u << 4;   // IDLE Interrupt Enable
    constexpr uint32_t RXNEIE   = 1u << 5;   // RXNE Interrupt Enable
    constexpr uint32_t TCIE     = 1u << 6;   // Transmission Complete Interrupt Enable
    constexpr uint32_t TXEIE    = 1u << 7;   // TXE Interrupt Enable
    constexpr uint32_t PEIE     = 1u << 8;   // PE Interrupt Enable
    constexpr uint32_t PS       = 1u << 9;   // Parity Selection
    constexpr uint32_t PCE      = 1u << 10;  // Parity Control Enable
    constexpr uint32_t WAKE     = 1u << 11;  // Receiver Wakeup Method
    constexpr uint32_t M0       = 1u << 12;  // Word Length bit 0
    constexpr uint32_t MME      = 1u << 13;  // Mute Mode Enable
    constexpr uint32_t CMIE     = 1u << 14;  // Character Match Interrupt Enable
    constexpr uint32_t OVER8    = 1u << 15;  // Oversampling mode
    constexpr uint32_t DEDT0    = 1u << 16;
    constexpr uint32_t DEDT1    = 1u << 17;
    constexpr uint32_t DEDT2    = 1u << 18;
    constexpr uint32_t DEDT3    = 1u << 19;
    constexpr uint32_t DEDT4    = 1u << 20;
    constexpr uint32_t RTOIE    = 1u << 26;  // Receiver Timeout Interrupt Enable
    constexpr uint32_t EOBIE    = 1u << 27;  // End Of Block Interrupt Enable
    constexpr uint32_t M1       = 1u << 28;  // Word Length bit 1
  }
  
  
  /*
   * USART Control Register 2 (USART_CR2)
   */
  namespace USART_CR2
  {
    constexpr uint32_t ADD0     = 1u << 0;
    constexpr uint32_t ADD1     = 1u << 1;
    constexpr uint32_t ADD2     = 1u << 2;
    constexpr uint32_t ADD3     = 1u << 3;
    constexpr uint32_t LBDL     = 1u << 5;
    constexpr uint32_t LBDIE    = 1u << 6;
    constexpr uint32_t LBCL     = 1u << 8;
    constexpr uint32_t CPHA     = 1u << 9;
    constexpr uint32_t CPOL     = 1u << 10;
    constexpr uint32_t CLKEN    = 1u << 11;
    constexpr uint32_t STOP0    = 1u << 12;
    constexpr uint32_t STOP1    = 1u << 13;
    constexpr uint32_t LINEN    = 1u << 14;
    constexpr uint32_t SWAP     = 1u << 15;
    constexpr uint32_t RXINV    = 1u << 16;
    constexpr uint32_t TXINV    = 1u << 17;
    constexpr uint32_t DATAINV  = 1u << 18;
    constexpr uint32_t MSBFIRST = 1u << 19;
    constexpr uint32_t ABREN    = 1u << 20;
    constexpr uint32_t ABRMOD0  = 1u << 21;
    constexpr uint32_t ABRMOD1  = 1u << 22;
    constexpr uint32_t RTOEN    = 1u << 23;
    constexpr uint32_t ADDM7    = 1u << 31;
  }
  
  
  /*
   * USART Control Register 3 (USART_CR3)
   */
  namespace USART_CR3
  {
    constexpr uint32_t EIE      = 1u << 0;
    constexpr uint32_t IREN     = 1u << 1;
    constexpr uint32_t IRLP     = 1u << 2;
    constexpr uint32_t HDSEL    = 1u << 3;
    constexpr uint32_t NACK     = 1u << 4;
    constexpr uint32_t SCEN     = 1u << 5;
    constexpr uint32_t DMAR     = 1u << 6;
    constexpr uint32_t DMAT     = 1u << 7;
    constexpr uint32_t RTSE     = 1u << 8;
    constexpr uint32_t CTSE     = 1u << 9;
    constexpr uint32_t CTSIE    = 1u << 10;
    constexpr uint32_t ONEBIT   = 1u << 11;
    constexpr uint32_t OVRDIS   = 1u << 12;
    constexpr uint32_t DDRE     = 1u << 13;
    constexpr uint32_t DEM      = 1u << 14;
    constexpr uint32_t DEP      = 1u << 15;
    constexpr uint32_t SCARCNT0 = 1u << 17;
    constexpr uint32_t SCARCNT1 = 1u << 18;
    constexpr uint32_t WUS0     = 1u << 20;
    constexpr uint32_t WUS1     = 1u << 21;
    constexpr uint32_t WUFIE    = 1u << 22;
    constexpr uint32_t UCESM    = 1u << 23;
  }
}
