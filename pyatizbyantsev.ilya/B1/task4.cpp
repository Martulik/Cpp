#include "tasks.hpp"

#include "functions.hpp"

void pyatizbyantsev::taskFour(const char* cmp, int size)
{
  std::vector< double > vector(size);
  pyatizbyantsev::fillRandom(vector.data(), size);

  print(vector.begin(), vector.end(), " ");
  sort< strategyAt< double >, double >(vector, sortMode< double >(cmp));
  print(vector.begin(), vector.end(), " ");
}
