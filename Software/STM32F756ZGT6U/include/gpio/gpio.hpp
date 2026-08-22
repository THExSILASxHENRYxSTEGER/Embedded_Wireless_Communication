/**
 * @file gpio.hpp
 * @brief Instantiate a class that can manipulate one set of GPIO port registers.
 */
#pragma once

#include "global/addresses.hpp"
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
       * @brief Initializes the GPIO pin to be in any of the operational modes of the GPIOx_MODER register.
       * 
       * @param pin_num The corresponding pin to be initialized.
       * @param gpio_moder The mode the pin is set to.
       * 
       * The pin can be set to be in Input mode (reset state), General purpose output mode,
       * Alternate function mode, Analog mode.
       */
      void set_pin_mode(GPIO_PIN pin_num, GPIO_MODER gpio_moder);

      /**
       * @brief Manipulate output type and speed of the corresponding pin.
       *
       * @param gpio_pin The pin to modify.
       * @param speed The speed set the port output speed register (GPIOx_OSPEEDR).
       * 
       * After execution the corresponding pin is ready to be pulled up and used at the given speed.
       * For that manipulate the GPIOx_OTYPER and the GPIOx_OSPEEDR register.
       */
      void set_pin_pup_speed(GPIO_PIN pin_num, GPIO_OSPEEDR gpio_speed);

      /**
       * @brief Pull GPIO pin down.
       *
       * @param pin_num The pin to be pulled down.
       * 
       * After execution the corresponding pin is at 0V.
       */
      void pull_pin_down(GPIO_PIN pin_num);

      /**
       * @brief Pull GPIO pin up.
       *
       * @param pin_num The pin to be pulled up.
       * 
       * After execution the corresponding pin is at 3.3V.
       */
      void pull_pin_up(GPIO_PIN pin_num);

      /**
       * @brief Prepare everything for the pin to be used in alternate function mode.
       * 
       * @param pin_num The pin to be set to alternative function mode.
       * @param gpio_af The alternative function to set the pin to.
       * @param gpio_speed The speed that the pin is set to.
       * @param pin_up If true this pulls the pin up to 3.3V
       * 
       * After the call the corresponding pins GPIOx_MODER register is enabled to be of type
       * alternate function and GPIOx_AFRL or GPIOx_AFRH is set to that alternative function.
       */
      void enable_and_set_pin_AF(GPIO_PIN pin_num, GPIO_AF gpio_af, GPIO_OSPEEDR gpio_speed, bool pin_up=false);
      
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


