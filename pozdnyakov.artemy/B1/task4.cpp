#include "tasks.hpp"
#include <random>
#include <string>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <functional>
#include "sort.hpp"
#include "strategies.hpp"
#include "print.hpp"

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
  std::string argAsc(argv[0]);
  std::string asc = "ascending";
  std::string desc = "descending";
  int len = std::stoi(std::string(argv[1]));
  double* array = new double[len];
  fillRandom(array, len);
  std::vector< double > vector(std::addressof(array[0]), std::addressof(array[len - 1]));
  poz::print(vector, std::cout);
  if (asc.compare(argAsc) == 0)
  {
    poz::sort< poz::VectorAtStrategy< double > >(vector, std::greater< double >());
  }
  else if (desc.compare(argAsc) == 0)
  {
    poz::sort< poz::VectorAtStrategy< double > >(vector, std::less< double >());
  }
  else
  {
    throw std::invalid_argument("Wrong argument");
  }
  poz::print(vector, std::cout);
}
