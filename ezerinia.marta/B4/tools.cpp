#include "tools.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "dataStruct.hpp"

namespace lab = ezerinia;

void lab::checkInput(const DataStruct &data, char comma, std::stringstream &input)
{
  if (input.fail() || comma != ',' || abs(data.key1) > 5 || abs(data.key2) > 5) {
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
  for (auto &&it: vector) {
    out << it.key1 << "," << it.key2 << "," << it.str << "\n";
  }
}

void lab::read(std::vector< lab::DataStruct > &vector)
{
  std::string line, str;
  char comma;
  while (std::getline(std::cin, line)) {
    lab::DataStruct data;
    std::stringstream input(line);
    input >> data.key1;
    if (!input.fail()) {
      input >> comma;
      if (!input.fail() && comma == ',') {
        input >> data.key2;
        if (!input.fail()) {
          input >> comma;
        }
      }
    }
    checkInput(data, comma, input);
//    if (input.fail() || abs(data.key1) > 5) {
//      throw std::invalid_argument("Invalid input\n");
//    }
//    input >> comma;
//    if (input.fail() || comma != ',') {
//      throw std::invalid_argument("Invalid input\n");
//    }
//    input >> data.key2;
//    if (input.fail() || abs(data.key2) > 5) {
//      throw std::invalid_argument("Invalid input\n");
//    }
//    input >> comma;
//    if (input.fail() || comma != ',') {
//      throw std::invalid_argument("Invalid input\n");
//    }
    if (!input.eof()) {
      input >> data.str;
    }
    vector.push_back(data);
  }
}

void lab::task()
{
  std::vector< lab::DataStruct > vector;
  read(vector);
  std::sort(vector.begin(), vector.end(), compare);
  print(vector, std::cout);
}
