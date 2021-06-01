#include "helpFunctionalObjects.h"

#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

namespace lysenko
{
  static int getDeltaFromFirstPoint(bool abscissa, const lysenko::Shape& obj, size_t pointNumber)
  {
    if (pointNumber < obj.size())
    {
      if (abscissa)
      {
        return obj[pointNumber].x - obj[0].x;
      }
      return obj[pointNumber].y - obj[0].y;
    }
    throw std::out_of_range("Invalid parameters");
  }

  static double getDistanceFromFirstPoint(const lysenko::Shape& obj, int pointNumber)
  {
    return std::sqrt(pow(getDeltaFromFirstPoint(0, obj, pointNumber), 2) + pow(getDeltaFromFirstPoint(1, obj, pointNumber), 2));
  }

  static std::vector< double > getSortedVectOfDistancesFromFirstPoint(const lysenko::Shape& obj)
  {
    double distance01 = getDistanceFromFirstPoint(obj, 1);
    double distance02 = getDistanceFromFirstPoint(obj, 2);
    double distance03 = getDistanceFromFirstPoint(obj, 3);

    std::vector< double > distances{ distance01, distance02, distance03 };
    std::sort(distances.begin(), distances.end());

    return distances;
  }
}

bool lysenko::isTriangle(const lysenko::Shape& obj)
{
  return  (obj.size() == 3);
}

bool lysenko::isRectangle(const lysenko::Shape& obj)
{
  if (obj.size() == 4)
  {
    if ((obj[0] == obj[1]) && (obj[0] == obj[2]) && (obj[0] == obj[3]))
    {
      return 1;
    }

    std::vector< double > distances = getSortedVectOfDistancesFromFirstPoint(obj);

    return (distances[2] == std::sqrt(std::pow(distances[0], 2) + std::pow(distances[1], 2)));
  }
  return 0;
}

bool lysenko::isSquare(const lysenko::Shape& obj)
{
  if (obj.size() == 4)
  {
    if ((obj[0] == obj[1]) && (obj[0] == obj[2]) && (obj[0] == obj[3]))
    {
      return 1;
    }

    std::vector< double > distances = getSortedVectOfDistancesFromFirstPoint(obj);

    return ((distances[2] == std::sqrt(2) * std::abs(distances[0])) && (std::abs(distances[0]) == std::abs(distances[1])));
  }
  return 0;
}

bool lysenko::isNotTriangleOrSquareOrRectangle(const Shape& obj)
{
  return !(isTriangle(obj) || isRectangle(obj));
}

bool lysenko::isPentagon(const Shape& obj)
{
  return (obj.size() == 5);
}

void lysenko::shapeSort(std::vector< Shape >& vect)
{
  std::vector< Shape > sortedOne;
  std::vector< Shape > copy(vect);

  std::copy_if(copy.begin(), copy.end(), std::back_inserter(sortedOne), isTriangle);
  std::vector< Shape >::iterator iterT = std::remove_if(copy.begin(), copy.end(), isTriangle);
  copy.erase(iterT, copy.end());

  std::copy_if(copy.begin(), copy.end(), std::back_inserter(sortedOne), isSquare);
  std::vector< Shape >::iterator iter = std::remove_if(copy.begin(), copy.end(), isSquare);
  copy.erase(iter, copy.end());

  std::copy_if(copy.begin(), copy.end(), std::back_inserter(sortedOne), isRectangle);
  std::vector< Shape >::iterator iterR = std::remove_if(copy.begin(), copy.end(), isRectangle);
  copy.erase(iterR, copy.end());

  std::copy(copy.begin(), copy.end(), std::back_inserter(sortedOne));

  std::swap(sortedOne, vect);
}
