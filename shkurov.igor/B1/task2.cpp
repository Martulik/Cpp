#include "tasks.hpp"

#include <fstream>

#include "functions.hpp"

namespace lab = shkurov;

void lab::taskTwo(const char* filename)
{
  std::ifstream file;
  file.open(filename);
  if (!file.is_open())
  {
    throw std::invalid_argument("No file found with such name.\n");
  }


  size_t length = 0;
  file.seekg(0, file.end);
  length = file.tellg();
  file.seekg(0, file.beg);


  // if (length == 0)
  // {
  //   throw std::length_error("File is empty.\n");
  // }
  std::cout << length;
  char* str = new char[length + 1];
  file.getline(str, length + 1);
  std::vector< char > vec(str, str + length);
  printContainer(vec, static_cast< char >(0));

  delete[] str;
}
