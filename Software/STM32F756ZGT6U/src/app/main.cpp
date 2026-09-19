#include "basic_timer/basic_timer.hpp"
#include "global/clock_vars.hpp"
#include "gpio/gpio.hpp"
#include "gpio/gpio_bits.hpp"
#include "input_buffer/input_buffer.hpp"
#include "i2c/i2c.hpp"
#include "nvic/nvic_bits.hpp"
#include "nvic/nvic.hpp"
#include "rcc/rcc.hpp"
#include "rcc/rcc_bits.hpp"
#include "usart/usart.hpp"

#include <cstdint>

int main(){

  // Enable basic timer 6
  rcc::rcc.peripheral_clk_enable(rcc::RCC_APB1ENR::TIM6EN);
  
  // Enable clock for pins on port D for usart2
  rcc::rcc.peripheral_clk_enable(rcc::RCC_AHB1ENR::GPIODEN);

  // Enable clock for pins on port B for i2c2
  rcc::rcc.peripheral_clk_enable(rcc::RCC_AHB1ENR::GPIOBEN);
  
  // Enable clock of usart2
  rcc::rcc.peripheral_clk_enable(rcc::RCC_APB1ENR::USART2EN);

  // Enable clock of i2c1
  rcc::rcc.peripheral_clk_enable(rcc::RCC_APB1ENR::I2C2EN);
  
  // Enable GPIO USART2 TX, RX, and CK
  gpio::port_D.enable_and_set_pin_AF(gpio::GPIO_PIN::GPIO_PIN_5, gpio::GPIO_AF::AF7, gpio::GPIO_OTYPER::PUSH_PULL, gpio::GPIO_OSPEEDR::MEDIUM_SPEED, false); // use variadic function here if works
  gpio::port_D.enable_and_set_pin_AF(gpio::GPIO_PIN::GPIO_PIN_6, gpio::GPIO_AF::AF7, gpio::GPIO_OTYPER::PUSH_PULL, gpio::GPIO_OSPEEDR::MEDIUM_SPEED, false);
  gpio::port_D.enable_and_set_pin_AF(gpio::GPIO_PIN::GPIO_PIN_7, gpio::GPIO_AF::AF7, gpio::GPIO_OTYPER::PUSH_PULL, gpio::GPIO_OSPEEDR::MEDIUM_SPEED, false);
  
  // Enable clock of Enable I2C2 SCl and SDA
  gpio::port_B.enable_and_set_pin_AF(gpio::GPIO_PIN::GPIO_PIN_10, gpio::GPIO_AF::AF4, gpio::GPIO_OTYPER::OPEN_DRAIN, gpio::GPIO_OSPEEDR::MEDIUM_SPEED, true); // use variadic function here if works
  gpio::port_B.enable_and_set_pin_AF(gpio::GPIO_PIN::GPIO_PIN_11, gpio::GPIO_AF::AF4, gpio::GPIO_OTYPER::OPEN_DRAIN, gpio::GPIO_OSPEEDR::MEDIUM_SPEED, true);  

  // Initialize NVIC 
  nvic::nvic.NVIC_EnableIRQ(nvic::IRQn::USART2);

  // Initialize I2C2
  bool i2c_init = i2c::i2c2.init(
    i2c::TIMING_CONST::SYSCLK_16_MHZ::Sm_100_KHZ::SCLL,
    i2c::TIMING_CONST::SYSCLK_16_MHZ::Sm_100_KHZ::SCLH,
    i2c::TIMING_CONST::SYSCLK_16_MHZ::Sm_100_KHZ::SDADEL,
    i2c::TIMING_CONST::SYSCLK_16_MHZ::Sm_100_KHZ::SCLDEL,
    i2c::TIMING_CONST::SYSCLK_16_MHZ::Sm_100_KHZ::PRESC
  );
  
  // Terminate if no I2C slave address was found
  if (!i2c_init)
    return 0;

  // Wait for the timer
  //basic_timer::basic_timer_6.wait_for(37,%20basic_timer::DURATION::MICRO_SECONDS)

  // Initialize USART2
  usart::usart_2.init(CLK_FREQ::_16_MHZ, BAUD_RATE::_9_6_K);

  // Send text over USART
  usart::usart_2.send_string("Hello, what would you like to tell me?:\n");

  input_buffer::ib.clear();
  // Receive an answer
  while(true)
  {
    // Wait until usart has read all characters of the search request
    while(!input_buffer::ib.answered());
    // Print the answer
    usart::usart_2.send_string("\nYour message is sent to I2C:\n");
    i2c::i2c2.send_string(input_buffer::ib);

    // Prompt the user for new input
    usart::usart_2.send_string("\nSent successfully, you can now tell me something else.\n");
    // Empty the input character data buffer
    input_buffer::ib.clear();
  }
  
  return 0;
}
