#include "tasks.hpp"
#include <vector>
#include <iostream>
#include "print.hpp"
#include "vector-operations.hpp"

namespace poz
{
  void task3()
  {
    std::vector< int > vector;
    int n;
    std::cin >> n;
    while (n != 0)
    {
      vector.push_back(n);
      std::cin >> n;
    }
    if (*std::prev(vector.end()) == 1)
    {
      eraseEven(vector);
    }
    else if (*std::prev(vector.end()) == 2)
    {
      addOnes(vector);
    }
    print(vector, std::cout);
  }
}
