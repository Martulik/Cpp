#include "tasks.hpp"

#include <algorithm>
#include <iterator>
#include <iostream>

#include "FactorialContainer.hpp"

namespace lab = shkurov;

void lab::task2(std::ostream& out)
{
  FactorialContainer cont;

  try
  {
    std::copy(cont.begin(), cont.end(), std::ostream_iterator< unsigned long >(out, " "));
    out << '\n';
    std::reverse_copy(cont.begin(), cont.end(), std::ostream_iterator< unsigned long >(out, " "));
    out << '\n';
  }
  catch (const std::exception& ex)
  {
    std::cerr << ex.what() << '\n';
  }
}
