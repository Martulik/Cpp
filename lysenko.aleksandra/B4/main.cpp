#include <iostream>
#include<vector>

#include "DataStruct.h"
#include "helpFunctions.h"

int main()
{
  std::vector< lysenko::DataStruct > myVect;
  lysenko::fillVector(myVect);
  lysenko::sortVector(myVect);
  lysenko::printVector(myVect, std::cout);
  return 0;
}