#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <vector>
#include "dataStruct.hpp"

namespace ezerinia {
  bool compare(DataStruct &lhs, DataStruct &rhs);
  void read(std::vector< DataStruct > &vector);
  void task();
}
#endif
