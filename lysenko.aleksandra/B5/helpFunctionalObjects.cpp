#include "helpFunctionalObjects.h"

#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

namespace lysenko
{
  static int getDeltaFromFirstPoint(bool abscissa, const Shape& obj, const int& numberOfPoint)
  {
    if (abscissa)
    {
      return obj[numberOfPoint].x - obj[0].x;
    }
    return obj[numberOfPoint].y - obj[0].y;
  }

  double getDistanceFromFirstPoint(const Shape& obj, const int& numberOfPoint)
  {
    double deltaX = getDeltaFromFirstPoint(0, obj, numberOfPoint);
    double deltaY = getDeltaFromFirstPoint(1, obj, numberOfPoint);

    return std::sqrt(std::pow(deltaX, 2) + std::pow(deltaY, 2));
  }

  struct fillTheVector
  {
    void operator()(const Shape& obj, std::vector< double >& dist, int& numb)
    {
      double distance = getDistanceFromFirstPoint(obj, numb);
      dist[ numb - 1 ] = distance;
    }
  };

  static std::vector< double > getSortedVectOfDistancesFromFirstPoint(const Shape& obj)
  {
    std::vector< double > distances(3);
    if (obj.size() == 4)
    {
      std::vector< int >indexesOfPoints{ 1, 2, 3 };
      std::for_each(indexesOfPoints.begin(), indexesOfPoints.end(), std::bind(fillTheVector(), obj, distances, std::placeholders::_1));
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
  return ((!(distances.empty())) && (distances[2] == std::sqrt(std::pow(distances[0], 2) + std::pow(distances[1], 2))));
}

bool lysenko::isSquare(const lysenko::Shape& obj)
{
  std::vector< double > distances = getSortedVectOfDistancesFromFirstPoint(obj);
  bool isRectanle = ((!(distances.empty())) && (distances[2] == std::sqrt(std::pow(distances[0], 2) + std::pow(distances[1], 2))));
  return ((isRectangle) && (distances[0] == distances[1]));

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
