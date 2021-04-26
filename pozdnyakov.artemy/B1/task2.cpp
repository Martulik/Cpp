#include "tasks.hpp"
#include <string>
#include <fstream>
#include <stdexcept>
#include <memory>
#include "print.hpp"

namespace poz = pozdnyakov;

void poz::task2(char* argv[])
{
  std::string fileName(argv[0]);
  std::ifstream fs;
  fs.open(fileName, std::ifstream::in);
  if (!fs.is_open())
  {
    throw std::runtime_error("Incorrect file");
  }
  fs.seekg(0, fs.end);
  size_t length = fs.tellg();
  fs.seekg(0, fs.beg);
  std::unique_ptr< char[] > buf = std::make_unique< char[] >(length);
  size_t read = 0;
  char c;
  while (!fs.eof())
  {
    fs.get(c);
    buf[read] = c;
    read += fs.gcount();
  }
  std::vector<char> vector(buf.get(), buf.get() + length);
  poz::print(vector, std::cout);
  fs.close();
}
