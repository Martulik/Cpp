#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <vector>
#include <iosfwd>
#include "dataStruct.hpp"

namespace ezerinia {
  bool compare(DataStruct &lhs, DataStruct &rhs);
  void read(std::vector< DataStruct > &vector, std::istream &in);
  void task(std::istream &in, std::ostream &out);
}
#endif
