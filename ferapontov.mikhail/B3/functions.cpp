#include "functions.hpp"
#include <stdexcept>
#include <algorithm>
#include <cctype>

std::string ferapontov::checkName(std::string& name)
{
  if (name.front() != '"' || name.back() != '"' || (name.size() < 2))
  {
    throw std::invalid_argument("<INVALID COMMAND>");
  }
  name.pop_back();
  name.erase(0, 1);
  return name;
}

int ferapontov::checkNumber(std::string& num)
{
  if (!std::all_of(num.begin(), num.end(), ::isdigit))
  {
    throw std::invalid_argument("<INVALID_COMMAND>");
  }
  int number = std::stoi(num);
  return number;
}