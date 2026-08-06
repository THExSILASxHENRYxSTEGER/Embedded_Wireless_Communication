/**
 * @file rcc_bits.hpp
 * @brief RCC register bits to change registers in RCC peripheral.
 */
#pragma once

#include <cstdint>

namespace rcc
{

  /**
   * @brief RCC clock control register bits.
   * 
   * Use these values to manipulate the RCC_CR register.
   */
  enum class RCC_CR : std::uint32_t
  {
    HSION      = 1u << 0,   // Internal high-speed clock enable
    HSIRDY     = 1u << 1,   // Internal high-speed clock ready flag
    HSITRIM0   = 1u << 3,   // Internal high-speed clock trimming bit 0
    HSITRIM1   = 1u << 4,   // Internal high-speed clock trimming bit 1
    HSITRIM2   = 1u << 5,   // Internal high-speed clock trimming bit 2
    HSITRIM3   = 1u << 6,   // Internal high-speed clock trimming bit 3
    HSITRIM4   = 1u << 7,   // Internal high-speed clock trimming bit 4
    HSICAL0    = 1u << 8,   // Internal high-speed clock calibration bit 0
    HSICAL1    = 1u << 9,   // Internal high-speed clock calibration bit 1
    HSICAL2    = 1u << 10,  // Internal high-speed clock calibration bit 2
    HSICAL3    = 1u << 11,  // Internal high-speed clock calibration bit 3
    HSICAL4    = 1u << 12,  // Internal high-speed clock calibration bit 4
    HSICAL5    = 1u << 13,  // Internal high-speed clock calibration bit 5
    HSICAL6    = 1u << 14,  // Internal high-speed clock calibration bit 6
    HSICAL7    = 1u << 15,  // Internal high-speed clock calibration bit 7
    HSEON      = 1u << 16,  // External high-speed clock enable
    HSERDY     = 1u << 17,  // External high-speed clock ready flag
    HSEBYP     = 1u << 18,  // External high-speed clock bypass
    CSSON      = 1u << 19,  // Clock security system enable
    PLLON      = 1u << 24,  // Main PLL enable
    PLLRDY     = 1u << 25,  // Main PLL ready flag
    PLLI2SON   = 1u << 26,  // PLLI2S enable
    PLLI2SRDY  = 1u << 27,  // PLLI2S ready flag
    PLLSAION   = 1u << 28,  // PLLSAI enable
    PLLSAIRDY  = 1u << 29,  // PLLSAI ready flag
  };

  /**
   * @brief RCC PLL configuration register bits.
   * 
   * Use these values to manipulate the RCC_PLLCFGR register.
   */
  enum class RCC_PLLCFGR : std::uint32_t
  {
    PLLM0      = 1u << 0,   // Division factor for the main PLL input clock bit 0
    PLLM1      = 1u << 1,   // Division factor for the main PLL input clock bit 1
    PLLM2      = 1u << 2,   // Division factor for the main PLL input clock bit 2
    PLLM3      = 1u << 3,   // Division factor for the main PLL input clock bit 3
    PLLM4      = 1u << 4,   // Division factor for the main PLL input clock bit 4
    PLLM5      = 1u << 5,   // Division factor for the main PLL input clock bit 5
    PLLN0      = 1u << 6,   // Main PLL multiplication factor bit 0
    PLLN1      = 1u << 7,   // Main PLL multiplication factor bit 1
    PLLN2      = 1u << 8,   // Main PLL multiplication factor bit 2
    PLLN3      = 1u << 9,   // Main PLL multiplication factor bit 3
    PLLN4      = 1u << 10,  // Main PLL multiplication factor bit 4
    PLLN5      = 1u << 11,  // Main PLL multiplication factor bit 5
    PLLN6      = 1u << 12,  // Main PLL multiplication factor bit 6
    PLLN7      = 1u << 13,  // Main PLL multiplication factor bit 7
    PLLN8      = 1u << 14,  // Main PLL multiplication factor bit 8
    PLLP0      = 1u << 16,  // Main PLL division factor for system clock bit 0
    PLLP1      = 1u << 17,  // Main PLL division factor for system clock bit 1
    PLLSRC     = 1u << 22,  // Main PLL entry clock source
    PLLQ0      = 1u << 24,  // Main PLL division factor for USB, SDMMC and RNG bit 0
    PLLQ1      = 1u << 25,  // Main PLL division factor for USB, SDMMC and RNG bit 1
    PLLQ2      = 1u << 26,  // Main PLL division factor for USB, SDMMC and RNG bit 2
    PLLQ3      = 1u << 27,  // Main PLL division factor for USB, SDMMC and RNG bit 3
  };
  
  /**
   * @brief RCC clock configuration register bits.
   * 
   * Use these values to manipulate the RCC_CFGR register.
   */
  enum class RCC_CFGR : std::uint32_t
  {
    SW0        = 1u << 0,   // System clock switch bit 0
    SW1        = 1u << 1,   // System clock switch bit 1
    SWS0       = 1u << 2,   // System clock switch status bit 0
    SWS1       = 1u << 3,   // System clock switch status bit 1
    HPRE0      = 1u << 4,   // AHB prescaler bit 0
    HPRE1      = 1u << 5,   // AHB prescaler bit 1
    HPRE2      = 1u << 6,   // AHB prescaler bit 2
    HPRE3      = 1u << 7,   // AHB prescaler bit 3
    PPRE10     = 1u << 10,  // APB1 low-speed prescaler bit 0
    PPRE11     = 1u << 11,  // APB1 low-speed prescaler bit 1
    PPRE12     = 1u << 12,  // APB1 low-speed prescaler bit 2
    PPRE20     = 1u << 13,  // APB2 high-speed prescaler bit 0
    PPRE21     = 1u << 14,  // APB2 high-speed prescaler bit 1
    PPRE22     = 1u << 15,  // APB2 high-speed prescaler bit 2
    RTCPRE0    = 1u << 16,  // HSE division factor for RTC clock bit 0
    RTCPRE1    = 1u << 17,  // HSE division factor for RTC clock bit 1
    RTCPRE2    = 1u << 18,  // HSE division factor for RTC clock bit 2
    RTCPRE3    = 1u << 19,  // HSE division factor for RTC clock bit 3
    RTCPRE4    = 1u << 20,  // HSE division factor for RTC clock bit 4
    MCO10      = 1u << 21,  // Microcontroller clock output 1 selection bit 0
    MCO11      = 1u << 22,  // Microcontroller clock output 1 selection bit 1
    I2SSRC     = 1u << 23,  // I2S clock selection
    MCO1PRE0   = 1u << 24,  // MCO1 prescaler bit 0
    MCO1PRE1   = 1u << 25,  // MCO1 prescaler bit 1
    MCO1PRE2   = 1u << 26,  // MCO1 prescaler bit 2
    MCO20      = 1u << 27,  // Microcontroller clock output 2 selection bit 0
    MCO21      = 1u << 28,  // Microcontroller clock output 2 selection bit 1
    MCO2PRE0   = 1u << 29,  // MCO2 prescaler bit 0
    MCO2PRE1   = 1u << 30,  // MCO2 prescaler bit 1
    MCO2PRE2   = 1u << 31,  // MCO2 prescaler bit 2
  };

  /**
   * @brief RCC clock interrupt register bits.
   * 
   * Use these values to manipulate the RCC_CIR register.
   */
  enum class RCC_CIR : std::uint32_t
  {
    LSIRDYF    = 1u << 0,   // LSI ready interrupt flag
    LSERDYF    = 1u << 1,   // LSE ready interrupt flag
    HSIRDYF    = 1u << 2,   // HSI ready interrupt flag
    HSERDYF    = 1u << 3,   // HSE ready interrupt flag
    PLLRDYF    = 1u << 4,   // Main PLL ready interrupt flag
    PLLI2SRDYF = 1u << 5,   // PLLI2S ready interrupt flag
    PLLSAIRDYF = 1u << 6,   // PLLSAI ready interrupt flag
    CSSF       = 1u << 7,   // Clock security system interrupt flag
    LSIRDYIE   = 1u << 8,   // LSI ready interrupt enable
    LSERDYIE   = 1u << 9,   // LSE ready interrupt enable
    HSIRDYIE   = 1u << 10,  // HSI ready interrupt enable
    HSERDYIE   = 1u << 11,  // HSE ready interrupt enable
    PLLRDYIE   = 1u << 12,  // Main PLL ready interrupt enable
    PLLI2SRDYIE= 1u << 13,  // PLLI2S ready interrupt enable
    PLLSAIRDYIE= 1u << 14,  // PLLSAI ready interrupt enable
    LSIRDYC    = 1u << 16,  // Clear LSI ready interrupt flag
    LSERDYC    = 1u << 17,  // Clear LSE ready interrupt flag
    HSIRDYC    = 1u << 18,  // Clear HSI ready interrupt flag
    HSERDYC    = 1u << 19,  // Clear HSE ready interrupt flag
    PLLRDYC    = 1u << 20,  // Clear Main PLL ready interrupt flag
    PLLI2SRDYC = 1u << 21,  // Clear PLLI2S ready interrupt flag
    PLLSAIRDYC = 1u << 22,  // Clear PLLSAI ready interrupt flag
    CSSC       = 1u << 23,  // Clear clock security system interrupt flag
  };

  /**
   * @brief RCC AHB1 peripheral reset register bits.
   * 
   * Use these values to manipulate the RCC_AHB1RSTR register.
   */
  enum class RCC_AHB1RSTR : std::uint32_t
  {
    GPIOARST   = 1u << 0,   // GPIOA reset
    GPIOBRST   = 1u << 1,   // GPIOB reset
    GPIOCRST   = 1u << 2,   // GPIOC reset
    GPIODRST   = 1u << 3,   // GPIOD reset
    GPIOERST   = 1u << 4,   // GPIOE reset
    GPIOFRST   = 1u << 5,   // GPIOF reset
    GPIOGRST   = 1u << 6,   // GPIOG reset
    GPIOHRST   = 1u << 7,   // GPIOH reset
    GPIOIRST   = 1u << 8,   // GPIOI reset
    GPIOJRST   = 1u << 9,   // GPIOJ reset
    GPIOKRST   = 1u << 10,  // GPIOK reset
    CRCRST     = 1u << 12,  // CRC reset
    DMA1RST    = 1u << 21,  // DMA1 reset
    DMA2RST    = 1u << 22,  // DMA2 reset
    DMA2DRST   = 1u << 23,  // DMA2D reset
    ETHMACRST  = 1u << 25,  // Ethernet MAC reset
    OTGHSRST   = 1u << 29,  // USB OTG HS reset
  };
  
  /**
   * @brief RCC AHB2 peripheral reset register bits.
   * 
   * Use these values to manipulate the RCC_AHB2RSTR register.
   */
  enum class RCC_AHB2RSTR : std::uint32_t
  {
    DCMIRST    = 1u << 0,   // DCMI reset
    CRYPRST    = 1u << 4,   // Cryptographic processor reset
    HASHRST    = 1u << 5,   // Hash processor reset
    RNGRST     = 1u << 6,   // Random number generator reset
    OTGFSRST   = 1u << 7,   // USB OTG FS reset
  };
  
  /**
   * @brief RCC AHB3 peripheral reset register bits.
   * 
   * Use these values to manipulate the RCC_AHB3RSTR register.
   */
  enum class RCC_AHB3RSTR : std::uint32_t
  {
    FMCRST     = 1u << 0,   // Flexible memory controller reset
    QSPIRST    = 1u << 1,   // Quad-SPI interface reset
  };

  /**
   * @brief RCC APB1 peripheral reset register bits.
   * 
   * Use these values to manipulate the RCC_APB1RSTR register.
   */
  enum class RCC_APB1RSTR : std::uint32_t
  {
    TIM2RST      = 1u << 0,   // TIM2 reset
    TIM3RST      = 1u << 1,   // TIM3 reset
    TIM4RST      = 1u << 2,   // TIM4 reset
    TIM5RST      = 1u << 3,   // TIM5 reset
    TIM6RST      = 1u << 4,   // TIM6 reset
    TIM7RST      = 1u << 5,   // TIM7 reset
    TIM12RST     = 1u << 6,   // TIM12 reset
    TIM13RST     = 1u << 7,   // TIM13 reset
    TIM14RST     = 1u << 8,   // TIM14 reset
    WWDGRST      = 1u << 11,  // Window watchdog reset
    SPI2RST      = 1u << 14,  // SPI2 reset
    SPI3RST      = 1u << 15,  // SPI3 reset
    SPDIFRXRST   = 1u << 16,  // SPDIF-RX reset
    USART2RST    = 1u << 17,  // USART2 reset
    USART3RST    = 1u << 18,  // USART3 reset
    UART4RST     = 1u << 19,  // UART4 reset
    UART5RST     = 1u << 20,  // UART5 reset
    I2C1RST      = 1u << 21,  // I2C1 reset
    I2C2RST      = 1u << 22,  // I2C2 reset
    I2C3RST      = 1u << 23,  // I2C3 reset
    FMPI2C1RST   = 1u << 24,  // FMPI2C1 reset
    CAN1RST      = 1u << 25,  // CAN1 reset
    CAN2RST      = 1u << 26,  // CAN2 reset
    CECRST       = 1u << 27,  // HDMI-CEC reset
    PWRRST       = 1u << 28,  // Power interface reset
    DACRST       = 1u << 29,  // DAC reset
    UART7RST     = 1u << 30,  // UART7 reset
    UART8RST     = 1u << 31,  // UART8 reset
  };

  /**
   * @brief RCC APB2 peripheral reset register bits.
   * 
   * Use these values to manipulate the RCC_APB2RSTR register.
   */
  enum class RCC_APB2RSTR : std::uint32_t
  {
    TIM1RST      = 1u << 0,   // TIM1 reset
    TIM8RST      = 1u << 1,   // TIM8 reset
    USART1RST    = 1u << 4,   // USART1 reset
    USART6RST    = 1u << 5,   // USART6 reset
    ADCRST       = 1u << 8,   // ADC reset
    SDMMCRST     = 1u << 11,  // SDMMC reset
    SPI1RST      = 1u << 12,  // SPI1 reset
    SPI4RST      = 1u << 13,  // SPI4 reset
    SYSCFGRST    = 1u << 14,  // System configuration controller reset
    TIM9RST      = 1u << 16,  // TIM9 reset
    TIM10RST     = 1u << 17,  // TIM10 reset
    TIM11RST     = 1u << 18,  // TIM11 reset
    SPI5RST      = 1u << 20,  // SPI5 reset
    SPI6RST      = 1u << 21,  // SPI6 reset
    SAI1RST      = 1u << 22,  // SAI1 reset
    LTDCRST      = 1u << 26,  // LCD-TFT controller reset
  };
  
  /**
   * @brief RCC AHB1 peripheral clock enable register bits.
   * 
   * Use these values to manipulate the RCC_AHB1ENR register.
   */
  enum class RCC_AHB1ENR : std::uint32_t
  {
    GPIOAEN      = 1u << 0,   // GPIOA clock enable
    GPIOBEN      = 1u << 1,   // GPIOB clock enable
    GPIOCEN      = 1u << 2,   // GPIOC clock enable
    GPIODEN      = 1u << 3,   // GPIOD clock enable
    GPIOEEN      = 1u << 4,   // GPIOE clock enable
    GPIOFEN      = 1u << 5,   // GPIOF clock enable
    GPIOGEN      = 1u << 6,   // GPIOG clock enable
    GPIOHEN      = 1u << 7,   // GPIOH clock enable
    GPIOIEN      = 1u << 8,   // GPIOI clock enable
    GPIOJEN      = 1u << 9,   // GPIOJ clock enable
    GPIOKEN      = 1u << 10,  // GPIOK clock enable
    CRCEN        = 1u << 12,  // CRC clock enable
    BKPSRAMEN    = 1u << 18,  // Backup SRAM clock enable
    DMA1EN       = 1u << 21,  // DMA1 clock enable
    DMA2EN       = 1u << 22,  // DMA2 clock enable
    DMA2DEN      = 1u << 23,  // DMA2D clock enable
    ETHMACEN     = 1u << 25,  // Ethernet MAC clock enable
    ETHMACTXEN   = 1u << 26,  // Ethernet MAC transmit clock enable
    ETHMACRXEN   = 1u << 27,  // Ethernet MAC receive clock enable
    ETHMACPTPEN  = 1u << 28,  // Ethernet MAC PTP clock enable
    OTGHSEN      = 1u << 29,  // USB OTG HS clock enable
    OTGHSULPIEN  = 1u << 30,  // USB OTG HS ULPI clock enable
  };

  /**
   * @brief RCC AHB2 peripheral clock enable register bits.
   * 
   * Use these values to manipulate the RCC_AHB2ENR register.
   */
  enum class RCC_AHB2ENR : std::uint32_t
  {
    DCMIEN       = 1u << 0,   // DCMI clock enable
    CRYPEN       = 1u << 4,   // Cryptographic processor clock enable
    HASHEN       = 1u << 5,   // Hash processor clock enable
    RNGEN        = 1u << 6,   // Random number generator clock enable
    OTGFSEN      = 1u << 7,   // USB OTG FS clock enable
  };
  
  /**
   * @brief RCC AHB3 peripheral clock enable register bits.
   * 
   * Use these values to manipulate the RCC_AHB3ENR register.
   */
  enum class RCC_AHB3ENR : std::uint32_t
  {
    FMCEN        = 1u << 0,   // Flexible memory controller clock enable
    QSPIEN       = 1u << 1,   // Quad-SPI interface clock enable
  };

  /**
   * @brief RCC AHB1 peripheral clock enable in Sleep mode register bits.
   * 
   * Use these values to manipulate the RCC_AHB1LPENR register.
   */
  enum class RCC_APB1ENR : std::uint32_t
  {
    TIM2EN      = 1u << 0,   // TIM2 clock enable
    TIM3EN      = 1u << 1,   // TIM3 clock enable
    TIM4EN      = 1u << 2,   // TIM4 clock enable
    TIM5EN      = 1u << 3,   // TIM5 clock enable
    TIM6EN      = 1u << 4,   // TIM6 clock enable
    TIM7EN      = 1u << 5,   // TIM7 clock enable
    TIM12EN     = 1u << 6,   // TIM12 clock enable
    TIM13EN     = 1u << 7,   // TIM13 clock enable
    TIM14EN     = 1u << 8,   // TIM14 clock enable
    WWDGEN      = 1u << 11,  // Window watchdog clock enable
    SPI2EN      = 1u << 14,  // SPI2 clock enable
    SPI3EN      = 1u << 15,  // SPI3 clock enable
    SPDIFRXEN   = 1u << 16,  // SPDIF-RX clock enable
    USART2EN    = 1u << 17,  // USART2 clock enable
    USART3EN    = 1u << 18,  // USART3 clock enable
    UART4EN     = 1u << 19,  // UART4 clock enable
    UART5EN     = 1u << 20,  // UART5 clock enable
    I2C1EN      = 1u << 21,  // I2C1 clock enable
    I2C2EN      = 1u << 22,  // I2C2 clock enable
    I2C3EN      = 1u << 23,  // I2C3 clock enable
    FMPI2C1EN   = 1u << 24,  // FMPI2C1 clock enable
    CAN1EN      = 1u << 25,  // CAN1 clock enable
    CAN2EN      = 1u << 26,  // CAN2 clock enable
    CECEN       = 1u << 27,  // HDMI-CEC clock enable
    PWREN       = 1u << 28,  // Power interface clock enable
    DACEN       = 1u << 29,  // DAC clock enable
    UART7EN     = 1u << 30,  // UART7 clock enable
    UART8EN     = 1u << 31,  // UART8 clock enable
  };

  /**
   * @brief RCC APB2 peripheral clock enable register bits.
   * 
   * Use these values to manipulate the RCC_APB2ENR register.
   */
  enum class RCC_APB2ENR : std::uint32_t
  {
    TIM1EN      = 1u << 0,   // TIM1 clock enable
    TIM8EN      = 1u << 1,   // TIM8 clock enable
    USART1EN    = 1u << 4,   // USART1 clock enable
    USART6EN    = 1u << 5,   // USART6 clock enable
    ADC1EN      = 1u << 8,   // ADC1 clock enable
    ADC2EN      = 1u << 9,   // ADC2 clock enable
    ADC3EN      = 1u << 10,  // ADC3 clock enable
    SDMMCEN     = 1u << 11,  // SDMMC clock enable
    SPI1EN      = 1u << 12,  // SPI1 clock enable
    SPI4EN      = 1u << 13,  // SPI4 clock enable
    SYSCFGEN    = 1u << 14,  // System configuration controller clock enable
    TIM9EN      = 1u << 16,  // TIM9 clock enable
    TIM10EN     = 1u << 17,  // TIM10 clock enable
    TIM11EN     = 1u << 18,  // TIM11 clock enable
    SPI5EN      = 1u << 20,  // SPI5 clock enable
    SPI6EN      = 1u << 21,  // SPI6 clock enable
    SAI1EN      = 1u << 22,  // SAI1 clock enable
    LTDCEN      = 1u << 26,  // LCD-TFT controller clock enable
  };

  /**
   * @brief RCC AHB1 peripheral clock enable in Sleep mode register bits.
   * 
   * Use these values to manipulate the RCC_AHB1LPENR register.
   */
  enum class RCC_AHB1LPENR : std::uint32_t
  {
    GPIOALPEN   = 1u << 0,   // GPIOA clock enable during Sleep mode
    GPIOBLPEN   = 1u << 1,   // GPIOB clock enable during Sleep mode
    GPIOCLPEN   = 1u << 2,   // GPIOC clock enable during Sleep mode
    GPIODLPEN   = 1u << 3,   // GPIOD clock enable during Sleep mode
    GPIOELPEN   = 1u << 4,   // GPIOE clock enable during Sleep mode
    GPIOFLPEN   = 1u << 5,   // GPIOF clock enable during Sleep mode
    GPIOGLPEN   = 1u << 6,   // GPIOG clock enable during Sleep mode
    GPIOHLPEN   = 1u << 7,   // GPIOH clock enable during Sleep mode
    GPIOILPEN   = 1u << 8,   // GPIOI clock enable during Sleep mode
    GPIOJLPEN   = 1u << 9,   // GPIOJ clock enable during Sleep mode
    GPIOKLPEN   = 1u << 10,  // GPIOK clock enable during Sleep mode
    CRCLPEN     = 1u << 12,  // CRC clock enable during Sleep mode
    FLITFLPEN   = 1u << 15,  // Flash interface clock enable during Sleep mode
    SRAM1LPEN   = 1u << 16,  // SRAM1 interface clock enable during Sleep mode
    SRAM2LPEN   = 1u << 17,  // SRAM2 interface clock enable during Sleep mode
    BKPSRAMLPEN = 1u << 18,  // Backup SRAM clock enable during Sleep mode
    DMA1LPEN    = 1u << 21,  // DMA1 clock enable during Sleep mode
    DMA2LPEN    = 1u << 22,  // DMA2 clock enable during Sleep mode
    DMA2DLPEN   = 1u << 23,  // DMA2D clock enable during Sleep mode
    ETHMACLPEN  = 1u << 25,  // Ethernet MAC clock enable during Sleep mode
    OTGHSLPEN   = 1u << 29,  // USB OTG HS clock enable during Sleep mode
    OTGHSULPILPEN = 1u << 30, // USB OTG HS ULPI clock enable during Sleep mode
  };

  /**
   * @brief RCC AHB2 peripheral clock enable in Sleep mode register bits.
   * 
   * Use these values to manipulate the RCC_AHB2LPENR register.
   */
  enum class RCC_AHB2LPENR : std::uint32_t
  {
    DCMILPEN    = 1u << 0,   // DCMI clock enable during Sleep mode
    CRYPLPEN    = 1u << 4,   // Cryptographic processor clock enable during Sleep mode
    HASHLPEN    = 1u << 5,   // Hash processor clock enable during Sleep mode
    RNGLPEN     = 1u << 6,   // Random number generator clock enable during Sleep mode
    OTGFSLPEN   = 1u << 7,   // USB OTG FS clock enable during Sleep mode
  };
  
  /**
   * @brief RCC AHB3 peripheral clock enable in Sleep mode register bits.
   * 
   * Use these values to manipulate the RCC_AHB3LPENR register.
   */
  enum class RCC_AHB3LPENR : std::uint32_t
  {
    FMCLPEN     = 1u << 0,   // Flexible memory controller clock enable during Sleep mode
    QSPILPEN    = 1u << 1,   // Quad-SPI clock enable during Sleep mode
  };
  
  /**
   * @brief RCC APB1 peripheral clock enable in Sleep mode register bits.
   * 
   * Use these values to manipulate the RCC_APB1LPENR register.
   */
  enum class RCC_APB1LPENR : std::uint32_t
  {
    TIM2LPEN      = 1u << 0,   // TIM2 clock enable during Sleep mode
    TIM3LPEN      = 1u << 1,   // TIM3 clock enable during Sleep mode
    TIM4LPEN      = 1u << 2,   // TIM4 clock enable during Sleep mode
    TIM5LPEN      = 1u << 3,   // TIM5 clock enable during Sleep mode
    TIM6LPEN      = 1u << 4,   // TIM6 clock enable during Sleep mode
    TIM7LPEN      = 1u << 5,   // TIM7 clock enable during Sleep mode
    TIM12LPEN     = 1u << 6,   // TIM12 clock enable during Sleep mode
    TIM13LPEN     = 1u << 7,   // TIM13 clock enable during Sleep mode
    TIM14LPEN     = 1u << 8,   // TIM14 clock enable during Sleep mode
    WWDGLPEN      = 1u << 11,  // Window watchdog clock enable during Sleep mode
    SPI2LPEN      = 1u << 14,  // SPI2 clock enable during Sleep mode
    SPI3LPEN      = 1u << 15,  // SPI3 clock enable during Sleep mode
    SPDIFRXLPEN   = 1u << 16,  // SPDIF-RX clock enable during Sleep mode
    USART2LPEN    = 1u << 17,  // USART2 clock enable during Sleep mode
    USART3LPEN    = 1u << 18,  // USART3 clock enable during Sleep mode
    UART4LPEN     = 1u << 19,  // UART4 clock enable during Sleep mode
    UART5LPEN     = 1u << 20,  // UART5 clock enable during Sleep mode
    I2C1LPEN      = 1u << 21,  // I2C1 clock enable during Sleep mode
    I2C2LPEN      = 1u << 22,  // I2C2 clock enable during Sleep mode
    I2C3LPEN      = 1u << 23,  // I2C3 clock enable during Sleep mode
    FMPI2C1LPEN   = 1u << 24,  // FMPI2C1 clock enable during Sleep mode
    CAN1LPEN      = 1u << 25,  // CAN1 clock enable during Sleep mode
    CAN2LPEN      = 1u << 26,  // CAN2 clock enable during Sleep mode
    CECLPEN       = 1u << 27,  // HDMI-CEC clock enable during Sleep mode
    PWRLPEN       = 1u << 28,  // Power interface clock enable during Sleep mode
    DACLPEN       = 1u << 29,  // DAC clock enable during Sleep mode
    UART7LPEN     = 1u << 30,  // UART7 clock enable during Sleep mode
    UART8LPEN     = 1u << 31,  // UART8 clock enable during Sleep mode
  };
  
  /**
   * @brief RCC APB2 peripheral clock enable in Sleep mode register bits.
   * 
   * Use these values to manipulate the RCC_APB2LPENR register.
   */
  enum class RCC_APB2LPENR : std::uint32_t
  {
    TIM1LPEN      = 1u << 0,   // TIM1 clock enable during Sleep mode
    TIM8LPEN      = 1u << 1,   // TIM8 clock enable during Sleep mode
    USART1LPEN    = 1u << 4,   // USART1 clock enable during Sleep mode
    USART6LPEN    = 1u << 5,   // USART6 clock enable during Sleep mode
    ADC1LPEN      = 1u << 8,   // ADC1 clock enable during Sleep mode
    ADC2LPEN      = 1u << 9,   // ADC2 clock enable during Sleep mode
    ADC3LPEN      = 1u << 10,  // ADC3 clock enable during Sleep mode
    SDMMCLPEN     = 1u << 11,  // SDMMC clock enable during Sleep mode
    SPI1LPEN      = 1u << 12,  // SPI1 clock enable during Sleep mode
    SPI4LPEN      = 1u << 13,  // SPI4 clock enable during Sleep mode
    SYSCFGLPEN    = 1u << 14,  // System configuration controller clock enable during Sleep mode
    TIM9LPEN      = 1u << 16,  // TIM9 clock enable during Sleep mode
    TIM10LPEN     = 1u << 17,  // TIM10 clock enable during Sleep mode
    TIM11LPEN     = 1u << 18,  // TIM11 clock enable during Sleep mode
    SPI5LPEN      = 1u << 20,  // SPI5 clock enable during Sleep mode
    SPI6LPEN      = 1u << 21,  // SPI6 clock enable during Sleep mode
    SAI1LPEN      = 1u << 22,  // SAI1 clock enable during Sleep mode
    LTDCLPEN      = 1u << 26,  // LCD-TFT controller clock enable during Sleep mode
  };
  
  /**
   * @brief RCC backup domain control register bits.
   * 
   * Use these values to manipulate the RCC_BDCR register.
   */
  enum class RCC_BDCR : std::uint32_t
  {
    LSEON        = 1u << 0,   // External low-speed oscillator enable
    LSERDY       = 1u << 1,   // External low-speed oscillator ready flag
    LSEBYP       = 1u << 2,   // External low-speed oscillator bypass
    LSEMOD       = 1u << 3,   // External low-speed oscillator low-drive mode
    RTCSEL0      = 1u << 8,   // RTC clock source selection bit 0
    RTCSEL1      = 1u << 9,   // RTC clock source selection bit 1
    RTCEN        = 1u << 15,  // RTC clock enable
    BDRST        = 1u << 16,  // Backup domain software reset
    RTCSEL2      = 1u << 17,  // RTC clock source selection bit 2
  };
  
  /**
   * @brief RCC clock control and status register bits.
   * 
   * Use these values to manipulate the RCC_CSR register.
   */
  enum class RCC_CSR : std::uint32_t
  {
    LSION        = 1u << 0,   // Internal low-speed oscillator enable
    LSIRDY       = 1u << 1,   // Internal low-speed oscillator ready flag
    RMVF         = 1u << 24,  // Remove reset flag
    BORRSTF      = 1u << 25,  // BOR reset flag
    PINRSTF      = 1u << 26,  // Pin reset flag
    PORRSTF      = 1u << 27,  // POR/PDR reset flag
    SFTRSTF      = 1u << 28,  // Software reset flag
    IWDGRSTF     = 1u << 29,  // Independent watchdog reset flag
    WWDGRSTF     = 1u << 30,  // Window watchdog reset flag
    LPWRRSTF     = 1u << 31,  // Low-power reset flag
  };
  
  /**
   * @brief RCC spread spectrum clock generation register bits.
   * 
   * Use these values to manipulate the RCC_SSCGR register.
   */
  enum class RCC_SSCGR : std::uint32_t
  {
    MODPER0      = 1u << 0,   // Modulation period bit 0
    MODPER1      = 1u << 1,   // Modulation period bit 1
    MODPER2      = 1u << 2,   // Modulation period bit 2
    MODPER3      = 1u << 3,   // Modulation period bit 3
    MODPER4      = 1u << 4,   // Modulation period bit 4
    MODPER5      = 1u << 5,   // Modulation period bit 5
    INCSTEP0     = 1u << 13,  // Increment step bit 0
    INCSTEP1     = 1u << 14,  // Increment step bit 1
    INCSTEP2     = 1u << 15,  // Increment step bit 2
    INCSTEP3     = 1u << 16,  // Increment step bit 3
    INCSTEP4     = 1u << 17,  // Increment step bit 4
    INCSTEP5     = 1u << 18,  // Increment step bit 5
    INCSTEP6     = 1u << 19,  // Increment step bit 6
    SPREADSEL    = 1u << 30,  // Spread select
    SSCGEN       = 1u << 31,  // Spread spectrum modulation enable
  };
  
  /**
   * @brief RCC PLLI2S configuration register bits.
   * 
   * Use these values to manipulate the RCC_PLLI2SCFGR register.
   */
  enum class RCC_PLLI2SCFGR : std::uint32_t
  {
    PLLI2SN0     = 1u << 6,   // PLLI2S multiplication factor bit 0
    PLLI2SN1     = 1u << 7,   // PLLI2S multiplication factor bit 1
    PLLI2SN2     = 1u << 8,   // PLLI2S multiplication factor bit 2
    PLLI2SN3     = 1u << 9,   // PLLI2S multiplication factor bit 3
    PLLI2SN4     = 1u << 10,  // PLLI2S multiplication factor bit 4
    PLLI2SN5     = 1u << 11,  // PLLI2S multiplication factor bit 5
    PLLI2SN6     = 1u << 12,  // PLLI2S multiplication factor bit 6
    PLLI2SN7     = 1u << 13,  // PLLI2S multiplication factor bit 7
    PLLI2SN8     = 1u << 14,  // PLLI2S multiplication factor bit 8
    PLLI2SR0     = 1u << 28,  // PLLI2S division factor for I2S clocks bit 0
    PLLI2SR1     = 1u << 29,  // PLLI2S division factor for I2S clocks bit 1
    PLLI2SR2     = 1u << 30,  // PLLI2S division factor for I2S clocks bit 2
    PLLI2SR3     = 1u << 31,  // PLLI2S division factor for I2S clocks bit 3
  };

  /**
   * @brief RCC PLLSAI configuration register bits.
   * 
   * Use these values to manipulate the RCC_PLLSAICFGR register.
   */
  enum class RCC_PLLSAICFGR : std::uint32_t
  {
    PLLSAIN0     = 1u << 6,   // PLLSAI multiplication factor bit 0
    PLLSAIN1     = 1u << 7,   // PLLSAI multiplication factor bit 1
    PLLSAIN2     = 1u << 8,   // PLLSAI multiplication factor bit 2
    PLLSAIN3     = 1u << 9,   // PLLSAI multiplication factor bit 3
    PLLSAIN4     = 1u << 10,  // PLLSAI multiplication factor bit 4
    PLLSAIN5     = 1u << 11,  // PLLSAI multiplication factor bit 5
    PLLSAIN6     = 1u << 12,  // PLLSAI multiplication factor bit 6
    PLLSAIN7     = 1u << 13,  // PLLSAI multiplication factor bit 7
    PLLSAIN8     = 1u << 14,  // PLLSAI multiplication factor bit 8
    PLLSAIP0     = 1u << 16,  // PLLSAI division factor for LCD-TFT clock bit 0
    PLLSAIP1     = 1u << 17,  // PLLSAI division factor for LCD-TFT clock bit 1
    PLLSAIQ0     = 1u << 24,  // PLLSAI division factor for SAI clocks bit 0
    PLLSAIQ1     = 1u << 25,  // PLLSAI division factor for SAI clocks bit 1
    PLLSAIQ2     = 1u << 26,  // PLLSAI division factor for SAI clocks bit 2
    PLLSAIQ3     = 1u << 27,  // PLLSAI division factor for SAI clocks bit 3
    PLLSAIR0     = 1u << 28,  // PLLSAI division factor for LCD-TFT and SAI clocks bit 0
    PLLSAIR1     = 1u << 29,  // PLLSAI division factor for LCD-TFT and SAI clocks bit 1
    PLLSAIR2     = 1u << 30,  // PLLSAI division factor for LCD-TFT and SAI clocks bit 2
    PLLSAIR3     = 1u << 31,  // PLLSAI division factor for LCD-TFT and SAI clocks bit 3
  };
  
  /**
   * @brief RCC dedicated clocks configuration register 1 bits.
   * 
   * Use these values to manipulate the RCC_DCKCFGR1 register.
   */
  enum class RCC_DCKCFGR1 : std::uint32_t
  {
    PLLI2SDIVQ0  = 1u << 0,   // PLLI2S division factor for SAI1 clock bit 0
    PLLI2SDIVQ1  = 1u << 1,   // PLLI2S division factor for SAI1 clock bit 1
    PLLI2SDIVQ2  = 1u << 2,   // PLLI2S division factor for SAI1 clock bit 2
    PLLI2SDIVQ3  = 1u << 3,   // PLLI2S division factor for SAI1 clock bit 3
    PLLI2SDIVQ4  = 1u << 4,   // PLLI2S division factor for SAI1 clock bit 4
    PLLI2SDIVQ5  = 1u << 5,   // PLLI2S division factor for SAI1 clock bit 5
    PLLI2SDIVQ6  = 1u << 6,   // PLLI2S division factor for SAI1 clock bit 6
    PLLI2SDIVQ7  = 1u << 7,   // PLLI2S division factor for SAI1 clock bit 7
    PLLSAIDIVQ0  = 1u << 8,   // PLLSAI division factor for SAI2 clock bit 0
    PLLSAIDIVQ1  = 1u << 9,   // PLLSAI division factor for SAI2 clock bit 1
    PLLSAIDIVQ2  = 1u << 10,  // PLLSAI division factor for SAI2 clock bit 2
    PLLSAIDIVQ3  = 1u << 11,  // PLLSAI division factor for SAI2 clock bit 3
    PLLSAIDIVQ4  = 1u << 12,  // PLLSAI division factor for SAI2 clock bit 4
    PLLSAIDIVQ5  = 1u << 13,  // PLLSAI division factor for SAI2 clock bit 5
    PLLSAIDIVQ6  = 1u << 14,  // PLLSAI division factor for SAI2 clock bit 6
    PLLSAIDIVQ7  = 1u << 15,  // PLLSAI division factor for SAI2 clock bit 7
    PLLSAIDIVR0  = 1u << 16,  // PLLSAI division factor for LCD-TFT clock bit 0
    PLLSAIDIVR1  = 1u << 17,  // PLLSAI division factor for LCD-TFT clock bit 1
    SAI1SEL0     = 1u << 20,  // SAI1 clock source selection bit 0
    SAI1SEL1     = 1u << 21,  // SAI1 clock source selection bit 1
    SAI2SEL0     = 1u << 22,  // SAI2 clock source selection bit 0
    SAI2SEL1     = 1u << 23,  // SAI2 clock source selection bit 1
    TIMPRE       = 1u << 24,  // Timers clock prescaler selection
    DFSDM1SEL    = 1u << 30,  // DFSDM1 kernel clock selection
  };
  
  /**
   * @brief RCC dedicated clocks configuration register 2 bits.
   * 
   * Use these values to manipulate the RCC_DCKCFGR2 register.
   */
  enum class RCC_DCKCFGR2 : std::uint32_t
  {
    USART1SEL0   = 1u << 0,   // USART1 clock source selection bit 0
    USART1SEL1   = 1u << 1,   // USART1 clock source selection bit 1
    USART2SEL0   = 1u << 2,   // USART2 clock source selection bit 0
    USART2SEL1   = 1u << 3,   // USART2 clock source selection bit 1
    USART3SEL0   = 1u << 4,   // USART3 clock source selection bit 0
    USART3SEL1   = 1u << 5,   // USART3 clock source selection bit 1
    UART4SEL0    = 1u << 6,   // UART4 clock source selection bit 0
    UART4SEL1    = 1u << 7,   // UART4 clock source selection bit 1
    UART5SEL0    = 1u << 8,   // UART5 clock source selection bit 0
    UART5SEL1    = 1u << 9,   // UART5 clock source selection bit 1
    I2C1SEL0     = 1u << 12,  // I2C1 clock source selection bit 0
    I2C1SEL1     = 1u << 13,  // I2C1 clock source selection bit 1
    I2C2SEL0     = 1u << 14,  // I2C2 clock source selection bit 0
    I2C2SEL1     = 1u << 15,  // I2C2 clock source selection bit 1
    I2C3SEL0     = 1u << 16,  // I2C3 clock source selection bit 0
    I2C3SEL1     = 1u << 17,  // I2C3 clock source selection bit 1
    CECSEL       = 1u << 26,  // HDMI-CEC clock source selection
    CK48MSEL     = 1u << 27,  // 48 MHz clock source selection
    SDMMCSEL     = 1u << 28,  // SDMMC clock source selection
    SPDIFRXSEL0  = 1u << 29,  // SPDIF-RX clock source selection bit 0
    SPDIFRXSEL1  = 1u << 30,  // SPDIF-RX clock source selection bit 1
  };
  
}
  