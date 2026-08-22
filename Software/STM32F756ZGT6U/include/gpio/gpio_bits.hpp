/**
 * @file gpio_bits.hpp
 * @brief GPIO register bits to change registers in GPIO_PORT_REGS.
 */
#pragma once

#include <cstdint>

namespace gpio {
  
  /**
   * @brief GPIO pin numbers available at every port from A to K.
   * 
   * Use these values to address which GPIO pin is manipulated generally.
   */
  enum class GPIO_PIN : std::uint32_t
  {
    GPIO_PIN_0  = 0u,     // GPIO Pin 0
    GPIO_PIN_1  = 1u,     // GPIO Pin 1
    GPIO_PIN_2  = 2u,     // GPIO Pin 2
    GPIO_PIN_3  = 3u,     // GPIO Pin 3
    GPIO_PIN_4  = 4u,     // GPIO Pin 4
    GPIO_PIN_5  = 5u,     // GPIO Pin 5
    GPIO_PIN_6  = 6u,     // GPIO Pin 6
    GPIO_PIN_7  = 7u,     // GPIO Pin 7
    GPIO_PIN_8  = 8u,     // GPIO Pin 8
    GPIO_PIN_9  = 9u,     // GPIO Pin 9
    GPIO_PIN_10 = 10u,    // GPIO Pin 10
    GPIO_PIN_11 = 11u,    // GPIO Pin 11
    GPIO_PIN_12 = 12u,    // GPIO Pin 12
    GPIO_PIN_13 = 13u,    // GPIO Pin 13
    GPIO_PIN_14 = 14u,    // GPIO Pin 14
    GPIO_PIN_15 = 15u,    // GPIO Pin 15
  };

  /**
   * @brief GPIO port mode register bits.
   * 
   * Use these values to manipulate the GPIOx_MODER register.
   */
  enum class GPIO_MODER : std::uint32_t
  {
    INPUT_MODE  = 0u,   // Pin in input mode
    OUTPUT_MODE = 1u,   // Pin in general purpose output mode 
    AF_MODE     = 2u,   // Pin in alternate function mode
    ANALOG_MODE = 3u,   // Pin in analog mode
  };
  
  /**
   * @brief GPIO port output type register bits.
   * 
   * Use these values to manipulate the GPIOx_OTYPER register.
   */
  enum class GPIO_OTYPER : std::uint32_t
  {
    OT0  = 1u << 0,   // Pin 0 output type selection
    OT1  = 1u << 1,   // Pin 1 output type selection
    OT2  = 1u << 2,   // Pin 2 output type selection
    OT3  = 1u << 3,   // Pin 3 output type selection
    OT4  = 1u << 4,   // Pin 4 output type selection
    OT5  = 1u << 5,   // Pin 5 output type selection
    OT6  = 1u << 6,   // Pin 6 output type selection
    OT7  = 1u << 7,   // Pin 7 output type selection
    OT8  = 1u << 8,   // Pin 8 output type selection
    OT9  = 1u << 9,   // Pin 9 output type selection
    OT10 = 1u << 10,  // Pin 10 output type selection
    OT11 = 1u << 11,  // Pin 11 output type selection
    OT12 = 1u << 12,  // Pin 12 output type selection
    OT13 = 1u << 13,  // Pin 13 output type selection
    OT14 = 1u << 14,  // Pin 14 output type selection
    OT15 = 1u << 15,  // Pin 15 output type selection
  };
 
  /**
   * @brief GPIO port output speed register bits.
   * 
   * Use these values to manipulate the GPIOx_OSPEEDR register.
   */  
  enum class GPIO_OSPEEDR : std::uint32_t
  {
    LOW_SPEED       = 0u,   // Pin speed low 
    MEDIUM_SPEED    = 1u,   // Pin speed medium 
    HIGH_SPEED      = 2u,   // Pin speed high 
    VERY_HIGH_SPEED = 3u,   // Pin speed very high  
  };

  /**
   * @brief GPIO port pull-up/pull-down register bits.
   * 
   * Use these values to manipulate the GPIOx_PUPDR register.
   */  
  enum class GPIO_PUPDR : std::uint32_t
  {
    PIN0UP    = 1u << 0,  // Pin 0  Pulled UP
    PIN0DOWN  = 1u << 1,  // Pin 0  Pulled DOWN
    PIN1UP    = 1u << 2,  // Pin 1  Pulled UP
    PIN1DOWN  = 1u << 3,  // Pin 1  Pulled DOWN
    PIN2UP    = 1u << 4,  // Pin 2  Pulled UP
    PIN2DOWN  = 1u << 5,  // Pin 2  Pulled DOWN
    PIN3UP    = 1u << 6,  // Pin 3  Pulled UP
    PIN3DOWN  = 1u << 7,  // Pin 3  Pulled DOWN
    PIN4UP    = 1u << 8,  // Pin 4  Pulled UP
    PIN4DOWN  = 1u << 9,  // Pin 4  Pulled Down
    PIN5UP    = 1u << 10, // Pin 5  Pulled UP
    PIN5DOWN  = 1u << 11, // Pin 5  Pulled Down
    PIN6UP    = 1u << 12, // Pin 6  Pulled UP
    PIN6DOWN  = 1u << 13, // Pin 6  Pulled Down
    PIN7UP    = 1u << 14, // Pin 7  Pulled UP
    PIN7DOWN  = 1u << 15, // Pin 7  Pulled Down
    PIN8UP    = 1u << 16, // Pin 8  Pulled UP
    PIN8DOWN  = 1u << 17, // Pin 8  Pulled DOWN
    PIN9UP    = 1u << 18, // Pin 9  Pulled UP
    PIN9DOWN  = 1u << 19, // Pin 9  Pulled DOWN
    PIN10UP   = 1u << 20, // Pin 10 Pulled UP
    PIN10DOWN = 1u << 21, // Pin 10 Pulled DOWN
    PIN11UP   = 1u << 22, // Pin 11 Pulled UP
    PIN11DOWN = 1u << 23, // Pin 11 Pulled DOWN
    PIN12UP   = 1u << 24, // Pin 12 Pulled UP
    PIN12DOWN = 1u << 25, // Pin 12 Pulled Down
    PIN13UP   = 1u << 26, // Pin 13 Pulled UP
    PIN13DOWN = 1u << 27, // Pin 13 Pulled Down
    PIN14UP   = 1u << 28, // Pin 14 Pulled UP
    PIN14DOWN = 1u << 29, // Pin 14 Pulled Down
    PIN15UP   = 1u << 30, // Pin 15 Pulled UP
    PIN15DOWN = 1u << 31, // Pin 15 Pulled Down
  };
  
  /**
   * @brief GPIO port input data register bits.
   * 
   * Use these values to manipulate the GPIOx_IDR register.
   */  
  enum class GPIO_IDR : std::uint32_t
  {
    IDR0   = 1u << 0,   // Pin 0 input data
    IDR1   = 1u << 1,   // Pin 1 input data
    IDR2   = 1u << 2,   // Pin 2 input data
    IDR3   = 1u << 3,   // Pin 3 input data
    IDR4   = 1u << 4,   // Pin 4 input data
    IDR5   = 1u << 5,   // Pin 5 input data
    IDR6   = 1u << 6,   // Pin 6 input data
    IDR7   = 1u << 7,   // Pin 7 input data
    IDR8   = 1u << 8,   // Pin 8 input data
    IDR9   = 1u << 9,   // Pin 9 input data
    IDR10  = 1u << 10,  // Pin 10 input data
    IDR11  = 1u << 11,  // Pin 11 input data
    IDR12  = 1u << 12,  // Pin 12 input data
    IDR13  = 1u << 13,  // Pin 13 input data
    IDR14  = 1u << 14,  // Pin 14 input data
    IDR15  = 1u << 15,  // Pin 15 input data
  };
  
  /**
   * @brief GPIO port output data register bits.
   * 
   * Use these values to manipulate the GPIOx_ODR register.
   */ 
  enum class GPIO_ODR : std::uint32_t
  {
    ODR0   = 1u << 0,   // Pin 0 output data
    ODR1   = 1u << 1,   // Pin 1 output data
    ODR2   = 1u << 2,   // Pin 2 output data
    ODR3   = 1u << 3,   // Pin 3 output data
    ODR4   = 1u << 4,   // Pin 4 output data
    ODR5   = 1u << 5,   // Pin 5 output data
    ODR6   = 1u << 6,   // Pin 6 output data
    ODR7   = 1u << 7,   // Pin 7 output data
    ODR8   = 1u << 8,   // Pin 8 output data
    ODR9   = 1u << 9,   // Pin 9 output data
    ODR10  = 1u << 10,  // Pin 10 output data
    ODR11  = 1u << 11,  // Pin 11 output data
    ODR12  = 1u << 12,  // Pin 12 output data
    ODR13  = 1u << 13,  // Pin 13 output data
    ODR14  = 1u << 14,  // Pin 14 output data
    ODR15  = 1u << 15,  // Pin 15 output data
  };

  /**
   * @brief GPIO port bit set/reset register bits.
   * 
   * Use these values to manipulate the GPIOx_BSRR register.
   */
  enum class GPIO_BSRR : std::uint32_t
  {
    BS0   = 1u << 0,   // Pin 0 set bit
    BS1   = 1u << 1,   // Pin 1 set bit
    BS2   = 1u << 2,   // Pin 2 set bit
    BS3   = 1u << 3,   // Pin 3 set bit
    BS4   = 1u << 4,   // Pin 4 set bit
    BS5   = 1u << 5,   // Pin 5 set bit
    BS6   = 1u << 6,   // Pin 6 set bit
    BS7   = 1u << 7,   // Pin 7 set bit
    BS8   = 1u << 8,   // Pin 8 set bit
    BS9   = 1u << 9,   // Pin 9 set bit
    BS10  = 1u << 10,  // Pin 10 set bit
    BS11  = 1u << 11,  // Pin 11 set bit
    BS12  = 1u << 12,  // Pin 12 set bit
    BS13  = 1u << 13,  // Pin 13 set bit
    BS14  = 1u << 14,  // Pin 14 set bit
    BS15  = 1u << 15,  // Pin 15 set bit
    BR0   = 1u << 16,  // Pin 0 reset bit
    BR1   = 1u << 17,  // Pin 1 reset bit
    BR2   = 1u << 18,  // Pin 2 reset bit
    BR3   = 1u << 19,  // Pin 3 reset bit
    BR4   = 1u << 20,  // Pin 4 reset bit
    BR5   = 1u << 21,  // Pin 5 reset bit
    BR6   = 1u << 22,  // Pin 6 reset bit
    BR7   = 1u << 23,  // Pin 7 reset bit
    BR8   = 1u << 24,  // Pin 8 reset bit
    BR9   = 1u << 25,  // Pin 9 reset bit
    BR10  = 1u << 26,  // Pin 10 reset bit
    BR11  = 1u << 27,  // Pin 11 reset bit
    BR12  = 1u << 28,  // Pin 12 reset bit
    BR13  = 1u << 29,  // Pin 13 reset bit
    BR14  = 1u << 30,  // Pin 14 reset bit
    BR15  = 1u << 31,  // Pin 15 reset bit
  };
 
  /**
   * @brief GPIO port configuration lock register bits.
   * 
   * Use these values to manipulate the GPIOx_LCKR register.
   */
  enum class GPIO_LCKR : std::uint32_t
  {
    LCK0  = 1u << 0,   // Pin 0 configuration lock bit
    LCK1  = 1u << 1,   // Pin 1 configuration lock bit
    LCK2  = 1u << 2,   // Pin 2 configuration lock bit
    LCK3  = 1u << 3,   // Pin 3 configuration lock bit
    LCK4  = 1u << 4,   // Pin 4 configuration lock bit
    LCK5  = 1u << 5,   // Pin 5 configuration lock bit
    LCK6  = 1u << 6,   // Pin 6 configuration lock bit
    LCK7  = 1u << 7,   // Pin 7 configuration lock bit
    LCK8  = 1u << 8,   // Pin 8 configuration lock bit
    LCK9  = 1u << 9,   // Pin 9 configuration lock bit
    LCK10 = 1u << 10,  // Pin 10 configuration lock bit
    LCK11 = 1u << 11,  // Pin 11 configuration lock bit
    LCK12 = 1u << 12,  // Pin 12 configuration lock bit
    LCK13 = 1u << 13,  // Pin 13 configuration lock bit
    LCK14 = 1u << 14,  // Pin 14 configuration lock bit
    LCK15 = 1u << 15,  // Pin 15 configuration lock bit
    LCKK = 1u << 16,   // Lock key bit
  };

  /**
   * @brief GPIO alternate function register bits.
   * 
   * Use these values to manipulate the GPIOx_AFRL and the GPIOx_AFRH register.
   */
  enum class GPIO_AF : std::uint32_t
  {
    AF0   = 0,   // alternate function 0
    AF1   = 1,   // alternate function 1
    AF2   = 2,   // alternate function 2
    AF3   = 3,   // alternate function 3
    AF4   = 4,   // alternate function 4
    AF5   = 5,   // alternate function 5
    AF6   = 6,   // alternate function 6
    AF7   = 7,   // alternate function 7
    AF8   = 8,   // alternate function 8
    AF9   = 9,   // alternate function 9
    AF10  = 10,  // alternate function 10
    AF11  = 11,  // alternate function 11
    AF12  = 12,  // alternate function 12
    AF13  = 13,  // alternate function 13
    AF14  = 14,  // alternate function 14
    AF15  = 15,  // alternate function 15
  };
   
}