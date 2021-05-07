#include "note.hpp"
#include <iostream>

namespace lab = borisova;

bool lab::correctName(std::string& name)
{
  if (name.empty() || name.front() != '\"' || name.back() != '\"')
  {
    return false;
  }
  name.erase(name.begin());
  name.erase(--name.end());

  for (size_t i = 0; i < name.length(); i++)
  {
    if (name[i] == '\\')
    {
      name.erase(i, 1);
    }
  }
  if (name.empty())
  {
    return false;
  }
  return true;
}

bool lab::correctNumder(std::string& number)
{
  if (number.length() < 1)
  {
    return false;
  }
  for (size_t i = 0; i < number.length(); i++)
  {
    if (!isdigit(number[i]))
    {
      return false;
    }
  }
  return true;
}

std::ostream& lab::operator<<(std::ostream& out, const Note& value)
{
  out << value.number_ << ' ' << value.name_ << '\n';
  return out;
}
