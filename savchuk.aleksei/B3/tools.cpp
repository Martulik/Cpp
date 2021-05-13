#include "tools.hpp"

#include <istream>
#include <stdexcept>
#include <algorithm>
#include <cctype>

#include "error-messages.hpp"

namespace lab = savchuk;

std::string lab::readNumber(std::istream& is)
{
  std::string number;
  is >> number;
  if (is.fail() && !is.eof())
  {
    throw std::runtime_error(INPUT_ERROR);
  }
  if (!std::all_of(number.begin(), number.end(), ::isdigit))
  {
    throw std::invalid_argument(INVALID_COMMAND);
  }
  return number;
}

std::string lab::readName(std::istream& is)
{
  is >> std::ws;
  std::string name;
  std::getline(is, name);
  if (is.fail() && !is.eof())
  {
    throw std::runtime_error(INPUT_ERROR);
  }
  if (name.size() < 3)
  {
    throw std::invalid_argument(INVALID_COMMAND);
  }
  if (name.front() != '"' || name.back() != '"')
  {
    throw std::invalid_argument(INVALID_COMMAND);
  }
  std::rotate(name.begin(), ++name.begin(), name.end());
  name.pop_back();
  name.pop_back();
  name.erase(std::remove(name.begin(), name.end(), '\\'), name.end());
  return name;
}
