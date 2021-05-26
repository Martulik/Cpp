#include "shape.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>

std::istream& ferapontov::operator>>(std::istream& in, Shape& vec)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    int size = 0;
    in >> std::ws >> size;
    vec.resize(size);
    Shape temp;
    std::copy_n(std::istream_iterator< Point >(in), vec.size(), std::back_inserter(temp));
    if (in.fail() && in.eof() && !temp.empty())
    {
      in.setstate(std::ios::badbit);
      return in;
    }
    if (in)
    {
      std::swap(vec, temp);
    }
  }
  return in;
}

std::ostream& ferapontov::operator<<(std::ostream& out, const Shape& vec)
{
  out << vec.size() << ' ';
  std::copy(vec.begin(), vec.end(), std::ostream_iterator< Point >(out, " "));
  return out;
}
