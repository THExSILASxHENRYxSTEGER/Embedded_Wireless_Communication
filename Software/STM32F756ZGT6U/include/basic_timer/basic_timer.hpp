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
      
      BasicTimer(const std::uint32_t basic_timer_address);
      
      void wait_for(std::uint32_t n, DURATION duration);
      
      ~BasicTimer() = default;
    
    private:
      
      volatile BASIC_TIMER_REGS * basic_timer_regs_;

      void activate_timer(PSC psc, std::uint32_t arr);

      bool update_event();
      
      void clear_update();

      void deactivate_timer();
  };  

  inline BasicTimer basic_timer_5(addresses::BASIC_TIMER_5);
  inline BasicTimer basic_timer_6(addresses::BASIC_TIMER_6);

}
