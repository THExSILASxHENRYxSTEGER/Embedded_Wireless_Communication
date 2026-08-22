#pragma once

#include <cstdint>

namespace nvic{

  /**
   * @brief These numbers apply to all registers ISER until IABR
   * 
   * Choose a register entry in any of the registers enumerated 
   * in the brief section with one of the niumber below.
   */
  enum class IRQn : std::uint32_t
  {
    WWDG               = 0,  // Window watchdog interrupt
    PVD                = 1,  // PVD through EXTI line detection interrupt
    TAMP_STAMP         = 2,  // Tamper and timestamp interrupt
    RTC_WKUP           = 3,  // RTC wake-up interrupt
    FLASH              = 4,  // Flash global interrupt
    RCC                = 5,  // RCC global interrupt
    EXTI0              = 6,  // EXTI line 0 interrupt
    EXTI1              = 7,  // EXTI line 1 interrupt
    EXTI2              = 8,  // EXTI line 2 interrupt
    EXTI3              = 9,  // EXTI line 3 interrupt
    EXTI4              = 10, // EXTI line 4 interrupt
    DMA1_Stream0       = 11, // DMA1 stream 0 interrupt
    DMA1_Stream1       = 12, // DMA1 stream 1 interrupt
    DMA1_Stream2       = 13, // DMA1 stream 2 interrupt
    DMA1_Stream3       = 14, // DMA1 stream 3 interrupt
    DMA1_Stream4       = 15, // DMA1 stream 4 interrupt
    DMA1_Stream5       = 16, // DMA1 stream 5 interrupt
    DMA1_Stream6       = 17, // DMA1 stream 6 interrupt
    ADC                = 18, // ADC global interrupt
    CAN1_TX            = 19, // CAN1 TX interrupt
    CAN1_RX0           = 20, // CAN1 RX0 interrupt
    CAN1_RX1           = 21, // CAN1 RX1 interrupt
    CAN1_SCE           = 22, // CAN1 SCE interrupt
    EXTI9_5            = 23, // EXTI lines 5 to 9 interrupt
    TIM1_BRK_TIM9      = 24, // TIM1 break and TIM9 global interrupt
    TIM1_UP_TIM10      = 25, // TIM1 update and TIM10 global interrupt
    TIM1_TRG_COM_TIM11 = 26, // TIM1 trigger/commutation and TIM11 global interrupt
    TIM1_CC            = 27, // TIM1 capture compare interrupt
    TIM2               = 28, // TIM2 global interrupt
    TIM3               = 29, // TIM3 global interrupt
    TIM4               = 30, // TIM4 global interrupt
    I2C1_EV            = 31, // I2C1 event interrupt
    I2C1_ER            = 32, // I2C1 error interrupt
    I2C2_EV            = 33, // I2C2 event interrupt
    I2C2_ER            = 34, // I2C2 error interrupt
    SPI1               = 35, // SPI1 global interrupt
    SPI2               = 36, // SPI2 global interrupt
    USART1             = 37, // USART1 global interrupt
    USART2             = 38, // USART2 global interrupt
    USART3             = 39, // USART3 global interrupt
    EXTI15_10          = 40, // EXTI lines 10 to 15 interrupt
    RTC_ALARM          = 41, // RTC alarm interrupt
    OTG_FS_WKUP        = 42, // USB OTG FS wake-up interrupt
    TIM8_BRK_TIM12     = 43, // TIM8 break and TIM12 global interrupt
    TIM8_UP_TIM13      = 44, // TIM8 update and TIM13 global interrupt
    TIM8_TRG_COM_TIM14 = 45, // TIM8 trigger/commutation and TIM14 global interrupt
    TIM8_CC            = 46, // TIM8 capture compare interrupt
    DMA1_Stream7       = 47, // DMA1 stream 7 interrupt
    FMC                = 48, // FMC global interrupt
    SDMMC1             = 49, // SDMMC1 global interrupt
    TIM5               = 50, // TIM5 global interrupt
    SPI3               = 51, // SPI3 global interrupt
    UART4              = 52, // UART4 global interrupt
    UART5              = 53, // UART5 global interrupt
    TIM6_DAC           = 54, // TIM6 and DAC global interrupt
    TIM7               = 55, // TIM7 global interrupt
    DMA2_Stream0       = 56, // DMA2 stream 0 interrupt
    DMA2_Stream1       = 57, // DMA2 stream 1 interrupt
    DMA2_Stream2       = 58, // DMA2 stream 2 interrupt
    DMA2_Stream3       = 59, // DMA2 stream 3 interrupt
    DMA2_Stream4       = 60, // DMA2 stream 4 interrupt
    ETH                = 61, // Ethernet global interrupt
    ETH_WKUP           = 62, // Ethernet wake-up interrupt
    CAN2_TX            = 63, // CAN2 TX interrupt
    CAN2_RX0           = 64, // CAN2 RX0 interrupt
    CAN2_RX1           = 65, // CAN2 RX1 interrupt
    CAN2_SCE           = 66, // CAN2 SCE interrupt
    OTG_FS             = 67, // USB OTG FS global interrupt
    DMA2_Stream5       = 68, // DMA2 stream 5 interrupt
    DMA2_Stream6       = 69, // DMA2 stream 6 interrupt
    DMA2_Stream7       = 70, // DMA2 stream 7 interrupt
    USART6             = 71, // USART6 global interrupt
    I2C3_EV            = 72, // I2C3 event interrupt
    I2C3_ER            = 73, // I2C3 error interrupt
    OTG_HS_EP1_OUT     = 74, // USB OTG HS endpoint 1 OUT interrupt
    OTG_HS_EP1_IN      = 75, // USB OTG HS endpoint 1 IN interrupt
    OTG_HS_WKUP        = 76, // USB OTG HS wake-up interrupt
    OTG_HS             = 77, // USB OTG HS global interrupt
    DCMI               = 78, // DCMI global interrupt
    CRYP               = 79, // Cryptographic processor interrupt
    HASH_RNG           = 80, // HASH and RNG global interrupt
    FPU                = 81, // Floating point unit interrupt
    UART7              = 82, // UART7 global interrupt
    UART8              = 83, // UART8 global interrupt
    SPI4               = 84, // SPI4 global interrupt
    SPI5               = 85, // SPI5 global interrupt
    SPI6               = 86, // SPI6 global interrupt
    SAI1               = 87, // SAI1 global interrupt
    LTDC               = 88, // LTDC global interrupt
    LTDC_ER            = 89, // LTDC error interrupt
    DMA2D              = 90, // DMA2D global interrupt
  };

  /**
   * @brief 
   * 
   */
  enum class NVIC_IPR : std::uint32_t
  {
    PRIORITY_0  = 0  << 4,   // Priority level 0
    PRIORITY_1  = 1  << 4,   // Priority level 1
    PRIORITY_2  = 2  << 4,   // Priority level 2
    PRIORITY_3  = 3  << 4,   // Priority level 3
    PRIORITY_4  = 4  << 4,   // Priority level 4
    PRIORITY_5  = 5  << 4,   // Priority level 5
    PRIORITY_6  = 6  << 4,   // Priority level 6
    PRIORITY_7  = 7  << 4,   // Priority level 7
    PRIORITY_8  = 8  << 4,   // Priority level 8
    PRIORITY_9  = 9  << 4,   // Priority level 9
    PRIORITY_10 = 10 << 4,   // Priority level 10
    PRIORITY_11 = 11 << 4,   // Priority level 11
    PRIORITY_12 = 12 << 4,   // Priority level 12
    PRIORITY_13 = 13 << 4,   // Priority level 13
    PRIORITY_14 = 14 << 4,   // Priority level 14
    PRIORITY_15 = 15 << 4,   // Priority level 15
  };
    
}