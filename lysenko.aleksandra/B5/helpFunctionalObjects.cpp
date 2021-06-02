#include "helpFunctionalObjects.h"

#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

namespace lysenko
{
  static int getDeltaFromFirstPoint(bool abscissa, const Shape& obj, const Point& pnt)
  {
    if (abscissa)
    {
      return pnt.x - obj[0].x;
    }
    return pnt.y - obj[0].y;
  }

  double getDistanceFromFirstPoint(const Shape& obj, const Point& pnt)
  {
    double deltaX = getDeltaFromFirstPoint(0, obj, pnt);
    double deltaY = getDeltaFromFirstPoint(1, obj, pnt);

    return std::sqrt(std::pow(deltaX, 2) + std::pow(deltaY, 2));
  }

  struct fillTheVector
  {
    int numb = 0;
    void operator()(const Shape& obj, const Point& pnt, std::vector< double >& dist)
    {
      double distance = getDistanceFromFirstPoint(obj, pnt);
      dist[numb] = distance;
      numb += 1;
    }
  };

  static std::vector< double > getSortedVectOfDistancesFromFirstPoint(const Shape& obj)
  {
    std::vector< double > distances(3);
    if (obj.size() == 4)
    {
      std::for_each(obj.begin() + 1, obj.end(), std::bind(fillTheVector(), obj, std::placeholders::_1, distances));
      std::stable_sort(distances.begin(), distances.end());
    }
    return distances;
  }
}

bool lysenko::isTriangle(const lysenko::Shape& obj)
{
  return (obj.size() == 3);
}

bool lysenko::isRectangle(const lysenko::Shape& obj)
{
  std::vector< double > distances = getSortedVectOfDistancesFromFirstPoint(obj);
  return (!(distances.empty()) && (distances[2] == std::sqrt(std::pow(distances[0], 2) + std::pow(distances[1], 2))));
}

bool lysenko::isSquare(const lysenko::Shape& obj)
{
  std::vector< double > distances = getSortedVectOfDistancesFromFirstPoint(obj);
  return ((isRectangle(obj)) && (distances[0] == distances[1]));

}

bool lysenko::isPentagon(const Shape& obj)
{
  return (obj.size() == 5);
}

void lysenko::shapeSort(std::vector< Shape >& vect)
{
  std::vector< Shape > sortedOne;

  std::copy_if(vect.begin(), vect.end(), std::back_inserter(sortedOne), isTriangle);
  std::vector< Shape >::iterator iter = std::remove_if(vect.begin(), vect.end(), isTriangle);
  vect.erase(iter, vect.end());

  std::copy_if(vect.begin(), vect.end(), std::back_inserter(sortedOne), isSquare);
  iter = std::remove_if(vect.begin(), vect.end(), isSquare);
  vect.erase(iter, vect.end());

  std::copy_if(vect.begin(), vect.end(), std::back_inserter(sortedOne), isRectangle);
  iter = std::remove_if(vect.begin(), vect.end(), isRectangle);
  vect.erase(iter, vect.end());

  std::copy(vect.begin(), vect.end(), std::back_inserter(sortedOne));

  std::swap(sortedOne, vect);
}
