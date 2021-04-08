#include "task-file.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "iterator-utils.hpp"

namespace shilyaev {
  const size_t INITIAL_CAPACITY = 1024;
  const size_t CAPACITY_INCREASE_FACTOR = 2;

  std::tuple< std::unique_ptr< char[] >, size_t > read(std::ifstream &ifstream)
  {
    size_t capacity = INITIAL_CAPACITY;
    std::unique_ptr< char[] > fileContent = std::make_unique< char[] >(capacity);
    size_t size = 0;
    while (ifstream.good()) {
      ifstream.read(fileContent.get() + size, capacity - size);
      size += ifstream.gcount();
      capacity *= CAPACITY_INCREASE_FACTOR;
      std::unique_ptr< char[] > temp = std::make_unique< char[] >(capacity);
      for (size_t j = 0; j < size; j++) {
        temp[j] = fileContent[j];
      }
      fileContent = std::move(temp);
    }
    return std::make_tuple(std::move(fileContent), size);
  }

  int taskFile(int argc, char **argv)
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
    std::unique_ptr< char[] > fileContent;
    size_t size;
    std::tie(fileContent, size) = read(ifstream);
    ifstream.close();
    std::vector< char > vector(fileContent.get(), fileContent.get() + size);
    print(vector.begin(), vector.end(), "", "");
    return 0;
  }

}
