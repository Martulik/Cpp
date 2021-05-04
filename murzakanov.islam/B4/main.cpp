#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

#include "data-struct.hpp"

int main()
{
  std::vector< murzakanov::DataStruct > vec;
  murzakanov::DataStruct temp;
  while (std::cin >> temp)
  {
    vec.push_back(temp);
  }
  std::sort(vec.begin(), vec.end());
  std::copy(vec.begin(), vec.end(), std::ostream_iterator< murzakanov::DataStruct >(std::cout));
}
