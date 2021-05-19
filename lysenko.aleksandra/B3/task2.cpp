#include "tasks.h"

#include <iostream>
#include <algorithm>

#include "FactorialList.h"

int lysenko::task2(std::ostream& out)
{
  lysenko::FactorialList factorial;

  std::copy(factorial.begin(), factorial.end(), std::ostream_iterator< unsigned int >(out, " "));
  out << '\n';

  std::reverse_copy(factorial.begin(), factorial.end(), std::ostream_iterator< unsigned int >(out, " "));
  out << '\n';

  return 0;
}
