#include "task-file.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "iterator-utils.hpp"

namespace shilyaev {
  const size_t INITIAL_CAPACITY = 1024;
  const size_t CAPACITY_INCREASE_FACTOR = 2;

  std::tuple< std::unique_ptr< char[] >, size_t > read(std::fstream &fstream)
  {
    size_t capacity = INITIAL_CAPACITY;
    std::unique_ptr< char[] > fileContent = std::make_unique< char[] >(capacity);
    size_t i = 0;
    while (fstream.get(fileContent[i++]).good()) {
      if (i == capacity) {
        capacity *= CAPACITY_INCREASE_FACTOR;
        std::unique_ptr< char[] > temp = std::make_unique< char[] >(capacity);
        for (size_t j = 0; j < i; j++) {
          temp[j] = fileContent[j];
        }
        fileContent = std::move(temp);
      }
    }
    return std::make_tuple(std::move(fileContent), i - 1);
  }

  int taskFile(int argc, char **argv)
  {
    if (argc != 3) {
      std::cerr << "Filename not specified";
      return 1;
    }
    std::string filename = argv[2];
    std::fstream fstream(filename);
    if (!fstream) {
      std::cerr << "File not open";
      return 1;
    }
    std::unique_ptr< char[] > fileContent;
    size_t size;
    std::tie(fileContent, size) = read(fstream);
    fstream.close();
    std::vector< char > vector(fileContent.get(), fileContent.get() + size);
    print(vector.begin(), vector.end(), "", "");
    return 0;
  }

}
