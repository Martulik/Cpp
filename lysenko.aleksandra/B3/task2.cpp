#include "tasks.h"

#include <iostream>
#include <algorithm>

#include "container.h"

int lysenko::task2(std::ostream& out)
{
  lysenko::Container factorial;

  std::copy(factorial.begin(), factorial.end(), std::ostream_iterator< size_t >(out, " "));
  out << '\n';

  std::reverse_copy(factorial.begin(), factorial.end(), std::ostream_iterator< size_t >(out, " "));
  out << '\n';

  return 0;
}
