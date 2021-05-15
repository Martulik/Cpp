#include "common-functions.hpp"
#include <iostream>
#include <string>
#include <cctype>

void checkForFailInput(const std::istream& in)
{
  if (in.bad())
  {
    throw std::runtime_error("Something went wrong, program stops working\n");
  }

  if (in.fail())
  {
    throw std::invalid_argument("Incorrect input\n");
  }
}

void checkForEmptyInput(const std::string& in)
{
  if (in.empty())
  {
    throw std::invalid_argument("Incorrect input,it must have command\n");
  }
}
