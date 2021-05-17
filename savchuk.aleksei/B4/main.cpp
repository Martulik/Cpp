#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <stdexcept>

#include "data-struct.hpp"
#include "comparator.hpp"

namespace lab = savchuk;

int main()
{
  try
  {
    std::istream_iterator< lab::DataStruct > first(std::cin);
    std::istream_iterator< lab::DataStruct > last;
    std::vector< lab::DataStruct > v(first, last);
    std::sort(v.begin(), v.end(), lab::compare);
    std::copy(v.begin(), v.end(), std::ostream_iterator< lab::DataStruct >(std::cout, "\n"));
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << e.what() << '\n';
    return 2;
  }
  catch (...)
  {
    std::cerr << "Internal program error\n";
    return 2;
  }
}
