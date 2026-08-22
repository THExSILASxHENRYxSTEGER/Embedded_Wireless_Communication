#pragma once

#include <cstdint>

namespace usart
{
  /**
   * @brief USART Control Register 1 (USART_CR1) bits.
   *
   * Use these values to manipulate the USART_CR1 register.
   */
  enum class USART_CR1 : std::uint32_t
  {
    UE       = 1u << 0,   // USART enable
    UESM     = 1u << 1,   // USART enable in Stop mode
    RE       = 1u << 2,   // Receiver enable
    TE       = 1u << 3,   // Transmitter enable
    IDLEIE   = 1u << 4,   // IDLE interrupt enable
    RXNEIE   = 1u << 5,   // RX not empty interrupt enable
    TCIE     = 1u << 6,   // Transmission complete interrupt enable
    TXEIE    = 1u << 7,   // TX register empty interrupt enable
    PEIE     = 1u << 8,   // Parity error interrupt enable
    PS       = 1u << 9,   // Parity selection
    PCE      = 1u << 10,  // Parity control enable
    WAKE     = 1u << 11,  // Receiver wakeup method
    M0       = 1u << 12,  // Word length bit 0
    MME      = 1u << 13,  // Mute mode enable
    CMIE     = 1u << 14,  // Character match interrupt enable
    OVER8    = 1u << 15,  // Oversampling mode
    DEDT0    = 1u << 16,  // Driver enable deassertion time bit 0
    DEDT1    = 1u << 17,  // Driver enable deassertion time bit 1
    DEDT2    = 1u << 18,  // Driver enable deassertion time bit 2
    DEDT3    = 1u << 19,  // Driver enable deassertion time bit 3
    DEDT4    = 1u << 20,  // Driver enable deassertion time bit 4
    RTOIE    = 1u << 26,  // Receiver timeout interrupt enable
    EOBIE    = 1u << 27,  // End of block interrupt enable
    M1       = 1u << 28,  // Word length bit 1
  };

  /**
   * @brief USART Control Register 2 (USART_CR2) bits.
   *
   * Use these values to manipulate the USART_CR2 register.
   */
  enum class USART_CR2 : std::uint32_t
  {
    ADD0     = 1u << 0,   // Address bit 0
    ADD1     = 1u << 1,   // Address bit 1
    ADD2     = 1u << 2,   // Address bit 2
    ADD3     = 1u << 3,   // Address bit 3
    LBDL     = 1u << 5,   // LIN break detection length
    LBDIE    = 1u << 6,   // LIN break detection interrupt enable
    LBCL     = 1u << 8,   // Last bit clock pulse
    CPHA     = 1u << 9,   // Clock phase
    CPOL     = 1u << 10,  // Clock polarity
    CLKEN    = 1u << 11,  // Clock enable
    STOP0    = 1u << 12,  // STOP bits bit 0
    STOP1    = 1u << 13,  // STOP bits bit 1
    LINEN    = 1u << 14,  // LIN mode enable
    SWAP     = 1u << 15,  // Swap TX/RX pins
    RXINV    = 1u << 16,  // RX pin active level inversion
    TXINV    = 1u << 17,  // TX pin active level inversion
    DATAINV  = 1u << 18,  // Binary data inversion
    MSBFIRST = 1u << 19,  // Most significant bit first
    ABREN    = 1u << 20,  // Auto baud rate enable
    ABRMOD0  = 1u << 21,  // Auto baud rate mode bit 0
    ABRMOD1  = 1u << 22,  // Auto baud rate mode bit 1
    RTOEN    = 1u << 23,  // Receiver timeout enable
    ADDM7    = 1u << 31,  // 7-bit address detection
  };

  /**
   * @brief USART Control Register 3 (USART_CR3) bits.
   *
   * Use these values to manipulate the USART_CR3 register.
   */
  enum class USART_CR3 : std::uint32_t
  {
    EIE      = 1u << 0,   // Error interrupt enable
    IREN     = 1u << 1,   // IrDA mode enable
    IRLP     = 1u << 2,   // IrDA low-power mode
    HDSEL    = 1u << 3,   // Half-duplex selection
    NACK     = 1u << 4,   // Smartcard NACK enable
    SCEN     = 1u << 5,   // Smartcard mode enable
    DMAR     = 1u << 6,   // DMA enable receiver
    DMAT     = 1u << 7,   // DMA enable transmitter
    RTSE     = 1u << 8,   // RTS enable
    CTSE     = 1u << 9,   // CTS enable
    CTSIE    = 1u << 10,  // CTS interrupt enable
    ONEBIT   = 1u << 11,  // One sample bit method enable
    OVRDIS   = 1u << 12,  // Overrun disable
    DDRE     = 1u << 13,  // DMA disable on reception error
    DEM      = 1u << 14,  // Driver enable mode
    DEP      = 1u << 15,  // Driver enable polarity
    SCARCNT0 = 1u << 17,  // Smartcard auto-retry count bit 0
    SCARCNT1 = 1u << 18,  // Smartcard auto-retry count bit 1
    WUS0     = 1u << 20,  // Wakeup from Stop mode interrupt bit 0
    WUS1     = 1u << 21,  // Wakeup from Stop mode interrupt bit 1
    WUFIE    = 1u << 22,  // Wakeup from Stop mode interrupt enable
    UCESM    = 1u << 23,  // USART clock enable in Stop mode
  };

  /**
   * @brief USART Baud Rate Register (USART_BRR) bits.
   *
   * Use these values to manipulate the USART_BRR register.
   */
  enum class USART_BRR : std::uint32_t
  {
    DIV_FRACTION0  = 1u << 0,   // USARTDIV fraction bit 0
    DIV_FRACTION1  = 1u << 1,   // USARTDIV fraction bit 1
    DIV_FRACTION2  = 1u << 2,   // USARTDIV fraction bit 2
    DIV_FRACTION3  = 1u << 3,   // USARTDIV fraction bit 3
    DIV_MANTISSA0  = 1u << 4,   // USARTDIV mantissa bit 0
    DIV_MANTISSA1  = 1u << 5,   // USARTDIV mantissa bit 1
    DIV_MANTISSA2  = 1u << 6,   // USARTDIV mantissa bit 2
    DIV_MANTISSA3  = 1u << 7,   // USARTDIV mantissa bit 3
    DIV_MANTISSA4  = 1u << 8,   // USARTDIV mantissa bit 4
    DIV_MANTISSA5  = 1u << 9,   // USARTDIV mantissa bit 5
    DIV_MANTISSA6  = 1u << 10,  // USARTDIV mantissa bit 6
    DIV_MANTISSA7  = 1u << 11,  // USARTDIV mantissa bit 7
    DIV_MANTISSA8  = 1u << 12,  // USARTDIV mantissa bit 8
    DIV_MANTISSA9  = 1u << 13,  // USARTDIV mantissa bit 9
    DIV_MANTISSA10 = 1u << 14,  // USARTDIV mantissa bit 10
    DIV_MANTISSA11 = 1u << 15,  // USARTDIV mantissa bit 11
  };

  /**
   * @brief USART Guard Time and Prescaler Register (USART_GTPR) bits.
   *
   * Use these values to manipulate the USART_GTPR register.
   */
  enum class USART_GTPR : std::uint32_t
  {
    PSC0 = 1u << 0,    // Prescaler value bit 0
    PSC1 = 1u << 1,    // Prescaler value bit 1
    PSC2 = 1u << 2,    // Prescaler value bit 2
    PSC3 = 1u << 3,    // Prescaler value bit 3
    PSC4 = 1u << 4,    // Prescaler value bit 4
    PSC5 = 1u << 5,    // Prescaler value bit 5
    PSC6 = 1u << 6,    // Prescaler value bit 6
    PSC7 = 1u << 7,    // Prescaler value bit 7
    GT0  = 1u << 8,    // Guard time value bit 0
    GT1  = 1u << 9,    // Guard time value bit 1
    GT2  = 1u << 10,   // Guard time value bit 2
    GT3  = 1u << 11,   // Guard time value bit 3
    GT4  = 1u << 12,   // Guard time value bit 4
    GT5  = 1u << 13,   // Guard time value bit 5
    GT6  = 1u << 14,   // Guard time value bit 6
    GT7  = 1u << 15,   // Guard time value bit 7
  };

  /**
   * @brief USART Receiver Timeout Register (USART_RTOR) bits.
   *
   * Use these values to manipulate the USART_RTOR register.
   */
  enum class USART_RTOR : std::uint32_t
  {
    RTO0  = 1u << 0,    // Receiver timeout value bit 0
    RTO1  = 1u << 1,    // Receiver timeout value bit 1
    RTO2  = 1u << 2,    // Receiver timeout value bit 2
    RTO3  = 1u << 3,    // Receiver timeout value bit 3
    RTO4  = 1u << 4,    // Receiver timeout value bit 4
    RTO5  = 1u << 5,    // Receiver timeout value bit 5
    RTO6  = 1u << 6,    // Receiver timeout value bit 6
    RTO7  = 1u << 7,    // Receiver timeout value bit 7
    RTO8  = 1u << 8,    // Receiver timeout value bit 8
    RTO9  = 1u << 9,    // Receiver timeout value bit 9
    RTO10 = 1u << 10,   // Receiver timeout value bit 10
    RTO11 = 1u << 11,   // Receiver timeout value bit 11
    RTO12 = 1u << 12,   // Receiver timeout value bit 12
    RTO13 = 1u << 13,   // Receiver timeout value bit 13
    RTO14 = 1u << 14,   // Receiver timeout value bit 14
    RTO15 = 1u << 15,   // Receiver timeout value bit 15
    RTO16 = 1u << 16,   // Receiver timeout value bit 16
    RTO17 = 1u << 17,   // Receiver timeout value bit 17
    RTO18 = 1u << 18,   // Receiver timeout value bit 18
    RTO19 = 1u << 19,   // Receiver timeout value bit 19
    RTO20 = 1u << 20,   // Receiver timeout value bit 20
    RTO21 = 1u << 21,   // Receiver timeout value bit 21
    RTO22 = 1u << 22,   // Receiver timeout value bit 22
    RTO23 = 1u << 23,   // Receiver timeout value bit 23
    BLEN0 = 1u << 24,   // Block length bit 0
    BLEN1 = 1u << 25,   // Block length bit 1
    BLEN2 = 1u << 26,   // Block length bit 2
    BLEN3 = 1u << 27,   // Block length bit 3
    BLEN4 = 1u << 28,   // Block length bit 4
    BLEN5 = 1u << 29,   // Block length bit 5
    BLEN6 = 1u << 30,   // Block length bit 6
    BLEN7 = 1u << 31,   // Block length bit 7
  };

  /**
   * @brief USART Request Register (USART_RQR) bits.
   *
   * Use these values to manipulate the USART_RQR register.
   */
  enum class USART_RQR : std::uint32_t
  {
    ABRRQ = 1u << 0,   // Auto baud rate request
    SBKRQ = 1u << 1,   // Send break request
    MMRQ  = 1u << 2,   // Mute mode request
    RXFRQ = 1u << 3,   // Receive data flush request
    TXFRQ = 1u << 4,   // Transmit data flush request
  };

  /**
   * @brief USART Interrupt and Status Register (USART_ISR) bits.
   *
   * Use these values to manipulate the USART_ISR register.
   */
  enum class USART_ISR : std::uint32_t
  {
    PE       = 1u << 0,   // Parity error
    FE       = 1u << 1,   // Framing error
    NF       = 1u << 2,   // Noise detected flag
    ORE      = 1u << 3,   // Overrun error
    IDLE     = 1u << 4,   // IDLE line detected
    RXNE     = 1u << 5,   // Receive data register not empty
    TC       = 1u << 6,   // Transmission complete
    TXE      = 1u << 7,   // Transmit data register empty
    LBDF     = 1u << 8,   // LIN break detection flag
    CTSIF    = 1u << 9,   // CTS interrupt flag
    CTS      = 1u << 10,  // CTS flag
    RTOF     = 1u << 11,  // Receiver timeout flag
    EOBF     = 1u << 12,  // End of block flag
    ABRE     = 1u << 14,  // Auto baud rate error
    ABRF     = 1u << 15,  // Auto baud rate flag
    BUSY     = 1u << 16,  // Busy flag
    CMF      = 1u << 17,  // Character match flag
    SBKF     = 1u << 18,  // Send break flag
    RWU      = 1u << 19,  // Receiver wakeup from mute mode
    WUF      = 1u << 20,  // Wakeup from Stop mode flag
    TEACK    = 1u << 21,  // Transmit enable acknowledge
    REACK    = 1u << 22,  // Receive enable acknowledge
  };

  /**
   * @brief USART Interrupt Flag Clear Register (USART_ICR) bits.
   *
   * Use these values to manipulate the USART_ICR register.
   */
  enum class USART_ICR : std::uint32_t
  {
    PECF     = 1u << 0,   // Parity error clear flag
    FECF     = 1u << 1,   // Framing error clear flag
    NCF      = 1u << 2,   // Noise detected clear flag
    ORECF    = 1u << 3,   // Overrun error clear flag
    IDLECF   = 1u << 4,   // IDLE line detected clear flag
    TCCF     = 1u << 6,   // Transmission complete clear flag
    LBDCF    = 1u << 8,   // LIN break detection clear flag
    CTSCF    = 1u << 9,   // CTS clear flag
    RTOCF    = 1u << 11,  // Receiver timeout clear flag
    EOBCF    = 1u << 12,  // End of block clear flag
    CMCF     = 1u << 17,  // Character match clear flag
    WUCF     = 1u << 20,  // Wakeup from Stop mode clear flag
  };

}