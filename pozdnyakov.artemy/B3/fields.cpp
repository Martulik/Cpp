#include "fields.hpp"
#include <algorithm>

namespace poz = pozdnyakov;

bool poz::Command::isField(std::string field) const
{
  return std::find(commands_.begin(), commands_.end(), field) != commands_.end();
}

bool poz::CommandParam::isField(std::string field) const
{
  return std::find(params_.begin(), params_.end(), field) != params_.end();
}

bool poz::PhoneNumber::isField(std::string field) const
{
  return std::all_of(field.begin(), field.end(), &isNumber); // temp
}

bool poz::Name::isField(std::string) const
{
  return true; // to do
}

bool poz::String::isField(std::string) const
{
  return true;
}

bool poz::Int::isField(std::string field) const
{
  return std::all_of(field.begin(), field.end(), &isNumber);
}

bool poz::isNumber(char c)
{
  return std::isdigit(c) != 0;
}
