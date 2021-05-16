#include "functions.hpp"
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <istream>

std::string ferapontov::read(std::istream& in)
{
  std::string line;
  in >> line;
  if (in.fail() && !in.eof())
  {
    throw std::runtime_error("<INPUT ERROR>");
  }
}

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

std::string ferapontov::checkMarkName(std::string& markName)
{
  for (char& ch: markName)
  {
    if (!isalpha(ch) && !isdigit(ch) && ch != '-')
    {
      throw std::invalid_argument("<INVALID COMMAND>");
    }
  }
  return markName;
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