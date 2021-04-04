#include "task-copy.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "iterator-utils.hpp"

size_t countCharacters(std::istream &istream)
{
  size_t size = 0;
  while (istream) {
    istream.get();
    size++;
  }
  return size;
}

void read(std::istream &istream, char *array, size_t size)
{
  for (size_t i = 0; i < size; i++) {
    istream.get(array[i]);
  }
}

int taskCopy(int argc, char *argv[])
{
  if (argc != 3) {
    std::cerr << "Filename not specified";
    return 1;
  }
  std::string filename = argv[2];
  std::ifstream ifstream(filename);
  if (!ifstream) {
    std::cerr << "File not open";
    return 1;
  }
  const size_t size = countCharacters(ifstream);
  ifstream.clear();
  ifstream.seekg(0, std::ios::beg);
  char fileContent[size];
  read(ifstream, fileContent, size);
  ifstream.close();
  std::vector< char > vector(fileContent, fileContent + size);
  print(vector.begin(), vector.end());
  return 0;
}
