#include "helpFunctions.h"

#include <vector>
#include <iostream>

#include "DataStruct.h"

namespace lysenko
{
  void sortVector(std::vector< DataStruct >& myVect)
  {
    for (long unsigned int i = 0; i < myVect.size(); i++)
    {
      for (long unsigned int j = i; j < myVect.size(); j++)
      {
        if (myVect[i] < myVect[j])
        {
          std::swap(myVect[i], myVect[j]);
        }
      }
    }
  }

  void printVector(const std::vector< DataStruct >& myVect, std::ostream& out)
  {
    for (long unsigned int i = 0; i < myVect.size(); i++)
    {
      out << myVect[i].key1 << "," << myVect[i].key2 << "," << myVect[i].str << "\n";
    }
  }
}
