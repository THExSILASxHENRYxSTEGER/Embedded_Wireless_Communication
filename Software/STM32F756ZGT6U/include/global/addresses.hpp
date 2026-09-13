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
   * @brief Basic timer physical hardware register addresses
   */
  constexpr std::uint32_t BASIC_TIMER_5 = 0x40000C00;
  constexpr std::uint32_t BASIC_TIMER_6 = 0x40001000;
  
  /**
   * @brief GPIO ports physical hardware register addresses
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

  /**
   * @brief I2C physical hardware register addresses
   * 
   */
  constexpr std::uint32_t I2C1 = 0x40005400;
  constexpr std::uint32_t I2C2 = 0x40005800;
  constexpr std::uint32_t I2C3 = 0x40005C00;
  constexpr std::uint32_t I2C4 = 0x40006000;

  /**
   * @brief NVIC cortex M7 physical hardware register addresses
   * 
   */
  constexpr std::uint32_t NVIC = 0xE000E100;

  /**
   * @brief RCC physical hardware regsiter Address
   */
  constexpr std::uint32_t RCC = 0x40023800;

  /**
   * @brief USART/UART physical hardware register addresses
   */
  constexpr std::uint32_t USART1 = 0x40011000;
  constexpr std::uint32_t USART2 = 0x40004400;
  constexpr std::uint32_t USART3 = 0x40004800;
  constexpr std::uint32_t UART4  = 0x40004C00;
  constexpr std::uint32_t UART5  = 0x40005000;
  constexpr std::uint32_t USART6 = 0x40011400;
  constexpr std::uint32_t UART7  = 0x40007800;
  constexpr std::uint32_t UART8  = 0x40007C00;

}
