#ifndef MATH_OBJECTS_HPP
#define MATH_OBJECTS_HPP

namespace savchuk
{
  struct Point;

  namespace math
  {
    class Vector
    {
      public:
        Vector(const Point& start, const Point& finish);

        Vector& operator+=(const Vector& other);

        friend int operator*(const Vector& lhs, const Vector& rhs);
        friend bool operator==(const Vector& lhs, const Vector& rhs);

      private:
        int x_;
        int y_;
    };

    int operator*(const Vector& lhs, const Vector& rhs);
    bool operator==(const Vector& lhs, const Vector& rhs);
    const Vector operator+(const Vector& lhs, const Vector& rhs);
  }
}

#endif
