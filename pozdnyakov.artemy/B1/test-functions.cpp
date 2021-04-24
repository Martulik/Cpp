#include "test-functions.hpp"
#include "sort.hpp"
#include "strategies.hpp"

namespace poz = pozdnyakov;

bool poz::testVectorSort(std::vector< double > vector, poz::CompareFunc compare)
{
  bool result = true;
  std::vector< double > vIndex(vector);
  std::vector< double > vAt(vector);
  std::sort< poz::Viterator, CompareFunc >(vector.begin(), vector.end(), compare);
  sort< poz::IndexStrategy< double > >(vIndex, compare);
  sort< poz::VectorAtStrategy< double > >(vAt, compare);
  result &= poz::compareContainers< poz::Viterator >(vector.begin(), vector.end(), vIndex.begin(), vIndex.end());
  result &= poz::compareContainers< poz::Viterator >(vector.begin(), vector.end(), vAt.begin(), vAt.end());
  return result;
}

bool poz::testListSort(std::list< double > list, poz::CompareFunc compare)
{
  std::list< double > listStrat(list);
  list.sort< poz::CompareFunc >(compare);
  sort< poz::ListStrategy< double > >(listStrat, compare);
  return poz::compareContainers< poz::Literator >(list.begin(), list.end(), listStrat.begin(), listStrat.end());
}
