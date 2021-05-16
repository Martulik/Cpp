#include "tools.hpp"
#include <cctype>
#include <iostream>
#include <cmath>

namespace lab = shkurov;

number_t lab::stringToNumber(const std::string& str)
{
  number_t result = 0;
  size_t radix = str.size() - 1;
  std::string::const_iterator it = str.cbegin();

  while (it != str.cend())
  {
    if (std::isdigit(*it))
    {
      result += pow(10, radix) * ((*it) - '0');
    }
    else
    {
      throw std::invalid_argument("Number should only consist of digits.");
    }
    radix--;
    it++;
  }

  return result;
}

std::string lab::nameCorrection(std::string str)
{
  if (*(str.begin()) == '"' && *(str.end() - 1) == '"')
  {
    str.erase(str.begin());
    str.erase(str.end() - 1);
  }
  else
  {
    throw std::invalid_argument("Name should be enclosed in quotes.");
  }

  std::string::iterator it = str.begin();

  while (it != str.end())
  {
    if (*it == '\\')
    {
      if (*(it + 1) == '"')
      {
        it = str.erase(it);
      }
    }
    it++;
  }

  return str;
}

bool lab::isNumber(const std::string& str)
{
  std::string::const_iterator it = str.cbegin();
  if (*it == '-')
  {
    if (++it == str.cend())
    {
      return false;
    }
  }
  while (it != str.cend())
  {
    if(!std::isdigit(*it))
    {
      return false;
    }
    it++;
  }

  return true;
}

bool lab::isCorrectBookmarkName(const std::string& str)
{
  std::string::const_iterator it = str.cbegin();

  while (it != str.cend())
  {
    if (!std::isalpha(*it) || !std::isdigit(*it) || !(*it == '-'))
    {
      return false;
    }
    it++;
  }

  return true;
}

void lab::printNode(std::ostream& out, const node_t& pair)
{
  out << std::get<0>(pair) << ' ' << std::get<1>(pair) << '\n';
}

constexpr unsigned long factorial(unsigned long number)
{
  if (number == 1)
  {
    return 1;
  }
  else
  {
    return factorial(number - 1) * number;
  }
}
