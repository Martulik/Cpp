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

  std::unique_ptr< char[] > str(std::make_unique< char[] >(length));
  file.read(str.get(), length);
  std::vector< char > vec(str.get(), str.get() + length);
  printContainer(vec, static_cast< char >(0));
}
