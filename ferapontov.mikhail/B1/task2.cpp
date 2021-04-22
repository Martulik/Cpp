#include "tasks.hpp"

#include <iostream>
#include <fstream>
#include <memory>
#include "functions.hpp"

void ferapontov::task2(const std::string& file)
{
  std::ifstream in(file);

  if(!(in.is_open()))
  {
    std::cerr << "Can't open the file";
    std::exit(-1);
  }

  size_t capacity = 1024;
  size_t size = 0;
  std::unique_ptr< char[] > arr = std::make_unique< char[] >(capacity);

  while(!in.eof())
  {
    in.read(arr.get() + size, capacity - size);
    size += in.gcount();
    if(size == capacity)
    {
      capacity *= 2;
      std::unique_ptr< char[] > temp = std::make_unique< char[] >(capacity);
      for(size_t i = 0; i < size; i++)
      {
        temp[i] = arr[i];
      }
      std::swap(arr, temp);
    }
  }
  if(in.bad())
  {
    std::cerr << "Read error";
    in.close();
    std::exit(-1);
  }

  in.close();

  std::vector< char > vec(arr.get(), arr.get() + size);
  for(size_t i = 0; i < vec.size(); i++)
  {
    std::cout << vec[i];
  }
}
