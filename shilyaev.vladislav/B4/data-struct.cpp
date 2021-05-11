#include "data-struct.hpp"
#include <iostream>
#include <sstream>

namespace shilyaev {
  std::ostream &operator<<(std::ostream &ostream, const DataStruct &dataStruct)
  {
    return ostream << dataStruct.key1 << ", " << dataStruct.key2 << ", " << dataStruct.str;
  }

  int readKey(std::istream &istream)
  {
    std::string str;
    std::getline(istream, str, ',');
    try {
      int key = std::stoi(str);
      if (key < -5 || key > 5) {
        istream.setstate(std::ios::failbit);
      }
      return key;
    } catch (const std::invalid_argument &) {
      istream.setstate(std::ios::failbit);
      return 0;
    }
  }

  std::istream &operator>>(std::istream &istream, DataStruct &dataStruct)
  {
    std::string line;
    std::getline(istream, line);
    std::istringstream istringstream(line);
    dataStruct.key1 = readKey(istringstream);
    dataStruct.key2 = readKey(istringstream);
    std::getline(istringstream, dataStruct.str);
    if (istringstream.fail()) {
      istream.setstate(std::ios::failbit);
    }
    return istream;
  }

  bool operator==(const DataStruct &a, const DataStruct &b)
  {
    return a.key1 == b.key1 && a.key2 == b.key2 && a.str == b.str;
  }

  bool compare(const DataStruct &a, const DataStruct &b)
  {
    if (a.key1 != b.key1) {
      return a.key1 < b.key1;
    } else if (a.key2 != b.key2) {
      return a.key2 < b.key2;
    } else {
      return a.str.length() < b.str.length();
    }
  }
}
