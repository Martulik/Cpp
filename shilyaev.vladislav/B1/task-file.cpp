#include "task-file.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
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
    return --size;
  }

  std::unique_ptr< char[] > read(std::ifstream &ifstream, size_t size)
  {
    std::unique_ptr< char[] > fileContent = std::make_unique< char[] >(size);

    seekBegin(ifstream);
    for (size_t i = 0; i < size && ifstream; i++) {
      ifstream.get(fileContent[i]);
    }
    return fileContent;
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
    const size_t size = countCharacters(ifstream);
    std::unique_ptr< char[] > fileContent = read(ifstream, size);
    ifstream.close();
    std::vector< char > vector(fileContent.get(), fileContent.get() + size);
    print(vector.begin(), vector.end(), "", "");
    return 0;
  }

}
