#ifndef B4_STRUCT_HPP
#define B4_STRUCT_HPP

#include <string>
#include <iostream>

namespace ivanova
{
  struct DataStruct
  {
    int key1;
    int key2;
    std::string str;

    bool operator >(const DataStruct &data) const;
  };
}
#endif
