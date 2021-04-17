#include "tasks.hpp"
#include <string>
#include <stdexcept>
#include <cstring>
#include <iostream>
#include "sort.hpp"
#include "strategies.hpp"
#include "functions.hpp"

namespace poz
{
  void task1(char* argv[])
  {
    std::string asc = "ascending";
    std::string desc = "descending";
    bool isAscending;
    if (!strcmp(argv[0], asc.c_str()))
    {
      isAscending = true;
    }
    else if (!strcmp(argv[0], desc.c_str()))
    {
      isAscending = false;
    }
    else
    {
      throw std::invalid_argument("Wrong argument");
    }
    std::vector<int> vector;
    int n;
    while (std::cin >> n)
    {
      vector.push_back(n);
    }
    if (std::cin.fail() && !std::cin.eof())
    {
      throw std::runtime_error("Invalid file content");
    }
    std::vector< int > indexVector(vector);
    std::vector< int > atVector(vector);
    std::list< int > list(vector.begin(), vector.end());
    sort< IndexStrategy< int > >(indexVector, isAscending);
    sort< VectorAtStrategy< int > >(atVector, isAscending);
    sort< ListStrategy< int > >(list, isAscending);
    print(indexVector, std::cout);
    print(atVector, std::cout);
    print(list, std::cout);
  }
}
