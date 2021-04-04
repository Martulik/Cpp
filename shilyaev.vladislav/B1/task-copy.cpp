#include "task-copy.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "iterator-utils.hpp"

int taskCopy(int argc, char *argv[])
{
  if (argc != 3) {
    std::cerr << "Filename not specified";
    return 1;
  }
  std::string filename = argv[2];
  std::ifstream ifstream(filename);
  size_t size = 0;
  while (ifstream) {
    ifstream.get();
    size++;
  }
  ifstream.clear();
  ifstream.seekg(0, std::ios::beg);
  char fileContent[size];
  for (size_t i = 0; i < size; i++) {
    ifstream.get(fileContent[i]);
  }
  ifstream.close();

  std::vector< char > vector(fileContent, fileContent + size);

  print(vector.begin(), vector.end());

  return 0;
}
