#ifndef DATASTRUCT_HPP
#define DATASTRUCT_HPP

#include <iosfwd>
#include <string>

namespace doroshin
{
  struct DataStruct
  {
    int key1, key2;
    std::string str;
  };

  std::istream& operator>>(std::istream&, DataStruct&);

  bool sort_order(const DataStruct&, const DataStruct&);
}

#endif //DATASTRUCT_HPP
