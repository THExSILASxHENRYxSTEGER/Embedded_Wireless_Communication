#include "input_buffer/input_buffer.hpp"
#include "usart/usart.hpp"

namespace input_buffer
{

  template <std::uint32_t max_input_len>
  void INPUT_BUFFER<max_input_len>::print(usart::USART& usart)
  {
    // Iterate over the buffer and send chars into USART/UART transmit FIFO buffer.
    for (std::uint32_t i = 0; i < len_; i++)
      usart.send(input_[i]);
  }

  // Explicit instantiation of the class type
  template class INPUT_BUFFER<global_vars::MAX_INPUT_LEN>;

}