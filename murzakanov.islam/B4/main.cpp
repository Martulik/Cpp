#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

#include "data-struct.hpp"

int main()
{
  std::vector< murzakanov::DataStruct > vec;
  std::fstream in("input.txt");
  murzakanov::DataStruct temp;

  while (in >> temp)
  {
    vec.push_back(temp);
  }
  std::sort(vec.begin(), vec.end());
  auto it = vec.begin();
  auto end = vec.end();
  while (it != end)
  {
    std::cout << *it;
    ++it;
  }
}
