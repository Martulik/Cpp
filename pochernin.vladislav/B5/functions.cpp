#include "functions.hpp"

#include <cstring>
#include <cctype>
#include <cstdlib>
#include <algorithm>

int pochernin::getTaskNumber(const char* string)
{
  if (strlen(string) != 1)
  {
    return -1;
  }
  if (!std::isdigit(string[0]))
  {
    return -1;
  }
  int argument = std::atoi(string);
  if ((argument != 1) && (argument != 2))
  {
    return -1;
  }
  return argument;
}

bool pochernin::isNumber(const std::string& str)
{
  if (str.size() == 0)
  {
    return false;
  }
  else if ((str.size() == 1) && !std::isdigit(str[0]))
  {
    return false;
  }
  else
  {
    if ((str[0] != '-') && !std::isdigit(str[0]))
    {
      return false;
    }
    if (!std::all_of(str.begin() + 1, str.end(), ::isdigit))
    {
      return false;
    }
  }
  return true;
}

unsigned int pochernin::sumVertices(unsigned int sum, const Shape& shape)
{
  return sum + shape.size();
}

bool pochernin::isTriangle(const Shape& shape)
{
  return shape.size() == 3;
}

unsigned int pochernin::getSquaredSide(const Point& lhs, const Point& rhs)
{
  return ((rhs.x - lhs.x) * (rhs.x - lhs.x)) + ((rhs.y - lhs.y) * (rhs.y - lhs.y));
}

bool pochernin::isRectangle(const Shape& shape)
{
  if (shape.size() != 4)
  {
    return false;
  }

  std::vector< unsigned int > squaredSides;
  squaredSides.push_back(getSquaredSide(shape[0], shape[1]));
  squaredSides.push_back(getSquaredSide(shape[1], shape[2]));
  squaredSides.push_back(getSquaredSide(shape[2], shape[3]));
  squaredSides.push_back(getSquaredSide(shape[3], shape[0]));
  squaredSides.push_back(getSquaredSide(shape[0], shape[2]));
  squaredSides.push_back(getSquaredSide(shape[1], shape[3]));

  std::sort(squaredSides.begin(), squaredSides.end());
  return ((squaredSides[0] == squaredSides[1]) &&
          (squaredSides[2] == squaredSides[3]) &&
          (squaredSides[4] == squaredSides[5]));
}

bool pochernin::isSquare(const Shape& shape)
{
  if (shape.size() != 4)
  {
    return false;
  }

  std::vector< unsigned int > squaredSides;
  squaredSides.push_back(getSquaredSide(shape[0], shape[1]));
  squaredSides.push_back(getSquaredSide(shape[1], shape[2]));
  squaredSides.push_back(getSquaredSide(shape[2], shape[3]));
  squaredSides.push_back(getSquaredSide(shape[3], shape[0]));
  squaredSides.push_back(getSquaredSide(shape[0], shape[2]));
  squaredSides.push_back(getSquaredSide(shape[1], shape[3]));

  return ((squaredSides[0] == squaredSides[1]) &&
          (squaredSides[0] == squaredSides[2]) &&
          (squaredSides[0] == squaredSides[3]) &&
          (squaredSides[4] == squaredSides[5]));
}
