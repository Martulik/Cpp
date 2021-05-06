#include "record_t.hpp"
#include <iostream>
#include <string>

namespace lab = ezerinia;

std::istream &operator>>(std::istream &in, lab::record_t &src)
{
  std::string number;
  in >> std::ws >> number;
  if (number.empty()) {
    src.number = "";
    src.name = "";
    return in;
  }
  for (char i : number) {
    if (!std::isdigit(i)) {
      src.number = "";
      src.name = "";
      return in;
    }
  }
  src.number = number;

  std::string name;
  std::getline(in >> std::ws, name);

  if ((name.empty()) || (name.front() != '\"') || (name.back() != '\"')) {
    src.name = "";
    return in;
  }
  name.erase(name.begin());
  size_t i = 0;
  while ((i < name.size()) && (name[i] != '\"')) {
    if (name[i] == '\\') {
      if ((name[i + 1] == '\"') && (i + 2 < name.size())) {
        name.erase(i, 1);
      } else {
        src.name = "";
        return in;
      }
    }
    i++;
  }
  if (i == name.size()) {
    src.name = "";
    return in;
  }
  name.erase(i);
  if (name.empty()) {
    src.name = "";
    return in;
  }
  src.name = name;
  return in;
}

std::ostream &operator<<(std::ostream &out, const lab::record_t &src)
{
  out << src.number << " " << src.name << "\n";
  return out;
}
