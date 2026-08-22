#include "input_buffer/input_buffer.hpp"

namespace input_buffer
{
  template <std::uint32_t max_input_len>
  void INPUT_BUFFER<max_input_len>::push_back(char c)
  {
    // Do not push chars into a full buffer
    if (len_ >= input_.size()) return;
    input_[len_] = c;
    len_ += 1;
  }

  template <std::uint32_t max_input_len>
  char INPUT_BUFFER<max_input_len>::operator[](std::uint32_t index) const
  {
    if (index <= len_) return input_[index];
    return '\0';
  }

  template <std::uint32_t max_input_len>
  std::uint32_t INPUT_BUFFER<max_input_len>::size()
  {
    return len_;
  }

  template <std::uint32_t max_input_len>
  bool INPUT_BUFFER<max_input_len>::answered()
  {
    return len_ > 0;
  }

  template <std::uint32_t max_input_len>
  void INPUT_BUFFER<max_input_len>::clear()
  {
    input_.fill(0);
    len_ = 0;
  }

}