#include "tools.hpp"

#include <sstream>
#include <string>

size_t murzakanov::getValue(const size_t num)
{
  if (num == 1)
  {
    return 1;
  }
  return num * getValue(num - 1);
}

std::istream& murzakanov::readName(std::istream& in, std::string& name)
{
  name.clear();
  while (in.get() != '"')
  {
    if (!in)
    {
      return in;
    }
  }
  while (!in.eof())
  {
    char next = in.get();
    if (next == '\\')
    {
      name += in.get();
    }
    else if (next != '"')
    {
      name += next;
    }
    else
    {
      break;
    }
  }
  //else
  //{
  //  in.setstate(std::ios_base::failbit);
  //}
  return in;
}

bool murzakanov::checkIsNum(const std::string& number)
{
  for (size_t i = 0; i < number.length(); i++)
  {
    if (!std::isdigit(number[i]))
    {
      return false;
    }
  }
  return true;
}
