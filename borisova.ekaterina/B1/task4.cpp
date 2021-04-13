#include "tasks.hpp"
#include <vector>
#include "strategies.hpp"
#include "functions.hpp"

void borisova::doTask4(const std::string & mode, const int size)
{
  if (size < 0)
  {
    std::cerr << "Incorrect size\n";
  }
  std::vector< double >arr(size);
  fillRandom(std::addressof(arr[0]), size);
  print(arr, std::cout);
  std::vector< double > indVec(arr[0], size);
  sort< bracketStrategy< double > >(indVec, mode);
}
