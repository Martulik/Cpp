#include "tasks.hpp"
#include <algorithm>
#include "container.hpp"

void lebedeva::doTask2(std::ostream& out)
{
  Container cFactorial;
  std::ostream_iterator< Container::valueType > itOut(out, " ");

  std::copy(cFactorial.begin(), cFactorial.end(), itOut);
  out << '\n';
  std::reverse_copy(cFactorial.begin(), cFactorial.end(), itOut);
  out << '\n';
}
