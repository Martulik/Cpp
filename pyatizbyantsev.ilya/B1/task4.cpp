#include "tasks.hpp"

#include "functions.hpp"

void pyatizbyantsev::taskFour(const char* cmp, int size)
{
  std::vector< double > vector(size);
  pyatizbyantsev::fillRandom(vector.data(), size);

  print< pyatizbyantsev::strategyAt< double > >(vector, std::cout, " ");
  sort< strategyAt< double > >(vector, sortMode< double >(cmp));
  print< pyatizbyantsev::strategyAt< double > >(vector, std::cout, " ");
}
