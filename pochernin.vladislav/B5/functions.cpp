#include "functions.hpp"

#include <cstring>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <array>

int pochernin::getTaskNumber(const char* string)
{
  if (std::strlen(string) != 1)
  {
    throw(std::invalid_argument("Incorrect argument (task number)"));
  }
  int argument = std::stoi(string);
  if ((argument != 1) && (argument != 2))
  {
    throw(std::invalid_argument("Incorrect argument (task number)"));
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

void pochernin::fillSquaredSideVector(std::array< unsigned int, 6 >& squaredSides, const Shape& shape)
{
  assert(shape.size() == 4);

  squaredSides[0] = (getSquaredSide(shape[0], shape[1]));
  squaredSides[1] = (getSquaredSide(shape[1], shape[2]));
  squaredSides[2] = (getSquaredSide(shape[2], shape[3]));
  squaredSides[3] = (getSquaredSide(shape[3], shape[0]));
  squaredSides[4] = (getSquaredSide(shape[0], shape[2]));
  squaredSides[5] = (getSquaredSide(shape[1], shape[3]));
}

bool pochernin::compareRectangleSides(const std::array< unsigned int, 6 >& sides)
{
  return (sides[0] == sides[1]) && (sides[2] == sides[3]) && (sides[4] == sides[5]);
}

bool pochernin::isRectangle(const Shape& shape)
{
  if (shape.size() != 4)
  {
    return false;
  }

  std::array< unsigned int, 6> squaredSides;
  fillSquaredSideVector(squaredSides, shape);

  std::sort(squaredSides.begin(), squaredSides.end());
  return compareRectangleSides(squaredSides);
}

bool pochernin::compareSquareSides(const std::array< unsigned int, 6 >& sides)
{
  assert(sides.size() == 6);

  return (sides[0] == sides[1]) && (sides[0] == sides[2]) && (sides[0] == sides[3]) && (sides[4] == sides[5]);
}

bool pochernin::isSquare(const Shape& shape)
{
  if (shape.size() != 4)
  {
    return false;
  }

  std::array< unsigned int, 6 > squaredSides;
  fillSquaredSideVector(squaredSides, shape);

  std::sort(squaredSides.begin(), squaredSides.end());
  return compareSquareSides(squaredSides);
}

bool pochernin::isPentagon(const Shape& shape)
{
  return shape.size() == 5;
}

pochernin::Point pochernin::getFirstPoint(const Shape& shape)
{
  assert(shape.size() > 0);

  return shape[0];
}

void pochernin::deleteExtraSpaces(std::string& str)
{
  std::string::iterator deleteFrom = std::remove(str.begin(), str.end(), ' ');
  str.erase(deleteFrom, str.end());
  deleteFrom = std::remove(str.begin(), str.end(), '\t');
  str.erase(deleteFrom, str.end());
}

void pochernin::sortShapes(std::vector< Shape >& shapes)
{
  std::vector< Shape > temp;

  std::copy_if(shapes.begin(), shapes.end(), std::back_inserter(temp), pochernin::isTriangle);
  std::vector< Shape >::iterator deleteFrom = std::remove_if(shapes.begin(), shapes.end(), pochernin::isTriangle);
  shapes.erase(deleteFrom, shapes.end());

  std::copy_if(shapes.begin(), shapes.end(), std::back_inserter(temp), pochernin::isSquare);
  deleteFrom = std::remove_if(shapes.begin(), shapes.end(), pochernin::isSquare);
  shapes.erase(deleteFrom, shapes.end());

  std::copy_if(shapes.begin(), shapes.end(), std::back_inserter(temp), pochernin::isRectangle);
  deleteFrom = std::remove_if(shapes.begin(), shapes.end(), pochernin::isRectangle);
  shapes.erase(deleteFrom, shapes.end());

  std::copy(shapes.begin(), shapes.end(), std::back_inserter(temp));

  shapes.swap(temp);
}

void pochernin::checkNoLineFeed(const std::string& str)
{
  if (str.find('\n') != str.npos)
  {
    throw(std::invalid_argument("Incorrect point reading"));
  }
}

int pochernin::readCoordinate(const std::string& str)
{
  return std::stoi(str);
}

int pochernin::getWeight(const Shape& shape)
{
  if (isTriangle(shape))
  {
    return 1;
  }
  else if (isSquare(shape))
  {
    return 2;
  }
  else if (isRectangle(shape))
  {
    return 3;
  }
  else
  {
    return 4;
  }
}
