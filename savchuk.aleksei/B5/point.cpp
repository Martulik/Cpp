#include "point.hpp"

#include <iostream>
#include <algorithm>
#include <cctype>

namespace lab = savchuk;

namespace
{
  void skipSpaces(std::string& str, int& err);
  void readDelimiter(std::string& str, char delim, int& err);
  int readCoordinate(std::string& str, int& err);
}

std::istream& lab::operator>>(std::istream& is, Point& point)
{
  std::istream::sentry sentry(is);
  if (sentry)
  {
    std::string str;
    if (getline(is, str, ')'))
    {
      int err = 0;
      skipSpaces(str, err);
      readDelimiter(str, '(', err);
      int x = readCoordinate(str, err);
      readDelimiter(str, ';', err);
      int y = readCoordinate(str, err);
      skipSpaces(str, err);
      if (!err)
      {
        point = { x, y };
      }
      else
      {
        is.setstate(std::ios::failbit);
      }
    }
  }
  return is;
}

std::ostream& lab::operator<<(std::ostream& os, const Point& point)
{
  std::ostream::sentry sentry(os);
  if (sentry)
  {
    os << '(' << point.x << "; " << point.y << ')';
  }
  return os;
}

namespace
{
  struct CheckSpace
  {
    bool operator()(char ch)
    {
      return !isspace(ch) || ch == '\n';
    }
  };

  struct CheckNumber
  {
    bool hasSign_ = false;

    bool operator()(char ch)
    {
      if (isdigit(ch))
      {
        hasSign_ = true;
        return false;
      }
      else if (ch == '-' || ch == '+')
      {
        if (!hasSign_)
        {
          hasSign_ = true;
          return false;
        }
        return true;
      }
      return true;
    }
  };

  void skipSpaces(std::string& str, int& err)
  {
    if (!err)
    {
      auto it = std::find_if(str.begin(), str.end(), CheckSpace());
      if (it != str.end())
      {
        err = (*it == '\n');
        str.erase(str.begin(), it);
      }
    }
  }

  void readDelimiter(std::string& str, char delim, int& err)
  {
    if (!err)
    {
      skipSpaces(str, err);
      if (!err)
      {
        err = (str.empty() || str.front() != delim);
        if (!str.empty())
        {
          str.erase(str.begin(), ++str.begin());
        }
      }
    }
  }

  int readCoordinate(std::string& str, int& err)
  {
    std::string num;
    if (!err)
    {
      skipSpaces(str, err);
      if (!err)
      {
        auto it = std::find_if(str.begin(), str.end(), CheckNumber());
        num.insert(num.begin(), str.begin(), it);
        str.erase(str.begin(), it);
        err = num.empty();
      }
    }
    return std::atoi(num.c_str());
  }
}
