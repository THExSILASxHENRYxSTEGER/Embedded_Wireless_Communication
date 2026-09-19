#pragma once

#include <array>

namespace basic_timer
{

  /**
   * @brief Basic timer peripheral registers.
   * 
   * To manipulate the register addresses of any basic timer use this struct.
   */
  struct BASIC_TIMER_REGS {
    volatile std::uint32_t CR1;                         // Control Register 1
    volatile std::uint32_t CR2;                         // Control Register 2
    volatile std::array<std::uint32_t, 1> UNUSED_MEM_0; // Unused memory
    volatile std::uint32_t DIER;                        // DMA/Interrupt enable register
    volatile std::uint32_t SR;                          // Status Register
    volatile std::uint32_t EGR;                         // Event generation register
    volatile std::array<std::uint32_t, 3> UNUSED_MEM_1; // Unused memory
    volatile std::uint32_t CNT;                         // Counter 
    volatile std::uint32_t PSC;                         // Prescaler 
    volatile std::uint32_t ARR;                         // Aut-reload register
  };
}