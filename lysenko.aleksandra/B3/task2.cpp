#include "tasks.h"

#include <iostream>
#include <algorithm>

#include "container.h"


int lysenko::task2()
{
  lysenko::Container factorial;

  std::copy(factorial.begin(), factorial.end(), std::ostream_iterator< size_t >(std::cout, " "));
  std::cout << '\n';

  std::reverse_copy(factorial.begin(), factorial.end(), std::ostream_iterator< size_t >(std::cout, " "));
  std::cout << '\n';

  return 0;
}