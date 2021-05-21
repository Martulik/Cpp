#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <string>

namespace lysenko
{
  struct DataStruct
  {
    int key1;
    int key2;
    std::string str;
  };

  std::istream& operator >> (std::istream&, DataStruct& data);
  bool operator <(const DataStruct& firstOp, const DataStruct& secondOp);
}

#endif
