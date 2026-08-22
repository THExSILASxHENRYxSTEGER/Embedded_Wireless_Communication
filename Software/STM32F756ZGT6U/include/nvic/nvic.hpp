#pragma once

#include <global/addresses.hpp>
#include "nvic/nvic_bits.hpp"
#include "nvic/nvic_regs.hpp"

namespace nvic{
    
  class NVIC
  {
    public:
      
      /**
       * @brief Construct a new Nested Vector Interrupt Control (NVIC) object, 
       * which controls (enable, disable, etc.) the interrupts on the cortex side of the stm32.
       * 
       * @param nvic_address The address of register NVIC_ISER0, where the NVIC registers start.
       */
      NVIC(const std::uint32_t nvic_address);

      /**
       * @brief Set a bit in any of the NVIC registers given the actual
       * register and the number of the interrupt in the interrupt table.
       * 
       * @param base_reg The actual register in which a bit is set.
       * @param irq_n The number of the actual interrupt in the interrupt table.
       */
      void set_reg(volatile std::uint32_t& base_reg, IRQn irq_n);

      /**
       * @brief Set a bit in any of the NVIC registers given the actual
       * register and the number of the interrupt in the interrupt table.
       * 
       * @param base_reg The actual register in which a bit is cleared.
       * @param irq_n The number of the actual interrupt in the interrupt table.
       */
      void clear_reg(volatile std::uint32_t& base_reg, IRQn irq_n);

      /**
       * @brief Test a bit to be set in any of the NVIC registers given the actual
       * register and the number of the interrupt in the interrupt table.
       * 
       * @param base_reg The actual register in which a bit is tested to be set.
       * @param irq_n The number of the actual interrupt in the interrupt table.
       * 
       * @return true When the bit irq_n in base_reg is set else false
       */
      bool test_reg(volatile std::uint32_t& base_reg, IRQn irq_n);

      /**
       * @brief Enable an interrupt by setting the corresponding bit in the NVIC_ISERx register.
       * 
       * @param irq_n The number in the interrupt table of the actual interrupt to be enabled.
       */
      void NVIC_EnableIRQ(IRQn irq_n);
      
      /**
       * @brief Disable an interrupt by setting the corresponding bit in the NVIC_ICERx register.
       * 
       * @param irq_n The number in the interrupt table of the actual interrupt to be disabled.
       */
      void NVIC_DisableIRQ(IRQn irq_n);

      /**
       * @brief Set an interrupt pending by setting the corresponding bit in the NVIC_ISPRx register.
       * 
       * @param irq_n The number in the interrupt table of the actual interrupt to be set pending.
       */
      void NVIC_SetPendingIRQ(IRQn irq_n);

      /**
       * @brief Clear a pending interrupt by setting the corresponding bit in the NVIC_ICPRx register.
       * 
       * @param irq_n The number in the interrupt table of the actual interrupt to be cleared from being pending.
       */
      void NVIC_ClearPendingIRQ(IRQn irq_n);

      /**
       * @brief Check if an interrupt is pending by querying the corresponding bit in the NVIC_ISPRx register.
       * 
       * @param irq_n The number in the interrupt table of the actual interrupt to be checked to be pending.
       * @return true The interrupt is pending.
       * @return false The interrupt is not pending.
       */
      bool NVIC_GetPendingIRQ(IRQn irq_n);

      /**
       * @brief Set a priority for the given interrupt. 
       * 
       * @param irq_n The number in the interrupt table of the actual interrupt to have a priority set.
       * @param priority The priority to set the interupt to.
       */
      void NVIC_SetPriority(IRQn irq_n, NVIC_IPR priority);

      /**
       * @brief Get the priority of the given interrupt. 
       * 
       * @param irq_n The number in the interrupt table of the actual interrupt to query the priority from.
       * 
       * @return The priority of the interrupt checked.
       */
      std::uint32_t NVIC_GetPriority(IRQn irq_n);

      /**
       * @brief Check if an interrupt is active by querying the corresponding bit in the NVIC_IABRx register.
       * 
       * @param irq_n The number in the interrupt table of the actual interrupt to be checked to be active.
       * @return true The interrupt is active.
       * @return false The interrupt is not active.
       */
      bool NVIC_GetActive(IRQn irq_n);

      ~NVIC() = default;

    private:

      volatile NVIC_REGS* nvic_regs_;
    
  };

  /** NVIC controller */
  inline NVIC nvic(addresses::NVIC_ISER0);
  
}