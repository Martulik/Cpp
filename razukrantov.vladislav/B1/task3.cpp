#include "tasks.hpp"

#include <iostream>
#include <vector>

#include "functions.hpp"

void razukrantov::task3()
{
  std::vector< int > vector;
  int x = 0;
  while (std::cin >> x)
  {
    if (x == 0)
	{
	  break;
	}
	vector.push_back(x);
  }
  if (!std::cin.eof() && std::cin.fail())
  {
	throw(std::runtime_error("Incorrect input"));
  }
  if (x != 0)
  {
	throw(std::runtime_error("Incorrect end of input"));
  }
  if (vector.size() == 0)
  {
	return;
  }

  print(vector);
  std::vector< int >::iterator i = vector.begin();
  if (vector.back() == 1)
  {
	while (i != vector.end())
	{
	  if ((*i % 2) == 0)
	  {
		i = vector.erase(i);
	  }
	  else
	  {
		i++;
	  }
	}
  }
  else if (vector.back() == 2)
  {
	while (i != vector.end())
	{
	  if ((*i % 3) == 0)
	  {
		i = vector.insert(i + 1, 3, 1);
		i += 2;
	  }
	  else
	  {
		i++;
	  }
	}
  }

  print(vector);
}
