#include "tasks.hpp"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <iterator>

#include "shape.hpp"

void murzakanov::task2(std::istream& in, std::ostream& out)
{
  std::istream_iterator< murzakanov::Shape > firstIterator(in);
  std::istream_iterator< murzakanov::Shape > lastIterator;
  std::vector< murzakanov::Shape > shapes(firstIterator, lastIterator);
  int vertices = 0;
  for (size_t i = 0; i < shapes.size(); i++)
  {
    vertices += shapes[i].size();
  }
  out << vertices << "\n";
}
