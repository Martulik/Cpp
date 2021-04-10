#include "tasks.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <memory>

#include "tools.hpp"

int murzakanov::task2(std::string& fileName)
{
  std::ifstream input;
  input.open(fileName);
  if (!input.is_open())
  {
    std::cerr << "Error with opening\n";
    return 1;
  }
  int capacity = 128;
  int size = 0;
  std::unique_ptr< char[] > text = std::make_unique< char [] >(capacity);
  while (!input.eof())
  {
    input.read(&text[size], capacity - size);
    size += input.gcount();
    capacity *= 2;
    std::unique_ptr< char[] > temp = std::make_unique< char [] >(capacity);
    for (int i = 0; i < size; i++)
    {
      temp[i] = std::move(text[i]);
    }
    text = std::move(temp);
    input.close();
  }

  std::vector< char > vec(&text[0], &text[size]);
  for (size_t i = 0; i < vec.size(); i++)
  {
    std::cout << vec[i];
  }
  return 0;
}
