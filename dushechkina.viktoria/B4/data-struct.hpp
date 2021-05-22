#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <string>

namespace dushechkina
{
  struct DataStruct
  {
    int key1;
    int key2;
    std::string str;
  };

  std::ostream& operator<<(std::ostream& out, const DataStruct& data);
  std::istream& operator>>(std::istream& in, DataStruct& data);
  bool operator<(const DataStruct& first, const DataStruct& second);
}

#endif
