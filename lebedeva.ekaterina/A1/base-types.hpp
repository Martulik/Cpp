#ifndef BASE_TYPES_H
#define BASE_TYPES_H
struct point_t
{
  double x;
  double y;

  bool operator== (const point_t& point)
  {
    bool bResult = false;
    if ((this->x == point.x) && (this->y == point.y))
    {
      bResult = true;
    }
    return bResult;
  }
  bool operator != (const point_t& point)
  {
    bool bresult = true;
    if ((this->x == point.x) && (this->y == point.y))
    {
      bresult = false;
    }
	  return bresult;
  }
  friend std::ostream& operator <<(std::ostream& out, const point_t& point)
  {
    out << "(" << point.x << ", " << point.y << ")";
    return out;
  }
};

struct rectangle_t
{
  point_t pos;
  double width;
  double height;
  friend std::ostream& operator <<(std::ostream& out, const rectangle_t& figure)
  {
    out << "centred in " << figure.pos << ", scale: " << figure.height << " x " << figure.width;
    return out;
  }
};
#endif