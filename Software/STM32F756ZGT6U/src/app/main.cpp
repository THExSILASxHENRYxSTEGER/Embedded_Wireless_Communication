#include "global/clock_vars.hpp"
#include "gpio/gpio.hpp"
#include "gpio/gpio_bits.hpp"
#include "nvic/nvic_bits.hpp"
#include "nvic/nvic.hpp"
#include "rcc/rcc.hpp"
#include "rcc/rcc_bits.hpp"
#include "input_buffer/input_buffer.hpp"
#include "usart/usart.hpp"

#include <cstdint>

int main(){
  
  // Enable clock for pins on port D for usart 2
  rcc::rcc.peripheral_clk_enable(rcc::RCC_AHB1ENR::GPIODEN);
  // Enable clock of usart 2
  rcc::rcc.peripheral_clk_enable(rcc::RCC_APB1ENR::USART2EN);  
  // Enable GPIO USART2 TX, RX, and CK
  gpio::port_D.enable_and_set_pin_AF(gpio::GPIO_PIN::GPIO_PIN_5, gpio::GPIO_AF::AF7, gpio::GPIO_OSPEEDR::MEDIUM_SPEED); // use variadic function here if works
  gpio::port_D.enable_and_set_pin_AF(gpio::GPIO_PIN::GPIO_PIN_6, gpio::GPIO_AF::AF7, gpio::GPIO_OSPEEDR::MEDIUM_SPEED);
  gpio::port_D.enable_and_set_pin_AF(gpio::GPIO_PIN::GPIO_PIN_7, gpio::GPIO_AF::AF7, gpio::GPIO_OSPEEDR::MEDIUM_SPEED);

  // Initialize NVIC 
  nvic::nvic.NVIC_EnableIRQ(nvic::IRQn::USART2);

  // Initialize USART
  usart::usart_2.init(CLK_FREQ::_16_MHZ, BAUD_RATE::_9_6_K);

  // Send text over USART
  usart::usart_2.send_string("Hello, what would you like to tell me?:\n");

  // Receive an answer
  while(true)
  {
    // Wait until usart has read all characters of the search request
    while(!input_buffer::ib.answered());
    // Print the answer
    usart::usart_2.send_string("\nYou have entered:\n");
    input_buffer::ib.print(usart::usart_2);
    // Prompt the user for new input
    usart::usart_2.send_string("\nYou can now tell me something else.\n");
    // Empty the input character data buffer
    input_buffer::ib.clear();
  }  
  
  return 0;
}