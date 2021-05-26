#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <string>
#include <iosfwd>

namespace shkurov
{
  struct DataStruct
  {
    int         key1;
    int         key2;
    std::string str;
  };

  std::istream& operator>>(std::istream& in, DataStruct& data);
  std::ostream& operator<<(std::ostream& out, const DataStruct& data);

  int readKey(std::istream& in);
  int intConvert(const std::string& str);

  bool compare(const DataStruct& lhs, const DataStruct& rhs);
}

#endif
