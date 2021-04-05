#include "task3.hpp"
#include <iostream>
#include <vector>
#include "ArgumentParseException.hpp"

std::vector< int > input_int_vec()
{
  std::vector< int > values;
  while(true) {
    int num;
    std::cin >> num;
    if(std::cin.eof()) {
      break;
    }
    if(std::cin.fail()) {
      throw ArgumentParseException("Not a number");
    }
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
    throw ArgumentParseException("No values given");
  }
  if(values.back() != 0) {
    throw ArgumentParseException("Output should end with a 0");
  }
  values.pop_back();

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
