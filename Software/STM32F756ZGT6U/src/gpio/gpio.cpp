#include "gpio/gpio.hpp"
#include "utils/enum_utils.hpp"
#include "utils/bit_manipultion.hpp"


namespace gpio
{
  constexpr std::uint32_t PIN_NUM_FACTOR = 2;

  GPIO_PORT::GPIO_PORT(const std::uint32_t port_address)
  :
    port_regs_(reinterpret_cast<volatile GPIO_PORT_REGS*>(port_address))
  {}
  
  void GPIO_PORT::set_pin_pup_output(GPIO_PIN pin_num, std::uint32_t speed){
    // change MODER register to activate pin in output mode
    const std::uint32_t moder_mask = GPIO_MODER::MODER0_0 << (pin_num * PIN_NUM_FACTOR);
    set_bits(port_regs_->MODER, moder_mask);
    // set pin to push-pull in OTYPER register
    clear_bits(port_regs_->OTYPER, 0x1u << pin_num);
    // set pin transition speed in OTYPER register
    const std::uint32_t speed_mask = speed << (pin_num * PIN_NUM_FACTOR);
    set_bits(port_regs_->OSPEEDR, speed_mask);
  }

  void GPIO_PORT::pull_pin_down(GPIO_PIN pin_num){
    // Clear the bits in the GPIOx_PUPDR register that pull the given pin up
    clear_bits(port_regs_->PUPDR, 0x1 << (pin_num * PIN_NUM_FACTOR));
    // Set the bits in the GPIOx_PUPDR register that pull the given pin down
    set_bits(port_regs_->PUPDR, 0x10 << (pin_num * PIN_NUM_FACTOR));
    // Set the bits in the GPIOx_BSRR register to reset the pin output
    set_bits(port_regs_->BSRR, 0x10000 << pin_num);
  }

  void GPIO_PORT::pull_pin_up(GPIO_PIN pin_num){
    // Clear the bits in the GPIOx_PUPDR register that pull the given pin down
    clear_bits(port_regs_->PUPDR, 0x10 << (pin_num * PIN_NUM_FACTOR));
    // Set the bits in the GPIOx_PUPDR register that pull the given pin up
    set_bits(port_regs_->PUPDR, 0x1 << (pin_num * PIN_NUM_FACTOR));
    // Set the bits in the GPIOx_BSRR register to reset the pin output
    set_bits(port_regs_->BSRR, 0x1 << pin_num);   
  }

}
