#include <fstream>
#include <functional>
#include <iostream>
#include <vector>

#include "tasks.hpp"
#include "functions.hpp"

void dushechkina::task3()
{
  std::vector< int > vector;
  int element = 0;
  while (std::cin >> element)
  {
    if (element == 0)
    {
      break;
    }
    vector.push_back(element);
  }
  if (element != 0)
  {
    throw std::runtime_error("Last element must be 0");
  }
  if (!std::cin.eof() && std::cin.fail())
  {
    throw std::runtime_error("Incorrect input");
  }
  if (vector.empty())
  {
    return;
  }
  auto iterator = vector.begin();
  switch (vector.back())
  {
  case 1:
    while (iterator != vector.end())
    {
      if (*iterator % 2 == 0)
      {
        iterator = vector.erase(iterator);
      }
      else iterator++;
    }
    break;
  case 2:
    while (iterator != vector.end())
    {
      if (*iterator % 3 == 0)
      {
        iterator = vector.insert(iterator + 1, 3, 1) + 3;
      }
      else iterator++;
    }
    break;
  default:
    break;
  }
  dushechkina::print(vector, " ");
}
