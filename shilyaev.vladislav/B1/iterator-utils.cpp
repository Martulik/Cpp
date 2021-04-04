#include "iterator-utils.hpp"

template <>
void print< char >(char t)
{
  std::cout << t;
}
