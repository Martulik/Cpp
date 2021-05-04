#include "tools.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "dataStruct.hpp"

namespace lab = ezerinia;

void lab::checkInput(const DataStruct &data, char comma1, char comma2)
{
  if (comma1 != ',' || comma2 != ',' || abs(data.key1) > 5 || abs(data.key2) > 5) {
    throw std::invalid_argument("Invalid input\n");
  }
}

bool lab::compare(DataStruct &lhs, DataStruct &rhs)
{
  if (lhs.key1 != rhs.key1) {
    return lhs.key1 < rhs.key1;
  } else if (lhs.key2 != rhs.key2) {
    return lhs.key2 < rhs.key2;
  } else {
    return lhs.str < rhs.str;
  }
}

void lab::print(std::vector< DataStruct > &vector, std::ostream &out)
{
  //for (auto it = vector.begin(); it != vector.end(); it++) {
  for (auto &&it: vector) {
    out << it.key1 << ", " << it.key2 << ", " << it.str << "\n";
  }
}

void lab::read(std::vector< lab::DataStruct > &vector)
{
  std::cout<<"start read\n";
  std::string line;
  std::string str;
  char comma1;
  char comma2;
  while (std::getline(std::cin, line)) {
    lab::DataStruct data;
    std::stringstream input(line);
    input >> data.key1 >> comma1 >> data.key2 >> comma2;
    checkInput(data, comma1, comma2);
    if (input >> data.str)
    {
      vector.push_back(data);
    }
//    while (!input.eof()) {
//      input >> data.str;
//    }
//    vector.push_back(data);
  }
  std::cout<<"end read\n";
}

void lab::task()
{
  std::vector< lab::DataStruct > vector;
  read(vector);
  std::sort(vector.begin(), vector.end(), compare);
  std::cout << vector.data();
  print(vector, std::cout);
}
