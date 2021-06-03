#include "tasks.hpp"

#include <iostream>
#include <iterator>
#include <algorithm>
#include "counter.hpp"
#include "functions.hpp"
#include "shape.hpp"

void ferapontov::task2(std::istream& in, std::ostream& out)
{
  std::istream_iterator< Shape > begin(in);
  std::istream_iterator< Shape > end;
  std::vector< Shape > shapes(begin, end);
  if (in.fail() && !in.eof())
  {
    throw std::runtime_error("Inavalid Input");
  }

  Counter count = std::for_each(shapes.begin(), shapes.end(), Counter());

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon), shapes.end());

  std::vector< Point > points;
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points), getVertex);

  sortShapes(shapes);

  out << count;

  out << "Points: ";
  std::copy(points.cbegin(), points.cend(), std::ostream_iterator< Point >(out, " "));
  out << "\nShapes:\n";
  std::copy(shapes.cbegin(), shapes.cend(), std::ostream_iterator< Shape >(out, "\n"));
}
