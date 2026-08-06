#include "rcc/rcc.hpp"
#include "rcc/rcc_bits.hpp"
#include "gpio/gpio.hpp"
#include "gpio/gpio_bits.hpp"

#include <cstdint>


int main(){
  
  rcc::rcc.peripheral_clk_enable(rcc::RCC_AHB1ENR::GPIOFEN);
  
  gpio::port_F.set_pin_pup_output(gpio::GPIO_PIN::GPIO_PIN_12);

  gpio::port_F.pull_pin_up(gpio::GPIO_PIN::GPIO_PIN_12);

  for(;;);
  
  return 0;
}