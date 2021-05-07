#include "dataStruct.hpp"

#include <iostream>

std::ostream &operator<<(std::ostream &out, const ezerinia::DataStruct &data)
{
  out << data.key1 << "," << data.key2 << "," << data.str << "\n";
  return out;
}

std::istream &operator>>(std::istream &in, ezerinia::DataStruct &data)
{
  char comma = '\0';
  in >> data.key1;
  if (!in.fail()) {
    in >> comma;
    if (!in.fail() && comma == ',') {
      in >> data.key2;
      if (!in.fail()) {
        in >> comma;
      }
    }
  }
  if (in.fail() || comma != ',' || abs(data.key1) > 5 || abs(data.key2) > 5) {
    throw std::invalid_argument("Invalid input\n");
  }
  if (!in.eof()) {
    std::getline(in, data.str);
  }
  return in;
}
