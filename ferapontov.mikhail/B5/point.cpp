#include "point.hpp"
#include <iostream>
#include <algorithm>

bool ferapontov::skipWs::operator()(char a)
{
  return a == ' ';
}

bool ferapontov::isNumber::operator()(char a)
{
  return isdigit(a);
}

std::istream& ferapontov::operator>>(std::istream& in, Point& point)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    std::string line;
    std::getline(in, line, ')');
    int err = 0;
    checkDelim(line, '(', err);
    int x = readNumber(line, err);;
    checkDelim(line, ';', err);
    int y = readNumber(line, err);

    std::string::iterator it = std::find_if_not(line.begin(), line.end(), skipWs());
    line.erase(line.begin(), it);
    if (it != line.begin())
    {
      err = 1;
    }
    if(!err)
    {
      point = {x, y};
    }
    else
    {
      in.setstate(std::ios::badbit);
    }
  }
  return in;
}

std::ostream& ferapontov::operator<<(std::ostream& out, const Point& point)
{
  std::ostream::sentry sentry(out);
  if(sentry)
  {
    return out << '(' << point.x << "; " << point.y << ')';
  }
  return out;
}

void ferapontov::checkDelim(std::string& line, const char& delim, int& err)
{
  if (!err)
  {
    std::string::iterator it = std::find_if_not(line.begin(), line.end(), skipWs());
    if (it != line.end())
    {
      it = line.erase(line.begin(), it);
      if (*it != delim)
      {
        err = 1;
        return;
      }
      line.erase(line.begin(), ++it);
      err = 0;
      return;
    }
    err = 1;
  }
}

int ferapontov::readNumber(std::string& line, int& err)
{
  if (!err)
  {
    std::string::iterator it = std::find_if_not(line.begin(), line.end(), skipWs());
    if (it != line.end())
    {
      std::string number;
      it = line.erase(line.begin(), it);
      if (*it == '+' || *it == '-' || isdigit(*it))
      {
        it = std::find_if_not(line.begin() + 1, line.end(), isNumber());
        number.insert(number.begin(), line.begin(), it);
        line.erase(line.begin(), it);
        return std::stoi(number);
      }
    }
    err = 1;
  }
  return 0;
}
