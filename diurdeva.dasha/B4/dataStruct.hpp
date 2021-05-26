#ifndef DATASTRUCT_HPP
#define DATASTRUCT_HPP

#include <string>

namespace diurdeva {
  struct DataStruct
  {
    int key1;
    int key2;
    std::string str;
  };

  std::istream& operator >>(std::istream& input, DataStruct& dataStruct);
  std::ostream& operator <<(std::ostream& output, const DataStruct& dataStruct);
  bool compare(const DataStruct& lhs, const DataStruct& rhs);
}
#endif
