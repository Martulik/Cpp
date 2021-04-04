#include "iterator-utils.hpp"

template <>
void shilyaev::print< char >(char t)
{
  std::cout << t;
}
