#include "tools.hpp"
#include <iostream>
#include <sstream>
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

void lab::read(std::vector< lab::DataStruct > &vector, std::istream &in)
{
  std::string line;
  while (std::getline(in, line)) {
    lab::DataStruct data;
    std::stringstream input(line);
    input >> data;
    vector.push_back(data);
  }
}

void lab::task(std::istream &in, std::ostream &out)
{
  std::vector< lab::DataStruct > vector;
  read(vector, in);
  std::sort(vector.begin(), vector.end(), compare);
  for (auto &&it: vector) {
    out << it;
  }
}
