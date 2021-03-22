#include "task3.hpp"
#include <iostream>
#include <vector>

std::vector< int > input_int_vec()
{
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
  return values;
}

void filterEven(std::vector< int >& vec)
{
  using It = typename std::vector< int >::iterator;
  for(It i = vec.begin(); i != vec.end();) {
    if(*i % 2 == 0) {
      i = vec.erase(i);
    }
    else {
      i++;
    }
  }
}

void put1after3(std::vector< int >& vec)
{
  using It = typename std::vector< int >::iterator;
  for(It i = vec.begin(); i != vec.end(); ++i) {
    if(*i % 3 == 0) {
      i = vec.insert(++i, 1);
      i = vec.insert(++i, 1);
      i = vec.insert(++i, 1);
    }
  }
}

void doroshin::filterInput()
{
  std::vector< int > values = input_int_vec();
  if(values.empty()) {
    std::cerr << "No values given\n";
    return;
  }

  if(values.back() == 1) {
    filterEven(values);
  } else if(values.back() == 2) {
    put1after3(values);
  }

  for(int num: values) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
}
