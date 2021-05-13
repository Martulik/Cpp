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

  bool isCorrect(const std::string& line);
  bool operator<(const DataStruct& temp1, const DataStruct& temp2);
  std::istream& operator>>(std::istream& in, DataStruct& value);
  std::ostream& operator<<(std::ostream& out, DataStruct& value);
}
#endif
