#include "vector-operations.hpp"

namespace poz
{
  void eraseEven(std::vector< int >& vector)
  {
    for (std::vector< int >::iterator i = vector.begin(); i != vector.end();)
    {
      if (*i % 2 == 0)
      {
        i = vector.erase(i);
      }
      else
      {
        i++;
      }
    }
  }

  void addOnes(std::vector< int >& vector)
  {
    for (std::vector< int >::iterator i = vector.begin(); i != vector.end();)
    {
      if (*i % 3 == 0)
      {
        i = vector.insert(std::next(i), 3, 1);
        i += 3;
      }
      else
      {
        i++;
      }
    }
  }
}
