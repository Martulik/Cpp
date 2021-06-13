#include "extra-task.hpp"

dushechkina::Shape dushechkina::generateFigure(std::mt19937& rand)
{
  std::uniform_int_distribution< int > coor(-10, 10);
  Point first{ coor(rand), coor(rand) };
  const int maxAbsCorr = 10;
  std::uniform_int_distribution< int > coorx(1, maxAbsCorr);
  std::uniform_int_distribution< int > coory(0, maxAbsCorr);
  std::uniform_int_distribution< int > coef(1, 3);
  int ax = coorx(rand);
  int ay = coory(rand);
  int k = coef(rand);
  Point fourth{ first.x + ax, first.y + ay};

  int xmin = ay;
  int ymin = ax;
  int xnod = xmin;
  int ynod = ymin;
  while (xnod != ynod)
  {
    if (xnod > ynod)
    {
      long tmp = xnod;
      xnod = ynod;
      ynod = tmp;
    }
    ynod = ynod - xnod;
  }
  xmin = xmin / xnod;
  ymin = ymin / ynod;

  Point second{ first.x - k * xmin, first.y + k * ymin };
  Point third{ second.x + ax, second.y + ay };

  Shape shape1 = {first, second, third, fourth};

  std::uniform_int_distribution< int > randPos(0, 3);
  int pos1 = randPos(rand);
  int pos2 = randPos(rand);
  while (pos1 == pos2)
  {
    pos2 = randPos(rand);
  }
  int pos3 = randPos(rand);
  while (pos1 == pos3 || pos2 == pos3)
  {
    pos3 = randPos(rand);
  }
  const int sumRandPos = 6;
  int pos4 = sumRandPos - pos1 - pos2 - pos3;

  std::swap(shape1[0], shape1[pos1]);
  std::swap(shape1[1], shape1[pos2]);
  std::swap(shape1[2], shape1[pos3]);
  std::swap(shape1[3], shape1[pos4]);

  return shape1;
}

bool dushechkina::isShapeNotSelfInter(const Shape& shape)
{
  int dx1 = shape[2].x - shape[1].x;
  int dy1 = shape[2].y - shape[1].y;
  int dx2 = shape[3].x - shape[0].x;
  int dy2 = shape[3].y - shape[0].y;
  int dx3 = shape[2].x - shape[3].x;
  int dy3 = shape[2].y - shape[3].y;
  int dx4 = shape[1].x - shape[0].x;
  int dy4 = shape[1].y - shape[0].y;

  if (dx1 == dx2 && dy1 == dy2 && dx3 == dx4 && dy3 == dy4)
  {
    return isRectangle(shape);
  }
  else
  {
    return !isRectangle(shape);
  }
}

dushechkina::Shape dushechkina::changeShapeSelfInter(Shape& shape)
{
  if (!isShapeNotSelfInter(shape))
  {
    int dx1 = shape[2].x - shape[1].x;
    int dy1 = shape[2].y - shape[1].y;
    int dx2 = shape[3].x - shape[0].x;
    int dy2 = shape[3].y - shape[0].y;

    if (dx1 != dx2 || dy1 != dy2)
    {
      std::swap(shape[2].x, shape[3].x);
      std::swap(shape[2].y, shape[3].y);
    }

    int dx3 = shape[2].x - shape[3].x;
    int dy3 = shape[2].y - shape[3].y;
    int dx4 = shape[1].x - shape[0].x;
    int dy4 = shape[1].y - shape[0].y;

    if (dx3 != dx4 || dy3 != dy4)
    {
      std::swap(shape[0].x, shape[3].x);
      std::swap(shape[0].y, shape[3].y);
    }
  }
  return shape;
}
