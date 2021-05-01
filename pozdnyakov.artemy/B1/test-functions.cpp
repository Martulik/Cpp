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
  result &= vector == vIndex;
  result &= vector == vAt;
  return result;
}

bool poz::testListSort(std::forward_list< double > list, poz::CompareFunc compare)
{
  std::forward_list< double > listStrat(list);
  list.sort< poz::CompareFunc >(compare);
  sort< poz::ListStrategy< double > >(listStrat, compare);
  return list == listStrat;
}
