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
  if ((argument != 1) && (argument != 2))
  {
    return -1;
  }
  return argument;
}

bool pochernin::isNumber(const std::string& str)
{
  if (str.size() == 0)
  {
    return false;
  }
  else if ((str.size() == 1) && !std::isdigit(str[0]))
  {
    return false;
  }
  else
  {
    if ((str[0] != '-') && !std::isdigit(str[0]))
    {
      return false;
    }
    for (size_t i = 1; i < str.length(); i++)
    {
      if (!std::isdigit(str[i]))
      {
        return false;
      }
    }
  }
  return true;
}
