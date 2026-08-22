/**
 * @file rcc_regs.hpp
 * @brief RCC register bits to access rcc functionality such as GPIO, UART, I2C, etc. activation.
 */
#pragma once

#include <array>
#include <cstdint>

namespace rcc
{
  /**
   * @brief // RCC registers
   * 
   * To activate and access the peripherals their clocks need to be enabled, 
   * the RCC registers do provide an access for bit manipulation. 
   */
  struct RCC_REGS
  {
    volatile std::uint32_t                  RCC_CR;           // Clock control register
    volatile std::uint32_t                  RCC_PLLCFGR;      // PLL configuration register
    volatile std::uint32_t                  RCC_CFGR;         // Clock configuration register
    volatile std::uint32_t                  RCC_CIR;          // Clock interrupt register
    volatile std::uint32_t                  RCC_AHB1RSTR;     // AHB1 peripheral reset register
    volatile std::uint32_t                  RCC_AHB2RSTR;     // AHB2 peripheral reset register
    volatile std::uint32_t                  RCC_AHB3RSTR;     // AHB3 peripheral reset register
    volatile std::array<std::uint32_t, 1>   UNUSED_MEM_0;     // Reserved
    volatile std::uint32_t                  RCC_APB1RSTR;     // APB1 peripheral reset register
    volatile std::uint32_t                  RCC_APB2RSTR;     // APB2 peripheral reset register
    volatile std::array<std::uint32_t, 2>   UNUSED_MEM_1;     // Reserved
    volatile std::uint32_t                  RCC_AHB1ENR;      // AHB1 peripheral clock enable register
    volatile std::uint32_t                  RCC_AHB2ENR;      // AHB2 peripheral clock enable register
    volatile std::uint32_t                  RCC_AHB3ENR;      // AHB3 peripheral clock enable register
    volatile std::array<std::uint32_t, 1>   UNUSED_MEM_2;     // Reserved
    volatile std::uint32_t                  RCC_APB1ENR;      // APB1 peripheral clock enable register
    volatile std::uint32_t                  RCC_APB2ENR;      // APB2 peripheral clock enable register
    volatile std::array<std::uint32_t, 2>   UNUSED_MEM_3;     // Reserved
    volatile std::uint32_t                  RCC_AHB1LPENR;    // AHB1 peripheral clock enable in Sleep/Stop modes
    volatile std::uint32_t                  RCC_AHB2LPENR;    // AHB2 peripheral clock enable in Sleep/Stop modes
    volatile std::uint32_t                  RCC_AHB3LPENR;    // AHB3 peripheral clock enable in Sleep/Stop modes
    volatile std::array<std::uint32_t, 1>   UNUSED_MEM_4;     // Reserved
    volatile std::uint32_t                  RCC_APB1LPENR;    // APB1 peripheral clock enable in Sleep/Stop modes
    volatile std::uint32_t                  RCC_APB2LPENR;    // APB2 peripheral clock enable in Sleep/Stop modes
    volatile std::array<std::uint32_t, 2>   UNUSED_MEM_5;     // Reserved
    volatile std::uint32_t                  RCC_BDCR;         // Backup domain control register
    volatile std::uint32_t                  RCC_CSR;          // Control/status register
    volatile std::array<std::uint32_t, 2>   UNUSED_MEM_6;     // Reserved
    volatile std::uint32_t                  RCC_SSCGR;        // Spread spectrum clock generation register
    volatile std::uint32_t                  RCC_PLLI2SCFGR;   // PLLI2S configuration register
    volatile std::uint32_t                  RCC_PLLSAICFGR;   // PLLSAI configuration register
    volatile std::uint32_t                  RCC_DCKCFGR1;     // Dedicated clocks configuration register 1
    volatile std::uint32_t                  RCC_DCKCFGR2;     // Dedicated clocks configuration register 2
  };
}