#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <string>
#include <iosfwd>

namespace pozdnyakov
{
  struct DataStruct
  {
    int key1;
    int key2;
    std::string str;
  };
  std::ostream& operator<<(std::ostream& out, const DataStruct& obj);
  std::istream& operator>>(std::istream& in, DataStruct& obj);
  int extractKey(std::string& str);
  bool comparator(DataStruct s1, DataStruct s2);
}

#endif
