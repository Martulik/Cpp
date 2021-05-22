#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP
#include <string>

namespace borisova
{
  struct DataStruct
  {
    int key1;
    int key2;
    std::string str;
  };

  bool operator<(const DataStruct& temp1, const DataStruct& temp2);
  std::istream& operator>>(std::istream& in, DataStruct& value);
  std::ostream& operator<<(std::ostream& out, const DataStruct& value);
}
#endif
