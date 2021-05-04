#include "tasks.hpp"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "shape.hpp"

void murzakanov::task2(std::istream& in, std::ostream& out)
{
  std::vector< murzakanov::Shape > shapes;
  while (!in.eof())
  {
    murzakanov::Shape temp;
    in >> temp;
    shapes.push_back(temp);
  }
  out << "1";
}
