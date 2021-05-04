#include <iostream>
#include <vector>
#include "dataStruct.hpp"

namespace lab = ezerinia;

int main()
{
  try {
    std::vector< lab::DataStruct > vector;
    std::string line;
    while(std::getline(std::cin,line))
    {

    }
  }
  catch (const std::exception &ex) {
    std::cerr << ex.what() << "\n";
  }
}
