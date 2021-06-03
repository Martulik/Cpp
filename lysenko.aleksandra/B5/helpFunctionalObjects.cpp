#include "helpFunctionalObjects.h"

#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

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


  static std::vector< double > getSortedVectOfDistancesFromFirstPoint(const Shape& obj)
  {
    std::vector< double > distances;
    if (obj.size() == 4)
    {
      std::vector< double > trueDist(3);
      if (!((obj[0] == obj[1]) && (obj[0] == obj[2]) && (obj[0] == obj[3])))
      {
        trueDist[0] = getDistanceFromFirstPoint(obj, 1);
        trueDist[1] = getDistanceFromFirstPoint(obj, 2);
        trueDist[2] = getDistanceFromFirstPoint(obj, 3);

        std::stable_sort(trueDist.begin(), trueDist.end());
      }
      std::swap(distances, trueDist);
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
  bool isRectangle = ((!(distances.empty())) && (distances[2] == std::sqrt(std::pow(distances[0], 2) + std::pow(distances[1], 2))));
  if (isRectangle)
  {
    return (distances[0] == distances[1]);
  }
  return 0;
}

bool lysenko::isPentagon(const Shape& obj)
{
  return (obj.size() == 5);
}

bool lysenko::isTriangleOrSquareOrRectangle(const Shape& obj)
{
  return ((isTriangle(obj)) || (isRectangle(obj)));
}


bool lysenko::isNotTriangleOrSquareOrRectangle(const Shape& obj)
{
  return !(isTriangleOrSquareOrRectangle(obj));
}

void lysenko::shapeSort(std::vector< Shape >& vect)
{
  std::vector< Shape > sortedOne(vect);

  std::vector< Shape >::iterator def = std::remove_if(sortedOne.begin(), sortedOne.end(), (isNotTriangleOrSquareOrRectangle));
  sortedOne.erase(def, sortedOne.end());

  std::vector< Shape >::iterator spec = std::remove_if(vect.begin(), vect.end(), (isTriangleOrSquareOrRectangle));
  vect.erase(spec, vect.end());

  std::stable_sort(sortedOne.begin(),sortedOne.end());
  std::copy(vect.begin(), vect.end(), std::back_inserter(sortedOne));

  std::swap(sortedOne, vect);
}
