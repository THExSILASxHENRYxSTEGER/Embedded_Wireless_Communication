/**
 * @file gpio.hpp
 * @brief Instantiate a class that can manipulate one set of GPIO port registers.
 */
#pragma once

#include "addresses/addresses.hpp"
#include "gpio/gpio_bits.hpp"
#include "gpio_regs.hpp"

#include <cstdint>

namespace gpio
{

  /**
   * @class GPIO_PORT
   * @brief Provides access to one individual GPIO port peripheral between ports A to K.
   *
   * This class wraps one specific set of GPIO port registers and provides
   * functions for configuring and controlling pins.
   */
  class GPIO_PORT
  {
    public:
      
      /**
       * @brief Constructs a GPIO port object.
       *
       * @param port_address Physical hardware base address of the GPIO port peripheral.
       */
      GPIO_PORT(const std::uint32_t port_address);

      /**
       * @brief Initializes the GPIO pin to be made ready to be pulled up or down.
       *
       * @param gpio_pin The pin to modify.
       * @param speed The speed set in the ort output speed register (GPIOx_OSPEEDR).
       * 
       * After execution the corresponding pin can be either pulled up or down.
       */
      void set_pin_pup_output(GPIO_PIN gpio_pin, std::uint32_t speed=0);

      /**
       * @brief Pull GPIO pin down.
       *
       * @param gpio_pin The pin to be pulled down.
       * 
       * After execution the corresponding pin is at 0V.
       */
      void pull_pin_down(GPIO_PIN gpio_pin);

      /**
       * @brief Pull GPIO pin up.
       *
       * @param gpio_pin The pin to be pulled up.
       * 
       * After execution the corresponding pin is at 3.3V.
       */
      void pull_pin_up(GPIO_PIN gpio_pin);
      
      /**
       * @brief Default destruction of the GPIO port object.
       */
      ~GPIO_PORT() = default;
  
    private:

      /** GPIO port registers. */
      volatile GPIO_PORT_REGS* port_regs_; 

  };


  /** GPIO Port A peripheral instance. */
  inline GPIO_PORT port_A(addresses::GPIO_PORT_A);

  /** GPIO Port B peripheral instance. */ 
  inline GPIO_PORT port_B(addresses::GPIO_PORT_B);

  /** GPIO Port C peripheral instance. */ 
  inline GPIO_PORT port_C(addresses::GPIO_PORT_C);

  /** GPIO Port D peripheral instance. */ 
  inline GPIO_PORT port_D(addresses::GPIO_PORT_D);

  /** GPIO Port E peripheral instance. */ 
  inline GPIO_PORT port_E(addresses::GPIO_PORT_E);

  /** GPIO Port F peripheral instance. */ 
  inline GPIO_PORT port_F(addresses::GPIO_PORT_F);

  /** GPIO Port G peripheral instance. */ 
  inline GPIO_PORT port_G(addresses::GPIO_PORT_G);

  /** GPIO Port H peripheral instance. */ 
  inline GPIO_PORT port_H(addresses::GPIO_PORT_H);

  /** GPIO Port I peripheral instance. */ 
  inline GPIO_PORT port_I(addresses::GPIO_PORT_I);

  /** GPIO Port J peripheral instance. */ 
  inline GPIO_PORT port_J(addresses::GPIO_PORT_J);

  /** GPIO Port K peripheral instance. */ 
  inline GPIO_PORT port_K(addresses::GPIO_PORT_K); 

}


