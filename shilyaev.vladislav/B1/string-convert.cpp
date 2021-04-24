#include "string-convert.hpp"

boost::optional< int > shilyaev::toNatural(const char *string)
{
  if (string[0] == '\0') {
    return {};
  }
  for (size_t i = 0; string[i] != '\0'; i++) {
    if (!isdigit(string[i])) {
      return {};
    }
  }
  return {std::atoi(string)};
}
