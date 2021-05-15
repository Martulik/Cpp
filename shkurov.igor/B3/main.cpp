#include <iostream>

#include "PhoneBook.hpp"
#include "tasks.hpp"

namespace lab = shkurov;

int main()
{
  task1(std::cin, std::cout);
  std::list<int> lst;
  std::list<int>::iterator it = lst.begin();
  it++;

  return 0;
}
