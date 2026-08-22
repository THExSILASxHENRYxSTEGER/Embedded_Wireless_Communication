
#include <global/global_vars.hpp>
#include "nvic/nvic.hpp"
#include <utils/bit_manipultion.hpp>
#include <utils/enum_utils.hpp>

namespace nvic
{
  NVIC::NVIC(const std::uint32_t nvic_address)
  :
    nvic_regs_(reinterpret_cast<volatile NVIC_REGS*>(nvic_address))
  {}

  void NVIC::set_reg(volatile std::uint32_t& base_reg, IRQn irq_n)
  {
    // Get the register to be set
    std::uint32_t n_reg = irq_n / global_vars::REG_SZ;
    // Get the bit of the register to be set
    std::uint32_t n_bit = irq_n % global_vars::REG_SZ;
    // Get the base register
    volatile std::uint32_t* br = &base_reg;
    // Increment the base register to the correct register
    br += n_reg;
    // Set the bit in the correct register
    set_bits(*br, global_vars::BIT_0 << n_bit);
  }

  void NVIC::clear_reg(volatile std::uint32_t& base_reg, IRQn irq_n)
  {
    // Get the register to be cleared
    std::uint32_t n_reg = irq_n / global_vars::REG_SZ;
    // Get the bit of the register to be cleared
    std::uint32_t n_bit = irq_n % global_vars::REG_SZ;
    // Get the base register
    volatile std::uint32_t* br = &base_reg;
    // Increment the base register to the correct register
    br += n_reg;
    // Clear the bit in the correct register
    clear_bits(*br, global_vars::BIT_0 << n_bit);
  }

  bool NVIC::test_reg(volatile std::uint32_t& base_reg, IRQn irq_n)
  {
    // Get the register to be tested
    std::uint32_t n_reg = irq_n / global_vars::REG_SZ;
    // Get the bit of the register to be tested
    std::uint32_t n_bit = irq_n % global_vars::REG_SZ;
    // Get the base register
    volatile std::uint32_t* br = &base_reg;
    // Increment the base register to the correct register
    br += n_reg;
    // Test the bit in the correct register
    return test_bits(*br, global_vars::BIT_0 << n_bit);
  }
  
  void NVIC::NVIC_EnableIRQ(IRQn irq_n)
  {
    set_reg(nvic_regs_->NVIC_ISER0, irq_n);
  }

  void NVIC::NVIC_DisableIRQ(IRQn irq_n)
  {
    set_reg(nvic_regs_->NVIC_ICER0, irq_n);
  }
  
  void NVIC::NVIC_SetPendingIRQ(IRQn irq_n)
  {
    set_reg(nvic_regs_->NVIC_ISPR0, irq_n);
  }
  
  void NVIC::NVIC_ClearPendingIRQ(IRQn irq_n)
  {
    set_reg(nvic_regs_->NVIC_ICPR0, irq_n);
  }
  
  bool NVIC::NVIC_GetPendingIRQ(IRQn irq_n)
  {
    return test_reg(nvic_regs_->NVIC_ISPR0, irq_n);
  }
  
  void NVIC::NVIC_SetPriority(IRQn irq_n, NVIC_IPR priority)
  {
    // Get the register to be cleared
    std::uint32_t n_reg = irq_n / global_vars::EIGTH_REG_SZ;
    // Get the bit of the register to be set
    std::uint32_t shift = irq_n % global_vars::EIGTH_REG_SZ;
    // Get the base register
    volatile std::uint32_t* br = &nvic_regs_->NVIC_IPR0;
    // Increment the base register to the correct register
    br += n_reg;
    // Clear previous priority
    clear_bits(
      *br, 
      NVIC_IPR::PRIORITY_15 << shift * global_vars::EIGTH_REG_SZ
    );
    // Set new priority
    set_bits(
      *br, 
      priority << shift * global_vars::EIGTH_REG_SZ
    ); 
  }
  
  std::uint32_t NVIC::NVIC_GetPriority(IRQn irq_n)
  {
    // Get the register to be cleared
    std::uint32_t n_reg = irq_n / global_vars::EIGTH_REG_SZ;
    // Get the bit of the register to be set
    std::uint32_t shift = irq_n % global_vars::EIGTH_REG_SZ;
    // Get the base register
    volatile std::uint32_t* br = &nvic_regs_->NVIC_IPR0;
    // Increment the base register to the correct register
    br += n_reg;
    // Return the current priority level
    return (shift + global_vars::EIGTH_REG_SZ) >> *br;
  }
  
  bool NVIC::NVIC_GetActive(IRQn irq_n)
  {
    return test_reg(nvic_regs_->NVIC_IABR0, irq_n);
  }
}