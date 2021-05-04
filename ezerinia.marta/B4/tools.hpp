#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <vector>
#include <sstream>
#include "dataStruct.hpp"

namespace ezerinia {

  void checkInput(const DataStruct &data, char comma,std::stringstream &input);

  bool compare(DataStruct &lhs, DataStruct &rhs);

  void print(std::vector< DataStruct > &vector, std::ostream &out);

  void read(std::vector< DataStruct > &vector);

  void task();

}
#endif