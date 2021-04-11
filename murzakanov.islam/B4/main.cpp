#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

#include "data-struct.hpp"
#include "tools.hpp"

int main()
{
  std::vector< murzakanov::DataStruct > vec;
  murzakanov::DataStruct temp;

  while (std::cin >> temp)
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
