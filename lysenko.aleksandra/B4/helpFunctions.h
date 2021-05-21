#ifndef HELP_FUNCTIONS_H
#define HELP_FUNCTIONS_H

#include <vector>

#include "DataStruct.h"

namespace lysenko
{
  void sortVector(std::vector< DataStruct >& myVect);
  void printVector(const std::vector< DataStruct >&myVect, std::ostream &out);
}

#endif
