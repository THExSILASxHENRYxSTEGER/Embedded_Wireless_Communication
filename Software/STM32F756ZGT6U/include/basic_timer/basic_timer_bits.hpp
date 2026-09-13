#pragma once

#include <cstdint>

namespace basic_timer
{

  /**
   * @brief Time units.
   * 
   * Give this unit of time to say how low long to wait for.
   */
  enum class DURATION : std::uint32_t
  {
    MICRO_SECONDS = 1u << 0, 
    MILLI_SECONDS = 1u << 1, 
    SECONDS       = 1u << 2, 
    MINUTES       = 1u << 3, 
  };

  /**
   * @brief TIMx Control Register 1 (TIMx_CR1) bits.
   *
   * Use these values to manipulate the TIMx_CR1 register.
   */
  enum class CR1 : std::uint32_t
  {
    CEN      = 1u << 0,   // Counter enable
    UDIS     = 1u << 1,   // Update disable
    URS      = 1u << 2,   // Update request source
    OPM      = 1u << 3,   // One-pulse mode
    ARPE     = 1u << 7,   // Auto-reload preload enable
    UIFREMAP = 1u << 11, // UIF status bit remapping
  };
  
  /**
   * @brief TIMx Control Register 2 (TIMx_CR2) bits.
   *
   * Use these values to manipulate the TIMx_CR2 register.
   */
  enum class CR2 : std::uint32_t
  {
    MMS_RESET  = 1u << 4, // Reset the UG bit
    MMS_ENABLE = 1u << 5, // Counter enable signal
    MMS_UPDATE = 1u << 6, // Update event is selected as a trigger output
  };
  
  /**
   * @brief TIMx DMA/Interrupt Enable Register (TIMx_DIER) bits.
   *
   * Use these values to manipulate the TIMx_DIER register.
   */
  enum class DIER : std::uint32_t
  {
    UIE = 1u << 0, // Update interrupt enable
    UDE = 1u << 8, // Update DMA request enable
  };
  
  /**
   * @brief TIMx Status Register (TIMx_SR) bits.
   *
   * Use these values to manipulate the TIMx_SR register.
   */
  enum class SR : std::uint32_t
  {
    UIF = 1u << 0, // Update interrupt flag
  };
  
  /**
   * @brief TIMx Event Generation Register (TIMx_EGR) bits.
   *
   * Use these values to manipulate the TIMx_EGR register.
   */
  enum class EGR : std::uint32_t
  {
    UG        = 1u << 0,   // Update generation
  };
  
  /**
   * @brief TIMx Counter Register (TIMx_CNT) bits.
   *
   * Use these values to manipulate the TIMx_CNT register.
   */
  enum class CNT : std::uint32_t
  {
    CNT0  = 1u << 0,
    CNT1  = 1u << 1,
    CNT2  = 1u << 2,
    CNT3  = 1u << 3,
    CNT4  = 1u << 4,
    CNT5  = 1u << 5,
    CNT6  = 1u << 6,
    CNT7  = 1u << 7,
    CNT8  = 1u << 8,
    CNT9  = 1u << 9,
    CNT10 = 1u << 10,
    CNT11 = 1u << 11,
    CNT12 = 1u << 12,
    CNT13 = 1u << 13,
    CNT14 = 1u << 14,
    CNT15 = 1u << 15,
  };
  
  /**
   * @brief TIMx Prescaler Register (TIMx_PSC) common values.
   *
   * Use these values to manipulate the TIMx_PSC register.
   */
  enum class PSC : std::uint32_t
  {
    ONE_MICRO_SECOND_16MHz = 15,    // 16 minus 1 as 1 is added by PSC
    ONE_MILLI_SECOND_16MHz = 15999, // 16k minus 1 as 1 is added by PSC
    MAX_VAL                = 0xFF,
  };
  
  /**
   * @brief TIMx Auto-Reload Register (TIMx_ARR) common values.
   *
   * Use these values to manipulate the TIMx_ARR register.
   */
  enum class ARR : std::uint32_t
  {
    TICK_1     = 1,
    TICK_1000  = 1000, 
    TICK_60000 = 60000,
    MAX_VAL    = 0xFFFF,
  };

  /** How many seconds are in one minute */
  inline std::uint32_t SEC_PER_MIN = 60;
}