#include "task3.hpp"
#include <iostream>
#include <vector>

void doroshin::filterInput()
{
  using It = typename std::vector< int >::iterator;
  std::vector< int > values;
  while(true) {
    int num = 0;
    std::cin >> num;
    if(std::cin.eof() || std::cin.fail()) {
      std::cerr << "Could not input the next number";
    }
    if(num == 0)
      break;
    values.push_back(num);
  }
  if(values.empty())
    return;

  if(values.back() == 1) {
    for(It i = values.begin(); i != values.end();) {
      if(*i % 2 == 0) {
        i = values.erase(i);
      }
      else {
        i++;
      }
    }
  } else if(values.back() == 2) {
    for(It i = values.begin(); i != values.end(); ++i) {
      if(*i % 3 == 0) {
        i = values.insert(++i, 1);
        i = values.insert(++i, 1);
        i = values.insert(++i, 1);
      }
    }
  }
  for(int num: values) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
}
