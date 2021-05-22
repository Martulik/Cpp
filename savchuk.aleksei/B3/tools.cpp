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

std::string lab::readMarkName(std::istream& is)
{
  std::string markName;
  is >> markName;
  if (is.fail() && !is.eof())
  {
    throw std::runtime_error(INPUT_ERROR);
  }
  for (char& ch: markName)
  {
    if (!isalpha(ch) && !isdigit(ch) && ch != '-')
    {
      throw std::invalid_argument(INVALID_COMMAND);
    }
  }
  return markName;
}

std::string lab::readSteps(std::istream& is)
{
  std::string steps;
  is >> steps;
  if (is.fail() && !is.eof())
  {
    throw std::runtime_error(INPUT_ERROR);
  }
  std::string::iterator it = steps.begin();
  if (*it == '-' || *it == '+')
  {
    ++it;
  }
  if (!std::all_of(it, steps.end(), ::isdigit) && steps != "first" && steps != "last")
  {
    throw std::invalid_argument(INVALID_STEP);
  }
  return steps;
}

std::string lab::readPosition(std::istream& is)
{
  std::string position;
  is >> position;
  if (is.fail() && !is.eof())
  {
    throw std::runtime_error(INPUT_ERROR);
  }
  if (position != "before" && position != "after")
  {
    throw std::invalid_argument(INVALID_COMMAND);
  }
  return position;
}
