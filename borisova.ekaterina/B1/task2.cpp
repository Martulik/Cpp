#include "tasks.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <memory>

void borisova::doTask2(const std::string& name)
{
  std::ifstream file;
  file.open(name);
  assert(file);
  size_t step = 2;
  size_t count = 0;
  std::unique_ptr< char[] > mass = std::make_unique< char[] >(step);

  while (file.peek() != EOF)
  {
    file >> mass[count];
    if (count + 1 == step)
    {
      step *= 2;
      std::unique_ptr< char[] > temp = std::make_unique< char[] >(step);
      for (size_t i = 0; i <= count; i++)
      {
        temp[i] = std::move(mass[i]);
      }
      std::swap(temp, mass);
    }
    count++;
  }

  file.close();
  std::vector< char > vec(mass.get(), mass.get() + count);
  for (size_t i = 0; i < vec.size(); i++)
  {
    std::cout << vec[i];
  }
}
