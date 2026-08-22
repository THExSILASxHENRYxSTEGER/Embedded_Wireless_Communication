#pragma once

#include <cstdint>

namespace global_vars
{
  /** Eigth Size of a register */
  constexpr std::uint32_t EIGTH_REG_SZ = 4;
  /** Quarter Size of a register */
  constexpr std::uint32_t QUART_REG_SZ = 8;
  /** Half size of a register */
  constexpr std::uint32_t HALF_REG_SZ = 16;
  /** Size of a register */
  constexpr std::uint32_t REG_SZ = 32;
  
  /** Bit zero to be shifted */
  constexpr std::uint32_t BIT_0 = 0x1;
  
  /** Maximum length of a video and name title */
  constexpr std::uint32_t MAX_INPUT_LEN = 50;
}