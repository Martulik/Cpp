#include "functions.hpp"

namespace poz = pozdnyakov;

bool poz::findSpaces(const char* const str)
{
  for (size_t i = 0; i < strlen(str); i++)
  {
    if (str[i] == ' ')
    {
      return true;
    }
  }
  return false;
}
