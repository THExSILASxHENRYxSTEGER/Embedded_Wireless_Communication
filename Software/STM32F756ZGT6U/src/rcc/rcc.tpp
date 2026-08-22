#include <rcc/rcc.hpp>

#include "utils/enum_utils.hpp"
#include "utils/bit_manipultion.hpp"
#include "rcc/rcc_bits.hpp"

namespace rcc {

  RCC::RCC(const std::uint32_t rcc_address)
  :
    rcc_regs_(reinterpret_cast<volatile RCC_REGS*>(rcc_address))
  {}

  template<typename P>
  requires (
    std::same_as<P, RCC_AHB1ENR> || 
    std::same_as<P, RCC_AHB2ENR> || 
    std::same_as<P, RCC_AHB3ENR> ||
    std::same_as<P, RCC_APB1ENR> ||
    std::same_as<P, RCC_APB2ENR>
  )
  void RCC::peripheral_clk_enable(P peripheral)
  {
    if constexpr (std::same_as<P, RCC_AHB1ENR>) {
      // Set bits in the RCC_AHB1ENR register
      set_bits(rcc_regs_->RCC_AHB1ENR, peripheral);
    } else if constexpr (std::same_as<P, RCC_AHB2ENR>) {
      // Set bits in the RCC_AHB2ENR register
      set_bits(rcc_regs_->RCC_AHB2ENR, peripheral);
    } else if constexpr (std::same_as<P, RCC_AHB3ENR>) {
      // Set bits in the RCC_AHB3ENR register
      set_bits(rcc_regs_->RCC_AHB3ENR, peripheral);
    } else if constexpr (std::same_as<P, RCC_APB1ENR>) {
      // Set bits in the RCC_APB1ENR register
      set_bits(rcc_regs_->RCC_APB1ENR, peripheral);
    } else {
      // Set bits in the RCC_APB2ENR register
      set_bits(rcc_regs_->RCC_APB2ENR, peripheral);
    }
  }

}