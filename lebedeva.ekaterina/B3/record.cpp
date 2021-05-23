#include "record.hpp"
#include <iostream>

std::ostream& lebedeva::operator<<(std::ostream& out, const record_t& rec)
{
  out << rec.phoneNumber << " " << rec.name;
  return out;
}

bool lebedeva::checkNumber(const std::string& number)
{
  bool bResult = false;
  if (number.length() >= 1)
  {
    bResult = true;
    for (size_t i = 0; i < number.length(); i++)
    {
      if (!isdigit(number[i]))
      {
        bResult = false;
        break;
      }
    }
  }
  return bResult;
}

void lebedeva::extractName(std::string& name)
{
  if (name.front() == '\"')
  {
    name.erase(name.begin());
  }
  if (name.back() == '\"')
  {
    name.erase(--name.end());
  }

  for (size_t i = 0; i < name.length(); i++)
  {
    if (name[i] == '\\')
    {
      name.erase(i, 1);
    }
  }
}

bool lebedeva::isName(const std::string& name)
{
  bool bResult = false;
  if (name.front() == '\"' && name.back() == '\"')
  {
    bResult = true;
  }
  return bResult;
}
