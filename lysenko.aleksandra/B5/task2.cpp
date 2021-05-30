#include "tasks.h"

#include <vector>
#include <iterator>
#include <numeric>
#include <functional>
#include <algorithm>

#include "Shape.h"
#include "helpFunctionalObjects.h"


void lysenko::task2(std::istream&  in, std::ostream& out)
{
  namespace lab = lysenko;
  using namespace std::placeholders;
  std::istream_iterator< Shape > first(in);
  std::istream_iterator< Shape > last;
  std::vector< Shape > myShapes(first, last);

  std::vector< Shape >::iterator firstSh = myShapes.begin();
  std::vector< Shape >::iterator lastSh = myShapes.end();
  size_t numberOfVerticles = std::accumulate(firstSh, lastSh, 0, std::bind(std::plus< size_t >(),_1, std::bind(lab::getNumberOfVerticals(),_2)));

  int numberOfTriangles = std::accumulate(firstSh, lastSh, 0, std::bind(std::plus< size_t >(), _1, std::bind(lab::checkIsTriangle(), _2)));
  int numberOfSquares = std::accumulate(firstSh, lastSh, 0, std::bind(std::plus< size_t >(), _1, std::bind(lab::checkIsSquare(), _2)));
  int numberOfRectangles= std::accumulate(firstSh, lastSh, numberOfSquares, std::bind(std::plus< size_t >(), _1, std::bind(lab::checkIsRectangle(),_2)));
}