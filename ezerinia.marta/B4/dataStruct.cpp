#include "dataStruct.hpp"
#include <sstream>

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
  out << data.key1 << "," << data.key2 << "," << data.str;
  return out;
}

std::istream &ezerinia::operator>>(std::istream &in, ezerinia::DataStruct &data)
{
  std::string str;
  std::getline(in,str);
  std::istringstream iss(str);
  char comma = '\0';
  iss >> data.key1;
  if (!in.fail()) {
    iss >> comma;
    if (!in.fail() && comma == ',') {
      iss >> data.key2;
      if (!in.fail()) {
        iss >> comma;
      }
    }
  }
  if (!iss || comma != ',' || abs(data.key1) > 5 || abs(data.key2) > 5) {
    in.setstate(std::ios::failbit);
    return in;
  }
  if (!in.eof()) {
    std::getline(iss, data.str);
  }
  return in;
}
