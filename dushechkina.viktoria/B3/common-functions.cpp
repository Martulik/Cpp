#include "common-functions.hpp"
#include <iostream>
#include <string>
#include <cctype>

void checkForFailInput(const std::istream& in)
{
  if (in.bad())
  {
    throw std::runtime_error("Something went wrong! The program stops working!\n");
  }

  if (in.fail())
  {
    throw std::invalid_argument("Incorrect input! Written command is too long!\n");
  }
}

void checkForEmptyInput(const std::string& in)
{
  if (in.empty())
  {
    throw std::invalid_argument("Incorrect input! Input must have command (and necessary parameters)!\n");
  }
}
