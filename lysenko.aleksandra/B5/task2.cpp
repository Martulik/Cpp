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
  auto numberOfVerticalsForOneShape = std::bind(std::plus< size_t >(), _1, std::bind(lab::getNumberOfVerticals(), _2));
  size_t numberOfVerticles = std::accumulate(firstSh, lastSh, 0, numberOfVerticalsForOneShape);
  out << "Verticles: " << numberOfVerticles << "\n";

  std::vector< int > numberOfTrianglesSquaresAndRectangles(3);
  std::for_each(firstSh, lastSh, std::bind(lab::checkIfAppropriateShape, numberOfTrianglesSquaresAndRectangles, _1));
  out << "Triangles: " << numberOfTrianglesSquaresAndRectangles[0] << "\n";
  out << "Squares: " << numberOfTrianglesSquaresAndRectangles[1] << "\n";
  out << "Rectangles: " << numberOfTrianglesSquaresAndRectangles[2] << "\n";

  std::for_each(myShapes.begin(), myShapes.end(), std::bind(lab::deletePentagons, myShapes, _1));

  std::vector< Point >firstPoitsofFigures = std::accumulate(myShapes.begin(), myShapes.end(), std::vector< Point >(), lab::addPoint());
  out << "Points: ";
  std::copy(firstPoitsofFigures.begin(), firstPoitsofFigures.end(), std::ostream_iterator< lysenko::Point >(out, " "));
  out << "\n";

  std::vector< Shape > sortedOne;
  out << "Shapes:" << "\n";
  std::for_each(myShapes.begin(), myShapes.end(), std::bind(lab::doSort, sortedOne, _1, &isTriangle));
  std::for_each(myShapes.begin(), myShapes.end(), std::bind(lab::doSort, sortedOne, _1, &isSquare));
  std::for_each(myShapes.begin(), myShapes.end(), std::bind(lab::doSort, sortedOne, _1, &isRectangle));
  std::swap(sortedOne, myShapes);
  std::copy(myShapes.begin(), myShapes.end(), std::ostream_iterator< Shape >(out, "\n"));
}
