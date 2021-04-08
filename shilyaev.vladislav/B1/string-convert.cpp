#include "string-convert.hpp"
#include <stdexcept>

unsigned int shilyaev::toNatural(const std::string &string)
{
  if (string.empty()) {
    throw std::invalid_argument("Empty string");
  }
  int result = 0;
  for (std::string::const_iterator i = string.cbegin(); i < string.cend(); i++) {
    result *= 10;
    if (*i < '0' || *i > '9') {
      throw std::invalid_argument("String must only contain digits");
    }
    result += *i - '0';
  }
  return result;
}
