#include "record.hpp"
#include <iostream>
#include <algorithm>

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
    std::string::const_iterator it = number.begin();
    if (number.length() > 1)
    {
      if ((*it == '+') || (*it == '-'))
      {
        it++;
      }
    }
    if (std::all_of(it, number.end(), ::isdigit))
    {
      bResult = true;
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

  name.erase(std::remove(name.begin(), name.end(), '\\'), name.end());
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
