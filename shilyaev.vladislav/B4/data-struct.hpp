#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <string>
#include <iosfwd>

namespace shilyaev {
  struct DataStruct {
    int key1;
    int key2;
    std::string str;
  };
  std::ostream &operator<<(std::ostream &ostream, const DataStruct &dataStruct);
  std::istream &operator>>(std::istream &istream, DataStruct &dataStruct);
  bool compare(const DataStruct &a, const DataStruct &b);
}

#endif
