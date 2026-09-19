#pragma once

#include "global/global_vars.hpp"

#include <array>
#include <cstdint>

namespace input_buffer
{
  /**
   * @brief Fixed size input buffer to store bytes from peripherals temporarily.
   * 
   * Abstraction over a regular array.
   * 
   * @tparam max_input_len Total length the buffer can carry.
   */
  template <std::uint32_t max_input_len>
  class INPUT_BUFFER
  {
    public:
      INPUT_BUFFER() = default;
      ~INPUT_BUFFER() = default;

      /**
       * @brief Push a byte at the back of the input buffer.
       * 
       * @param c The byte to be pushed into the buffer.
       */
      void push_back(char c);

      /**
       * @brief Return a byte in the buffer with standard array corner bracket notation.
       * 
       * @param index The index of the byte to be accessed.
       * @return char The byte to be accessed.
       */
      char operator[](std::uint32_t index) const;
  
      /**
       * @brief Query the length of the input buffer.
       * 
       * @return std::uint32_t The length of the buffer.
       */
      std::uint32_t size();
      
      /**
       * @brief Qquery if a peripheral has written data into the buffer.
       * 
       * @return true The buffer is not empty, i.e. a peripheral has stored data into it.
       * @return false The buffer is empty, no data to be processed is avialbale.
       */
      bool answered();
      
      /**
       * @brief Empty the buffer.
       */
      void clear();

      /**
       * @brief Fill the buffer with a fixed byte stream.
       * 
       * This function is mostly for debugging puroposes.
       * 
       * @param str The string to fill the buffer with.
       */
      void fill(const char* str);
    
    private:
  
      /** The actual std array this class abstracts over */
      std::array<char, max_input_len> input_;
  
      /** The legnth of the buffer */
      std::uint32_t len_ = 0;
  };
  
  /** A fixed global instance of the input buffer for peripherals to wirte to and read from */
  inline INPUT_BUFFER<global_vars::MAX_INPUT_LEN> ib;

}

#include "./../src/input_buffer/input_buffer.tpp"