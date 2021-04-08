#include "task-file.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "iterator-utils.hpp"

namespace shilyaev {

  size_t countCharacters(std::fstream &fstream)
  {
    fstream.seekg(0,std::ios_base::end);
    return fstream.tellg();
  }

  std::unique_ptr< char[] > read(std::fstream &fstream, size_t size)
  {
    fstream.seekg(0,std::ios_base::beg);
    std::unique_ptr< char[] > fileContent = std::make_unique< char[] >(size);
    fstream.read(fileContent.get(), size);
    return fileContent;
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
    const size_t size = countCharacters(fstream);
    std::unique_ptr< char[] > fileContent = read(fstream, size);
    fstream.close();
    std::vector< char > vector(fileContent.get(), fileContent.get() + size);
    print(vector.begin(), vector.end(), "", "");
    return 0;
  }

}
