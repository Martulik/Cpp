#include "dataStruct.hpp"
#include <iostream>

bool ezerinia::operator<(const DataStruct &lhs, const DataStruct &rhs){
  if (lhs.key1 != rhs.key1) {
    return lhs.key1 < rhs.key1;
  } else if (lhs.key2 != rhs.key2) {
    return lhs.key2 < rhs.key2;
  } else {
    return lhs.str.length() < rhs.str.length();
  }
}

std::ostream &ezerinia::operator<<(std::ostream &out, const ezerinia::DataStruct &data)
{
  out << data.key1 << "," << data.key2 << "," << data.str << "\n";
  return out;
}

std::istream &ezerinia::operator>>(std::istream &in, ezerinia::DataStruct &data)
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
