#ifndef TASKS_HPP
#define TASKS_HPP

#include "tasks.hpp"

#include <iostream>
#include <vector>

#include "functions.hpp"
#include "shape.hpp"

void razukrantov::shapeTask(std::istream& in, std::ostream& out)
{
  std::vector< Shape > shapes;
  std::copy(std::istream_iterator< Shape >(in), std::istream_iterator< Shape >(), std::back_inserter(shapes));
  

}

#endif
