#include "tasks.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <memory>

#include "tools.hpp"

int murzakanov::task2(const char* fileName)
{
  std::ifstream input;
  input.open(fileName);
  if (!input.is_open())
  {
    std::cerr << "Error with opening\n";
    return 1;
  }
  int capacity = 512;
  int size = 0;
  std::unique_ptr< char[] > arr = std::make_unique< char[] >(capacity);
  while (!input.eof())
  {
    input.read(arr.get() + size, capacity - size);
    size += input.gcount();
    capacity *= 2;
    std::unique_ptr< char[] > temp = std::make_unique< char[] >(capacity);
    for (int i = 0; i < size; i++)
    {
      temp[i] = arr[i];
    }
    arr = std::move(temp);
  }

  input.close();
  std::vector< char > vec(arr.get(), arr.get() + size);
  for (int i = 0; i < size; i++)
  {
    std::cout << vec[i];
  }
  return 0;
}
