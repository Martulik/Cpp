#include "tasks.hpp"
#include <string>
#include <fstream>
#include <stdexcept>
#include <memory>
#include "print.hpp"

namespace poz = pozdnyakov;

void poz::task2(char* argv[])
{
  const int LENGTH = 1000;
  std::string fileName(argv[0]);
  std::ifstream fs;
  fs.open(fileName, std::ifstream::in);
  if (!fs.is_open())
  {
    throw std::runtime_error("Incorrect file");
  }
  std::unique_ptr< char[] > buf = std::make_unique< char[] >(LENGTH);
  size_t read = 0;
  char c;
  while (!fs.eof() || read == LENGTH)
  {
    fs.get(c);
    buf[read] = c;
    read += fs.gcount();
  }
  fs.close();
  if (read == 0)
  {
    throw std::runtime_error("Empty file");
  }
  std::vector<char> vector(buf.get(), buf.get() + read);
  poz::print(vector, std::cout);
}
