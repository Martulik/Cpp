#include "tasks.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include "container.hpp"

void lebedeva::doTask2(std::ostream& out)
{
  Container cFactorial;
  //using itOut = std::ostream_iterator< Container::valueType >;
  std::ostream_iterator< Container::valueType > itOut(out, " ");

  std::copy(cFactorial.begin(), cFactorial.end(), itOut/*(out, " ")*/);
  out << '\n';
  std::reverse_copy(cFactorial.begin(), cFactorial.end(), itOut/*(out, " ")*/);
  out << '\n';
}
