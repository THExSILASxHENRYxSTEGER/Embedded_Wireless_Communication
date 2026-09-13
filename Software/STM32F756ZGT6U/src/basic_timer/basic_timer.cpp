#include "basic_timer/basic_timer.hpp"
#include "utils/enum_utils.hpp"
#include "utils/bit_manipultion.hpp"

namespace basic_timer
{
  BasicTimer::BasicTimer(const std::uint32_t basic_timer_address)
  :
    basic_timer_regs_(
      reinterpret_cast<volatile BASIC_TIMER_REGS*>(basic_timer_address)
    )
  {
    deactivate_timer();
  }

  void BasicTimer::wait_for(std::uint32_t n, DURATION duration)
  {
    switch (duration)
    {  
      case DURATION::MICRO_SECONDS:
        // Set update event every n micro seconds
        activate_timer(PSC::ONE_MICRO_SECOND_16MHz, n);
        break;
      case DURATION::MILLI_SECONDS:
        // Set update event every n milli seconds
        activate_timer(PSC::ONE_MILLI_SECOND_16MHz, n);
        break;
      case DURATION::SECONDS:
        // Set update event every n seconds
        activate_timer(
          PSC::ONE_MILLI_SECOND_16MHz,
          n * ARR::TICK_1000
        );
        break;
      case DURATION::MINUTES:
        // Set update event every n minutes
        activate_timer(
          PSC::ONE_MILLI_SECOND_16MHz,
          static_cast<std::uint32_t>(ARR::TICK_60000)
        );
        // Only 65535 ticks are possible, hence multiple minute iterations
        for (size_t i = 0; i < n; i++)
        {
          // Wait for an update event
          while(!update_event());
          clear_update();
        }
        deactivate_timer();
        // return after n iterations of a minute
        return;
    }
    // Wait for an update event
    while(!update_event());
    deactivate_timer();
  }

  void BasicTimer::activate_timer(PSC psc, std::uint32_t arr)
  {
    // Set the Prescaler value
    set_bits(basic_timer_regs_->PSC, psc);
    // Clear the Auto Reload value
    clear_bits(basic_timer_regs_->ARR, ARR::MAX_VAL);
    // Set the Auto Reload value, i.e. #ticks
    set_bits(basic_timer_regs_->ARR, arr);
    // Force update to load PSC immediately
    set_bits(basic_timer_regs_->EGR, EGR::UG);
    clear_update();
    // Enable/start the timer
    set_bits(basic_timer_regs_->CR1, CR1::CEN);
  }
  
  bool BasicTimer::update_event()
  {
    // Check the update interrupt flag
    return test_bits(basic_timer_regs_->SR, SR::UIF);
  }
  
  void BasicTimer::clear_update()
  {
    // Clear the update interrupt flag
    clear_bits(basic_timer_regs_->SR, SR::UIF);
  }

  void BasicTimer::deactivate_timer()
  {
    // Disable/start the timer
    clear_bits(basic_timer_regs_->CR1, CR1::CEN);
    // Undo forced update to load PSC immediately
    clear_bits(basic_timer_regs_->EGR, EGR::UG);
    // Clear the Prescaler value
    clear_bits(
      basic_timer_regs_->PSC,
      PSC::MAX_VAL
    );
    // Clear the Auto Reload value
    clear_bits(
      basic_timer_regs_->ARR, 
      ARR::MAX_VAL
    );
    /** Clear UE in case UE fired during this function */
    clear_update();
  }
  
}