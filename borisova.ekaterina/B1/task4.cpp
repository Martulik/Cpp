#include "tasks.hpp"
#include <vector>
#include "strategies.hpp"
#include "functions.hpp"

int borisova::doTask4(const int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Incorrect number of arguments";
    return 2;
  }
  int size = 0;
  if (checkNumber(argv[3]))
  {
    size = std::atoi(argv[3]);
  }

  if (size <= 0)
  {
    std::cerr << "Incorrect size\n";
    return 1;
  }
  char* mode = argv[2];
  std::vector< double > arr(size);
  fillRandom(arr.data(), size);
  std::vector< double > indVec(arr);
  int exitCode = sort< bracketStrategy< double > >(indVec, sortMode< double >(mode));
  if (!exitCode)
  {
    print(arr, std::cout);
    print(indVec, std::cout);
  }
  return exitCode;
}
