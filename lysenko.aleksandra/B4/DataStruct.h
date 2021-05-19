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

  bool isGreater(const DataStruct& firstOp, const DataStruct& secondOp);
}

#endif
