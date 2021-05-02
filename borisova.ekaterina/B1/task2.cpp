#include "tasks.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <memory>

int borisova::doTask2(const int argc, char* argv[])
{
  if (argc != 3)
  {
    std::cerr << "Incorrect number of arguments";
    return 2;
  }
  char* name = argv[2];
  std::ifstream file;
  file.open(name);
  if (!file.is_open())
  {
    std::cerr << "File can't be open";
    return 1;
  }
  size_t step = 2;
  size_t count = 0;
  std::unique_ptr< char[] > mass = std::make_unique< char[] >(step);

  while (!file.eof())
  {
    file.read(mass.get() + count, step - count);
    count += file.gcount();
    step *= 2;
    std::unique_ptr< char[] > temp = std::make_unique< char[] >(step);

    for (size_t i = 0; i < count; i++)
    {
      temp[i] = std::move(mass[i]);
    }
    std::swap(temp, mass);
  }
  file.close();

  std::vector< char > vec(mass.get(), mass.get() + count);
  for (size_t i = 0; i < vec.size(); i++)
  {
    std::cout << vec[i];
  }
  return 0;
}
