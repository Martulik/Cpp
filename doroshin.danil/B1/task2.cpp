#include "task2.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <stdexcept>

std::pair< std::unique_ptr< char[] >, size_t > read(std::ifstream& in)
{
  constexpr size_t chunk_len = 1024;
  size_t capacity = chunk_len;
  size_t size = 0;
  auto buffer = std::make_unique< char[] >(capacity);

  while(in.good()) {
    in.read(buffer.get() + size, chunk_len);
    auto temp = std::make_unique< char[] >(capacity + chunk_len);
    std::move(buffer.get(), buffer.get() + capacity, temp.get());
    std::swap(buffer, temp);
    capacity += chunk_len;
    size += in.gcount();
  }
  return { std::move(buffer), size };
}

void doroshin::task2(const char* filename)
{
  std::ifstream in(filename);
  if(!in.is_open()) {
    throw std::runtime_error("Could not open file");
  }
  std::pair< std::unique_ptr< char[] >, size_t > arr_len = read(in);
  std::unique_ptr< char[] > arr = std::move(arr_len.first);
  size_t len = arr_len.second;
  std::vector< char > v_buf(arr.get(), arr.get() + len);
  for(char c: v_buf) {
    std::cout << c;
  }
}
