#include "tasks.hpp"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "shape.hpp"

void murzakanov::task2(std::istream& in, std::ostream& out)
{
  std::vector< murzakanov::Shape > shapes(std::istream_iterator< murzakanov::Shape >(in), std::istream_iterator< murzakanov::Shape >());
}
