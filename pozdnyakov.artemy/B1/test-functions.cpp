#include "test-functions.hpp"
#include "sort.hpp"
#include "strategies.hpp"

namespace poz = pozdnyakov;

bool poz::testSort(std::vector< double > vector, std::list< double > list, poz::CompareFunc compare)
{
  using Viterator = typename std::vector< double >::iterator;
  using Literator = typename std::list< double >::iterator;
  std::vector< double > vectorIndex(vector);
  std::vector< double > vectorAt(vector);
  std::list< double > listStrat(list);
  std::sort< Viterator, CompareFunc >(vector.begin(), vector.end(), compare);
  sort< poz::IndexStrategy< double > >(vectorIndex, compare);
  sort< poz::VectorAtStrategy< double > >(vectorAt, compare);
  list.sort< CompareFunc >(compare);
  sort< poz::ListStrategy< double > >(listStrat, compare);
  poz::compareContainers< Viterator >(vector.begin(), vector.end(), vectorIndex.begin(), vectorIndex.end());
  poz::compareContainers< Viterator >(vector.begin(), vector.end(), vectorAt.begin(), vectorAt.end());
  poz::compareContainers< Literator >(list.begin(), list.end(), listStrat.begin(), listStrat.end());
  return true;
}
