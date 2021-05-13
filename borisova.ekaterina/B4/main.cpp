#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "data-struct.hpp"

namespace lab = borisova;

int main()
{
  std::vector< lab::DataStruct > vector;
  lab::DataStruct value;
  std::string line;
  while (std::getline(std::cin, line) && !line.empty())
  {
    std::istringstream in(line);
    in >> value;
    vector.push_back(value);
  }
  std::sort(vector.begin(), vector.end());
  for (size_t i = 0; i < vector.size(); i++)
  {
    std::cout << vector[i];
  }
  return 0;
}
