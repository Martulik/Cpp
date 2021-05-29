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
    int err = 0;
    checkDelim(line, '(', err);
    int x = readNumber(line, err);;
    checkDelim(line, ';', err);
    int y = readNumber(line, err);
    skipWs(line, err);
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
  skipWs(line, err);
  if (!err)
  {
    std::string::iterator it = line.begin();
    if (*it != delim)
    {
      err = 1;
      return;
    }
    line.erase(line.begin(), ++it);
    err = 0;
  }
}

int ferapontov::readNumber(std::string& line, int& err)
{
  skipWs(line, err);
  if (!err)
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
  err = 1;
  return 0;
}

void ferapontov::skipWs(std::string& line, int& err)
{
  if (!err)
  {
    std::string::iterator it = std::find_if_not(line.begin(), line.end(), noWs());
    if (it != line.end())
    {
      if (*it == '\n')
      {
        err = 1;
        return;
      }
      line.erase(line.begin(), it);
    }
  }
}
