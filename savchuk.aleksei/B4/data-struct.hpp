#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <string>
#include <iosfwd>

namespace savchuk
{
  struct DataStruct
  {
    int key1;
    int key2;
    std::string str;
  };

  std::istream& operator>>(std::istream& is, DataStruct& ds);
  std::ostream& operator<<(std::ostream& os, const DataStruct& ds);
}

#endif
