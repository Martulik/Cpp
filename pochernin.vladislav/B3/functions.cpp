#include "functions.hpp"

#include <cstring>
#include <cctype>
#include <cstdlib>

int pochernin::getTaskNumber(const char* string)
{
  if (strlen(string) != 1)
  {
    return -1;
  }
  if (!std::isdigit(string[0]))
  {
    return -1;
  }
  int argument = std::atoi(string);
  if ((argument != 1) || (argument != 2))
  {
    return -1;
  }
  return argument;
}
