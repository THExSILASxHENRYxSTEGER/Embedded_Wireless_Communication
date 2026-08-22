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

  void GPIO_PORT::set_pin_mode(GPIO_PIN pin_num, GPIO_MODER gpio_moder)
  {
    // Clear previous state
    clear_bits(port_regs_->MODER, GPIO_MODER::ANALOG_MODE << (pin_num * PIN_NUM_FACTOR));
    // Set bits to GPIO mode
    const std::uint32_t moder_mask = gpio_moder << (pin_num * PIN_NUM_FACTOR);
    set_bits(port_regs_->MODER, moder_mask);
  }
  
  void GPIO_PORT::set_pin_pup_speed(GPIO_PIN pin_num, GPIO_OSPEEDR gpio_speed)
  {
    // set pin to push-pull in OTYPER register
    clear_bits(port_regs_->OTYPER, GPIO_OTYPER::OT0 << pin_num);
    // set pin transition speed in OTYPER register
    const std::uint32_t speed_mask = gpio_speed << (pin_num * PIN_NUM_FACTOR);
    set_bits(port_regs_->OSPEEDR, speed_mask);
  }

  void GPIO_PORT::pull_pin_down(GPIO_PIN pin_num)
  {
    // Clear the bits in the GPIOx_PUPDR register that pull the given pin up
    clear_bits(port_regs_->PUPDR, GPIO_PUPDR::PIN0UP << (pin_num * PIN_NUM_FACTOR));
    
    // Set the bits in the GPIOx_PUPDR register that pull the given pin down
    set_bits(port_regs_->PUPDR, GPIO_PUPDR::PIN0DOWN << (pin_num * PIN_NUM_FACTOR));
    
    // Set the bits in the GPIOx_BSRR register to reset the pin output
    set_bits(port_regs_->BSRR, GPIO_BSRR::BR0 << pin_num);
  }

  void GPIO_PORT::pull_pin_up(GPIO_PIN pin_num)
  {
    // Clear the bits in the GPIOx_PUPDR register that pull the given pin down
    clear_bits(port_regs_->PUPDR, GPIO_PUPDR::PIN0DOWN << (pin_num * PIN_NUM_FACTOR));
    
    // Set the bits in the GPIOx_PUPDR register that pull the given pin up
    set_bits(port_regs_->PUPDR, GPIO_PUPDR::PIN0UP << (pin_num * PIN_NUM_FACTOR));
    
    // Set the bits in the GPIOx_BSRR register to reset the pin output
    set_bits(port_regs_->BSRR, GPIO_BSRR::BS0 << pin_num);   
  }

  void GPIO_PORT::enable_and_set_pin_AF(GPIO_PIN pin_num, GPIO_AF gpio_af, GPIO_OSPEEDR gpio_speed, bool pin_up)
  {
    // Enable the pin with alternate function mode
    set_pin_mode(pin_num, GPIO_MODER::AF_MODE);
    // Set pin to push-pull and also set the speed
    set_pin_pup_speed(pin_num, gpio_speed);
    // Alternate functions take 4 bits
    const std::uint32_t af_bit_space = 4;
    // assign the pin the corresponding alternate function
    if (pin_num < GPIO_PIN::GPIO_PIN_8){
      const std::uint32_t afrl_mask = gpio_af << (pin_num * af_bit_space);
      set_bits(port_regs_->AFRL, afrl_mask);
    } else {
      const std::uint32_t afrh_mask = gpio_af << ((pin_num - GPIO_PIN::GPIO_PIN_8) * af_bit_space);
      set_bits(port_regs_->AFRH, afrh_mask);
    }
    // Optionally, pull the pin up
    if (pin_up) pull_pin_up(pin_num);
  }

}
