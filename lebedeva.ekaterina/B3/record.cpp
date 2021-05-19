#include "record.hpp"
#include <iostream>

std::ostream& lebedeva::operator<<(std::ostream& out, const record_t& rec)
{
  out << rec.name << "\t" << rec.phoneNumber;
  return out;
}

bool lebedeva::checkNumber(const std::string& number)
{
  if (number.length() >= 1)
  {
    for (size_t i = 0; i < number.length(); i++)
    {
      if (!isdigit(number[i]))
      {
        return false;
      }
    }
    return true;
  }
  return false;
}
