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
  auto numberOfVerticesForOneShape = std::bind(std::plus< size_t >(), _1, std::bind(lab::getNumberOfVertices(), _2));
  size_t numberOfVertices = std::accumulate(firstSh, lastSh, 0, numberOfVerticesForOneShape);
  out << "Vertices: " << numberOfVertices << "\n";

  int numberOfTriangles =  std::count_if(firstSh, lastSh, isTriangle);
  out << "Triangles: " << numberOfTriangles << "\n";
  int numberOfSquares = std::count_if(firstSh, lastSh, isSquare);
  out << "Squares: " << numberOfSquares << "\n";
  int numberOfRectangles = std::count_if(firstSh, lastSh, isRectangle);
  out << "Rectangles: " << numberOfRectangles<< "\n";

  std::vector< Shape >::iterator deleteOnes= std::remove_if(myShapes.begin(), myShapes.end(), isPentagon());
  myShapes.erase(deleteOnes, myShapes.end());

  std::vector< Point > firstPoitsofShapes = std::accumulate(myShapes.begin(), myShapes.end(), std::vector< Point >(), lab::addPoint());
  out << "Points: ";
  std::copy(firstPoitsofShapes.begin(), firstPoitsofShapes.end(), std::ostream_iterator< lysenko::Point >(out, " "));
  out << "\n";

  std::vector< Shape > sortedOne;
  out << "Shapes:" << "\n";
  /*std::for_each(myShapes.begin(), myShapes.end(), std::bind(lab::doSort(), sortedOne, _1, isTriangle));
  std::for_each(myShapes.begin(), myShapes.end(), std::bind(lab::doSort(), sortedOne, _1, isSquare));
  std::for_each(myShapes.begin(), myShapes.end(), std::bind(lab::doSort(), sortedOne, _1, isRectangle));*/
  //вставка в вектор фигур, которых там нет
  std::swap(sortedOne, myShapes);
  std::copy(myShapes.begin(), myShapes.end(), std::ostream_iterator< Shape >(out, "\n"));
}
