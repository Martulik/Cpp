#include <vector>
#include <list>
#include <iostream>

void task1(const char* order)
{
  int x;
  std::vector< int > firstVector;
  while(std::cin.eof())
  {
    std::cin >> x;
    firstVector.push_back();
  }
  std::vector< int > secondVector(firstVector);
  sort< firstVector, order >;
  sort< secondVector, order >;
  sort< list, order >;
}
