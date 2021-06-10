#include "tasks.hpp"
#include "functions.hpp"
#include "point.hpp"

void lebedeva::doTask2(std::istream& in, std::ostream& out)
{
  std::vector< Shape > shapes = doInputShapes(in);
  // do some counting shit
  doSomeOutput(out, shapes);
}
