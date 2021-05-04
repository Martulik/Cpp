#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <vector>
#include "dataStruct.hpp"

namespace ezerinia {

  void checkInput(const DataStruct &data, char comma1, char comma2);

  bool compare(DataStruct &lhs, DataStruct &rhs);

  void print(std::vector< DataStruct > &vector, std::ostream &out);

  void read(std::vector< DataStruct > &vector);

  void task();

}
#endif