#include "functions.hpp"

#include <cctype>

bool checkSpaces(const char* str)
{
  if (strchr(str, ' '))
  {
    return true;
  }
  return false;
}

bool checkNumber(const char* str)
{
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    if (!std::isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}
