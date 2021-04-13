#include "tasks.hpp"
#include <vector>
#include "strategies.hpp"
#include "functions.hpp"

int borisova::doTask4(const std::string & mode, const int size)
{
  if (size < 0)
  {
    std::cerr << "Incorrect size\n";
    return 1;
  }
  std::vector< double >arr(size);
  fillRandom(std::addressof(arr[0]), size);
  print(arr, std::cout);
  std::vector< double > indVec(arr);
  sort< bracketStrategy< double > >(indVec, mode);
  print(indVec, std::cout);
  return 0;
}
