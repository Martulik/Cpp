#include "functions.hpp"

void ferapontov::checkSpaces(const char* str)
{
  for (size_t i = 0; i < strlen(str); i++)
  {
    if (str[i] == ' ')
    {
      std::cerr << "Argument with spaces";
      std::exit(1);
    }
  }
}

void ferapontov::checkNumber(const char* str)
{
  for (size_t i = 0; i < strlen(str); i++)
  {
    if(!isdigit(str[i]))
    {
      std::cerr << "Argument is not a number";
      std::exit(1);
    }
  }
}