/**
 * @file gpio_regs.hpp
 * @brief GPIO registers to access GPIO functionality such as input, 
 * output, alternative function, etc.
 */
#pragma once

#include <array>
#include <cstdint>

namespace gpio {
  
  /**
   * @brief // GPIO port registers
   * 
   * There are 11 GPIO ports from letter A to K, which all have one such address space. 
   */
  struct GPIO_PORT_REGS {
    volatile std::uint32_t MODER;      // Pin mode selection
    volatile std::uint32_t OTYPER;     // Output type selection
    volatile std::uint32_t OSPEEDR;    // Output speed selection
    volatile std::uint32_t PUPDR;      // Pull-up/pull-down selection
    volatile std::uint32_t IDR;        // Input data register
    volatile std::uint32_t ODR;        // Output data register
    volatile std::uint32_t BSRR;       // Bit set/reset register
    volatile std::uint32_t LCKR;       // Configuration lock register
    volatile std::uint32_t AFRL;       // Alternate function low (pins 0-7)
    volatile std::uint32_t AFRH;       // Alternate function high (pins 8-15)
  };
  
}