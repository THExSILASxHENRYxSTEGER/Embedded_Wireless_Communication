/**
 * @file rcc.hpp
 * @brief Instantiate a class that can manipulate the RCC registers.
 */
#pragma once

#include "addresses/addresses.hpp"
#include <rcc/rcc_bits.hpp>
#include <rcc/rcc_regs.hpp>

#include <cstdint>

namespace rcc
{
  /**
   * @class RCC
   * @brief Provides functionality for manipulation of the RCC registers.
   *
   * This class wraps the RCC registers around functionality to change their register values.
   */
  class RCC
  {

    public:
      
      /**
       * @brief Constructs an RCC object.
       *
       * @param port_address Physical hardware base address of the RCC peripheral.
       */
      RCC(const std::uint32_t rcc_address);

      /**
       * @brief Enables the clock for a peripheral.
       *
       * @tparam P An RCC peripheral clock enable enumeration type (e.g. RCC_AHB1ENR, RCC_APB2ENR).
       * @param peripheral Peripheral whose clock should be enabled.
       * 
       * Sets the corresponding clock enable bit in the appropriate RCC peripheral clock enable register.
       */
      template<typename P>
      requires (
        std::same_as<P, RCC_AHB1ENR> || 
        std::same_as<P, RCC_AHB2ENR> || 
        std::same_as<P, RCC_AHB3ENR> ||
        std::same_as<P, RCC_APB1ENR> ||
        std::same_as<P, RCC_APB2ENR>
      )
      void peripheral_clk_enable(P peripheral);

      /**
       * @brief Default destruction of the RCC object.
       */
      ~RCC() = default;
    
    private:
        
      /** RCC registers. */
      volatile RCC_REGS* rcc_regs_;
  };

  /** RCC peripheral instance. */
  inline RCC rcc(addresses::RCC);

}

#include "./../src/rcc/rcc.tpp"