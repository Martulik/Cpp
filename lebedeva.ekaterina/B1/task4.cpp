#include <vector>
#include "tasks.hpp"
#include "functions.hpp"

void lebedeva::doTask4(const int argc, char* argv[])
{
  lebedeva::checkNumOfArgs(argc, 4);

  int size = 0;
  if (isNumber(argv[3]))
  {
    size = std::atoi(argv[3]);
  }
  if (size <= 0)
  {
    throw std::invalid_argument("Invalid size\n");
  }

  std::vector< double > inVec(size);
  fillRandom(inVec.data(), size);
  std::vector< double > dVec(inVec);

  std::function< bool(double, double) > comp = getSortOrder< double >(argv[2]);
  sort< atAccess >(dVec, comp);

  print(inVec, std::cout, " ");
  print(dVec, std::cout, " ");
}
