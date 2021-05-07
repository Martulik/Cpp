#include "tools.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include "dataStruct.hpp"

namespace lab = ezerinia;

bool lab::compare(DataStruct &lhs, DataStruct &rhs)
{
  if (lhs.key1 != rhs.key1) {
    return lhs.key1 < rhs.key1;
  } else if (lhs.key2 != rhs.key2) {
    return lhs.key2 < rhs.key2;
  } else {
    return lhs.str.length() < rhs.str.length();
  }
}

void lab::read(std::vector< lab::DataStruct > &vector)
{
  std::string line;
  while (std::getline(std::cin, line)) {
    lab::DataStruct data;
    std::stringstream input(line);
    input >> data;
    vector.push_back(data);
  }
}

void lab::task()
{
  std::vector< lab::DataStruct > vector;
  read(vector);
  std::sort(vector.begin(), vector.end(), compare);
  for (auto &&it: vector) {
    std::cout << it;
  }
}
