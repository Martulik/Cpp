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

void poz::removeWS(std::string& str)
{
  using namespace std::placeholders;
  auto isNotSpace = std::bind(std::not_equal_to< char >(), _1, ' ');
  std::string newStr;
  std::copy_if(str.cbegin(), str.cend(), std::back_inserter(newStr), isNotSpace);
  str = newStr;
}
