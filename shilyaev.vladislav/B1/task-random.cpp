#include "task-random.hpp"
#include <iostream>
#include <random>
#include "sort.hpp"
#include "iterator-utils.hpp"
#include "order-strategies.hpp"
#include "access-strategies.hpp"

void fillRandom(double *array, int size)
{
  std::uniform_real_distribution< double > distribution(-1.0, 1.0);
  std::random_device randomDevice;
  for (int i = 0; i < size; i++) {
    array[i] = distribution(randomDevice);
  }
}

int shilyaev::taskRandom(int argc, char *argv[])
{
  if (argc != 4) {
    std::cerr << "Invalid arguments count";
    return 1;
  }
  const std::string orderParameter = argv[2];
  const size_t size = std::atoi(argv[3]);
  if (size == 0) {
    std::cerr << "Invalid size";
    return 1;
  }
  double array[size];
  fillRandom(array, size);
  std::vector< double > vector(array, array + size);
  shilyaev::print(vector.begin(), vector.end());
  if (orderParameter == "ascending") {
    shilyaev::bubbleSort< shilyaev::VectorBracketsStrategy< double >, shilyaev::AscendingOrder >(vector);
  } else if (orderParameter == "descending") {
    shilyaev::bubbleSort< shilyaev::VectorBracketsStrategy< double >, shilyaev::DescendingOrder >(vector);
  } else {
    std::cerr << "Invalid sorting order";
    return 1;
  }
  shilyaev::print(vector.begin(), vector.end());
  return 0;
}
