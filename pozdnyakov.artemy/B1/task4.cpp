#include "tasks.hpp"
#include <random>
#include <string>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <functional>
#include "sort.hpp"
#include "strategies.hpp"
#include "functions.hpp"

namespace poz = pozdnyakov;

void fillRandom(double* array, int len)
{
  std::uniform_real_distribution< double > dis(-1.0, 1.0);
  std::random_device device;
  for (int i = 0; i < len; i++)
  {
    array[i] = dis(device);
  }
}

void poz::task4(char* argv[])
{
  const char* ASC = "ascending";
  const char* DESC = "descending";
  int len = atoi(argv[1]);
  std::unique_ptr< double[] > array = std::make_unique< double[] >(len);
  fillRandom(array.get(), len);
  std::vector< double > vector(array.get(), array.get() + len);
  poz::print(vector, std::cout);
  if (!strcmp(ASC, argv[0]))
  {
    poz::sort< poz::VectorAtStrategy< double > >(vector, std::less< double >());
  }
  else if (!strcmp(DESC, argv[0]))
  {
    poz::sort< poz::VectorAtStrategy< double > >(vector, std::greater< double >());
  }
  else
  {
    throw std::invalid_argument("Wrong argument");
  }
  poz::print(vector, std::cout);
}
