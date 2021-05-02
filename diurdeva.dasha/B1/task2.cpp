#include "tasks.hpp"
#include <fstream>
#include <vector>
#include <memory>
#include "tools.hpp"

void diurdeva::task2(const char *fileName, Error &err)
{
  std::ifstream inputStream(fileName);
  if (!inputStream) {
    err.set("Error reading file\n");
  }

  size_t count = 0;
  size_t capacity = 8;
  std::unique_ptr< char[] > arr = std::make_unique< char[] >(capacity);

  if (err.isError()) {
    while (!inputStream.eof()) {
      inputStream.read(arr.get() + count, capacity - count);
      capacity *= 2;
      count += inputStream.gcount();
      std::unique_ptr< char[] > temp = std::make_unique< char[] >(capacity);
      for (size_t i = 0; i < count; i++) {
        temp[i] = arr[i];
      }
      std::swap(arr, temp);
    }
    inputStream.close();

    std::vector< char > vector(arr.get(), arr.get() + count);
    for (size_t i = 0; i < count; i++) {
      std::cout << vector[i];
    }
  }
}
