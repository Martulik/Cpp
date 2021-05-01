#include "test-functions.hpp"
#include "sort.hpp"
#include "strategies.hpp"
#include "vector-operations.hpp"

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

bool poz::testAddOnes(std::vector< int > vector)
{
  std::vector< int > vectorMod(vector);
  poz::addOnes(vectorMod);
  size_t endsTwo = 0;
  bool isOnes;
  bool result = true;
  for (size_t i; i < vector.size(); i++)
  {
    isOnes = vectorMod[i + endsTwo + 1] == 1 && vectorMod[i + endsTwo + 2] == 1 && vectorMod[i + endsTwo + 3] == 1;
    if (vector[i] % 10 == 2)
    {
      endsTwo += 3;
      result &= isOnes;
    }
  }
  return result;
}

bool poz::testEraseEven(std::vector< int > vector)
{
  return true;
}
