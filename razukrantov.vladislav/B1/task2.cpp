#include "tasks.hpp"
#include "functions.hpp"

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

void razukrantov::task2(const char* file)
{
  if (file == nullptr)
  {
	throw std::invalid_argument("Incorrect file");
  }
  std::ifstream input(file);
  if (!input)
  {
	throw (std::runtime_error("Open error"));
  }

  size_t capacity = 1;
  size_t size = 0;
  std::unique_ptr< char[] > data = std::make_unique< char[] >(capacity);

  while (input)
  {
	input.read(data.get() + size, capacity - size);
	size += input.gcount();
	if (size == capacity)
	{
	  capacity *= 2;
	  std::unique_ptr< char[] > temp = std::make_unique< char[] >(capacity);
	  for (size_t i = 0; i < size; i++)
	  {
		temp[i] = data[i];
	  }
	  data = std::move(temp);
	}
  }

  input.close();
  std::vector< char > vector(data.get(), data.get() + size);
  print(vector);
}
