#include "shape.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

std::istream& murzakanov::operator >>(std::istream& in, murzakanov::Shape& shp)
{
  std::string line;
  while (!getline(in, line))
  {
    return in;
  }
  std::istringstream lin(line);
  char bracketOp = '\0';
  char bracketClose = '\0';
  char semicolon = '\0';
  int x = 0;
  int y = 0;
  int n = 0;
  lin >> n;
  while (n != 0)
  {
    lin >> bracketOp >> x >> semicolon >> y >> bracketClose;
    n--;
    if (!lin || bracketOp != '(' || semicolon != ';' || bracketClose != ')')
    {
      std::cerr << "Invalid arguments\n";
      std::exit(1);
    }
    murzakanov::Point temp{ x, y };
    shp.push_back(temp);
  }
  return in;
}
