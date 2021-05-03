#include "data-struct.hpp"
#include <iostream>

namespace shilyaev {
  std::ostream &operator<<(std::ostream &ostream, const DataStruct &dataStruct)
  {
    return ostream << dataStruct.key1 << ", " << dataStruct.key2 << ", " << dataStruct.str;
  }

  std::istream &operator>>(std::istream &istream, DataStruct &dataStruct)
  {
    istream >> dataStruct.key1;
    istream.ignore();
    istream >> dataStruct.key2;
    if (dataStruct.key1 < -5 || dataStruct.key1 > 5 || dataStruct.key2 < -5 || dataStruct.key2 > 5) {
      istream.setstate(std::ios::failbit);
      return istream;
    }
    istream.ignore(2);
    std::getline(istream, dataStruct.str);
    return istream;
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
