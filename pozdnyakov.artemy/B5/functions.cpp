#include "functions.hpp"
#include <stdexcept>

namespace poz = pozdnyakov;

void poz::checkLineEnding(const std::string& str)
{
  if (str.find('\n') != std::string::npos)
  {
    throw std::invalid_argument("Incorrect input");
  }
}

bool poz::compChar(char a, char b)
{
  return a == b;
}

bool poz::compCharNeg(char a, char b)
{
  return a != b;
}

void poz::removeWS(std::string& str)
{
  auto isNotSpace = std::bind(poz::compCharNeg, std::placeholders::_1, ' ');
  std::string newStr;
  std::copy_if(str.cbegin(), str.cend(), std::back_inserter(newStr), isNotSpace);
  str = newStr;
}
