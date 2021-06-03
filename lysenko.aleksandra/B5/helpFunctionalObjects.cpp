#include "helpFunctionalObjects.h"

#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>

namespace lysenko
{
  static int getDeltaBetweenPoints(bool abscissa, const Point& firstPoint, const Point& secondPoint)
  {
    if (abscissa)
    {
      return firstPoint.x - secondPoint.x;
    }
    return firstPoint.y - secondPoint.y;
  }

  double getDistanceBetweenPoints(const Point& firstPoint, const Point& secondPoint)
  {
    int deltaX = getDeltaBetweenPoints(0, firstPoint, secondPoint);
    int deltaY = getDeltaBetweenPoints(1, firstPoint, secondPoint);

    return std::sqrt(std::pow(deltaX, 2) + std::pow(deltaY, 2));
  }

  static std::vector< double > getSortedVectOfDistancesFromFirstPoint(const Shape& obj)
  {
    namespace plc = std::placeholders;
    std::vector< double > distances;
    if (obj.size() == 4)
    {
      std::vector< double > trueDist(3);
      if (!((obj[0] == obj[1]) && (obj[0] == obj[2]) && (obj[0] == obj[3])))
      {
        auto fill = std::bind(fillTheVect(), plc::_1, std::bind(getDistanceBetweenPoints, obj[0], plc::_2));
        std::vector< double > trueDist = std::accumulate(obj.begin() + 1, obj.end(), std::vector< double >(), fill);

        std::stable_sort(trueDist.begin(), trueDist.end());
        std::swap(distances, trueDist);
      }
      else
      {
        std::vector< double > trueDist(3);
        std::swap(distances, trueDist);
      }
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
  if (!(distances.empty()))
  {
    return (distances[2] == std::sqrt((std::pow(distances[0], 2)) + (std::pow(distances[1], 2))));
  }
  return 0;
}

bool lysenko::isSquare(const lysenko::Shape& obj)
{
  std::vector< double > distances = getSortedVectOfDistancesFromFirstPoint(obj);
  if (!(distances.empty()))
  {
    bool isRectDist = (distances[2] == std::sqrt(std::pow(distances[0], 2) + std::pow(distances[1], 2)));
    return ((isRectDist) && (distances[0] == distances[1]));
  }
  return 0;
}

bool lysenko::isPentagon(const Shape& obj)
{
  return (obj.size() == 5);
}

void lysenko::shapeSort(std::vector< Shape >& vect)
{
  std::vector< Shape >::iterator it = std::partition(vect.begin(), vect.end(), isTriangle);
  std::vector< Shape >::iterator itS = std::partition(it, vect.end(), isSquare);
  std::partition(itS, vect.end(), isRectangle);
}
