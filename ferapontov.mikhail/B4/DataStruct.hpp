#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <iosfwd>
#include <string>
#include <vector>

namespace ferapontov
{
  struct DataStruct
  {
    int key1;
    int key2;
    std::string str;
  };

  std::istream& operator>>(std::istream& in, DataStruct& src);
  std::ostream& operator<<(std::ostream& out, const DataStruct& src);

  bool operator<(const DataStruct& lhs, const DataStruct& rhs);
  bool operator==(const DataStruct& lhs, const DataStruct& rhs);

  int readNumber(std::istream& in, const char& delim);
}

#endif
