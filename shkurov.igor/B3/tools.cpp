#include "tools.hpp"
#include <cctype>
#include <iostream>
#include <cmath>

namespace lab = shkurov;

std::string lab::nameCorrection(std::string str)
{
  if (*(str.begin()) == '"' && *(str.end() - 1) == '"')
  {
    str.erase(str.begin());
    str.erase(str.end() - 1);
  }
  else
  {
    throw std::invalid_argument("<INVALID COMMAND>\n");
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
  if (*it == '-' || *it == '+')
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
    if (!std::isalpha(*it) && !std::isdigit(*it) && !(*it == '-'))
    {
      return false;
    }
    it++;
  }

  return true;
}

void lab::printNode(std::ostream& out, const node_t& pair)
{
  out << std::get<1>(pair) << ' ' << std::get<0>(pair) << '\n';
}
