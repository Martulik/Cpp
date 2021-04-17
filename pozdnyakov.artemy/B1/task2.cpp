#include "tasks.hpp"
#include <string>
#include <fstream>
#include "functions.hpp"

namespace poz
{
  void task2(char* argv[])
  {
    std::string fileName(argv[0]);
    std::ifstream fs;
    fs.open(fileName, std::ifstream::in);
    if (fs)
    {
      fs.seekg(0, fs.end);
      size_t length = fs.tellg();
      fs.seekg(0, fs.beg);
      char* buf = new char[length]; //make unique
      size_t read = 0;
      char c;
      while (read != length)
      {
        fs.get(c);
        buf[read] = c;
        read += fs.gcount();
      }
      std::vector<char> vector(&buf[0], &buf[length]);
      print(vector, std::cout);
    }

    fs.close();
  }
}
