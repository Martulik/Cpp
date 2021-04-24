#include "string-convert.hpp"

boost::optional< unsigned long > shilyaev::toNatural(const std::string &string)
{
  if (string.empty()) {
    return {};
  }
  unsigned long result = 0;
  for (std::string::const_iterator i = string.cbegin(); i < string.cend(); i++) {
    result *= 10;
    if (!isdigit(*i)) {
      return {};
    }
    result += *i - '0';
  }
  return {result};
}
