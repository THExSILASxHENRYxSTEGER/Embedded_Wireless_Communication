#pragma once

#include <array>

namespace basic_timer
{
  struct BASIC_TIMER_REGS {
    volatile std::uint32_t CR1;
    volatile std::uint32_t CR2;
    volatile std::array<std::uint32_t, 1> UNUSED_MEM_0;
    volatile std::uint32_t DIER;
    volatile std::uint32_t SR;
    volatile std::uint32_t EGR;
    volatile std::array<std::uint32_t, 3> UNUSED_MEM_1;
    volatile std::uint32_t CNT;
    volatile std::uint32_t PSC;
    volatile std::uint32_t ARR;
  };
}