#include "task-copy.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "iterator-utils.hpp"

namespace shilyaev {

  void seekBegin(std::ifstream &ifstream)
  {
    ifstream.clear();
    ifstream.seekg(0, std::ios::beg);
  }

  size_t countCharacters(std::ifstream &ifstream)
  {
    seekBegin(ifstream);
    size_t size = 0;
    while (ifstream) {
      ifstream.get();
      size++;
    }
    return size - 1;
  }

  void read(std::ifstream &ifstream, char *array, size_t size)
  {
    seekBegin(ifstream);
    for (size_t i = 0; i < size && ifstream; i++) {
      ifstream.get(array[i]);
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
    char fileContent[size];
    read(ifstream, fileContent, size);
    ifstream.close();
    std::vector< char > vector(fileContent, fileContent + size);
    print(vector.begin(), vector.end());
    return 0;
  }

}
