#include "test-functions.hpp"

namespace poz = pozdnyakov;

std::vector< double > poz::makeVector()
{
  return std::vector< double >{1, 2, 3, 4, 5, 6};
}

std::list< double > poz::makeList()
{
  return std::list< double >{3, 4, 5, -9, 15};
}
