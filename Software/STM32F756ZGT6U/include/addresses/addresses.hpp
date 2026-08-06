/**
 * @file addresses.hpp
 * @brief File that saves all the physical memory addresses to instantiate preripheral registers.
 */
#pragma once

#include <cstdint>

/**
 * 
 * @namespace addresses
 * @brief All physical peripheral memory addresses of the STM32F756ZGT6U.
 * 
 */
namespace addresses
{

  /**
   * @brief RCC hardware regsiter Address
   */
  constexpr std::uint32_t RCC = 0x40023800;
  
  /**
   * @brief GPIO ports hardware register addresses
   */
  constexpr std::uint32_t GPIO_PORT_A = 0x40020000;
  constexpr std::uint32_t GPIO_PORT_B = 0x40020400;
  constexpr std::uint32_t GPIO_PORT_C = 0x40020800;
  constexpr std::uint32_t GPIO_PORT_D = 0x40020C00;
  constexpr std::uint32_t GPIO_PORT_E = 0x40021000;
  constexpr std::uint32_t GPIO_PORT_F = 0x40021400;
  constexpr std::uint32_t GPIO_PORT_G = 0x40021800;
  constexpr std::uint32_t GPIO_PORT_H = 0x40021C00;
  constexpr std::uint32_t GPIO_PORT_I = 0x40022000;
  constexpr std::uint32_t GPIO_PORT_J = 0x40022400;
  constexpr std::uint32_t GPIO_PORT_K = 0x40022800;
  
}
