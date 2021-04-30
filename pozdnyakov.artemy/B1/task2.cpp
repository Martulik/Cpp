#include "tasks.hpp"
#include <string>
#include <fstream>
#include <stdexcept>
#include <memory>
#include <vector>
#include "functions.hpp"

namespace poz = pozdnyakov;

void poz::task2(char* argv[])
{
  size_t len = 1000;
  std::string fileName(argv[0]);
  std::ifstream fs;
  fs.open(fileName, std::ifstream::in);
  if (!fs.is_open())
  {
    throw std::runtime_error("Incorrect file");
  }
  std::unique_ptr< char[] > arr = std::make_unique< char[] >(len);
  size_t read = 0;
  char c;
  while (!fs.eof())
  {
    if (read == len)
    {
      std::unique_ptr< char[] > buf = std::move(arr);
      arr = std::make_unique< char[] >(len * 2);
      for (size_t i = 0; i < len / 2; i++)
      {
        arr[i] = buf[i];
      }
      len *= 2;
    }
    fs.get(c);
    arr[read] = c;
    read += fs.gcount();
  }
  fs.close();
  if (read == 0)
  {
    return;
  }
  std::vector< char > vector(arr.get(), arr.get() + read);
  poz::print(vector, std::cout, "");
}
