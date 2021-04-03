#include "ArgumentParseException.hpp"

ArgumentParseException::ArgumentParseException(std::string msg):
  message_(std::move(msg))
{}

const char* ArgumentParseException::what() const noexcept
{
  return message_.c_str();
}
