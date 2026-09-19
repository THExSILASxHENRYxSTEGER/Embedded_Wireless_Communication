#pragma once

#include "basic_timer/basic_timer_bits.hpp"
#include "basic_timer/basic_timer_regs.hpp"
#include "global/addresses.hpp"

#include <cstdint>

namespace basic_timer
{
  class BasicTimer
  {
    public:
      
      /**
       * @brief Construct a new Basic Timer object
       * 
       * @param basic_timer_address The physical memory address of the corresponding basic timer peripheral.
       */
      BasicTimer(const std::uint32_t basic_timer_address);
      
      /**
       * @brief Wait idle for the set amount of time
       * 
       * @param n How many time units should be waited.
       * @param duration The time unit to be waited i.e. microseconds, milliseconds, seconds, etc.
       */
      void wait_for(std::uint32_t n, DURATION duration);
      
      ~BasicTimer() = default;
    
    private:
      
      volatile BASIC_TIMER_REGS * basic_timer_regs_;

      /**
       * @brief Set the actual timer to run for the given time parameters. 
       * 
       * @param psc The timer prescaler.
       * @param arr The timer auto reload  register.
       */
      void activate_timer(PSC psc, std::uint32_t arr);

      /**
       * @brief Query if an update event occured.
       * 
       * If the counter hits the auto-reload registers' stored value an update event is caused.
       * This signals that the time period set out for has expired. 
       * 
       * @return true An update event occured.
       * @return false An update event has not occured.
       */
      bool update_event();
      
      /**
       * @brief Clear the fired update event flag.
       */
      void clear_update();

      /**
       * @brief Deactivate the timer for future reinitialization.
       */
      void deactivate_timer();
  };  

  inline BasicTimer basic_timer_5(addresses::BASIC_TIMER_5);
  inline BasicTimer basic_timer_6(addresses::BASIC_TIMER_6);

}
