#include "task2.hpp"
#include <iostream>
#include <fstream>
#include "tools.hpp"

namespace lab = ezerinia;

int lab::task2(const char *input)
{
  std::ifstream file;
  file.open(input);
  if (!file) {
    std::cerr << "File does not exist\n";
    return 1;
  }

  if (file.peek() == EOF) {
    return 0;
  }

  size_t capacity = 5;
  size_t count = 0;
  std::unique_ptr< char[] > array = std::make_unique< char[] >(capacity);

  while (!file.eof()) {
    file.read(&array[count], capacity - count);
    count += file.gcount();
    capacity *= 2;
    std::unique_ptr< char[] > temp = std::make_unique< char[] >(capacity);
    for (size_t i = 0; i < count; i++) {
      temp[i] = std::move(array[i]);
    }
    std::swap(array, temp);
  }
  file.close();

  std::vector< char > vector(&array[0], &array[count]);
  for (size_t i = 0; i < count; i++) {
    std::cout << vector[i];
  }
  return 0;
}
