#pragma once

#include <cstdint>

/**
 * @brief Standardized baud rates
 * 
 */
namespace BAUD_RATE
{
  std::uint32_t _4_8_K   = 4800;   
  std::uint32_t _9_6_K   = 9600;
  std::uint32_t _115_2_K = 115200;
  std::uint32_t _128_K   = 128000;
  std::uint32_t _256_K   = 256000;
}


/**
 * @brief Physical Clock Frequencies
 * 
 */
namespace CLK_FREQ
{
  std::uint32_t _8_MHZ   = 8000000;
  std::uint32_t _16_MHZ  = 16000000;
  std::uint32_t _54_MHZ  = 54000000;
  std::uint32_t _108_MHZ = 108000000;
  std::uint32_t _256_MHZ = 256000000;
}

