#include "point.hpp"
#include <iostream>
#include <algorithm>

bool ferapontov::noWs::operator()(char a)
{
  return a == ' ';
}

std::istream& ferapontov::operator>>(std::istream& in, Point& point)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    std::string line;
    std::getline(in, line, ')');
    checkDelim(line, '(', in);
    int x = readNumber(line, in);;
    checkDelim(line, ';', in);
    int y = readNumber(line, in);
    skipWs(line, in);
    if(!in.fail())
    {
      point = {x, y};
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

void ferapontov::checkDelim(std::string& line, const char& delim, std::istream& err)
{
  skipWs(line, err);
  if (!err.fail())
  {
    std::string::iterator it = line.begin();
    if (*it != delim)
    {
      err.setstate(std::ios::badbit);
      return;
    }
    line.erase(line.begin(), ++it);
  }
}

int ferapontov::readNumber(std::string& line, std::istream& err)
{
  skipWs(line, err);
  if (!err.fail())
  {
    std::string number;
    std::string::iterator it = line.begin();
    if (*it == '+' || *it == '-' || isdigit(*it))
    {
      it = std::find_if_not(line.begin() + 1, line.end(), ::isdigit);
      number.insert(number.begin(), line.begin(), it);
      line.erase(line.begin(), it);
      return std::stoi(number);
    }
  }
  err.setstate(std::ios::badbit);
  return 0;
}

void ferapontov::skipWs(std::string& line, std::istream& err)
{
  if (!err.fail())
  {
    std::string::iterator it = std::find_if_not(line.begin(), line.end(), noWs());
    if (it != line.end())
    {
      if (*it == '\n')
      {
        err.setstate(std::ios::badbit);
        return;
      }
      line.erase(line.begin(), it);
    }
  }
}
