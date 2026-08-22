#pragma once

#include "global/global_vars.hpp"

#include <array>
#include <cstdint>

namespace usart
{
  class USART;
}

namespace input_buffer
{
  
  template <std::uint32_t max_input_len>
  class INPUT_BUFFER
  {
    public:
      INPUT_BUFFER() = default;
      ~INPUT_BUFFER() = default;

      void push_back(char c);

      char operator[](std::uint32_t index) const;
  
      std::uint32_t size();
      
      bool answered();
      
      void print(usart::USART& usart);

      void clear();
    
    private:
  
      std::array<char, max_input_len> input_;
  
      std::uint32_t len_ = 0;
  };
  
  inline INPUT_BUFFER<global_vars::MAX_INPUT_LEN> ib;

}

#include "./../src/input_buffer/input_buffer.tpp"