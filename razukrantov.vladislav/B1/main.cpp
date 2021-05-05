#include <iostream>
#include <stdexcept>

#include "tasks.hpp"

int main(int argc, char* argv[])
{
  try
  {
	if ((argc < 2) || (argc > 4))
	{
	  throw(std::invalid_argument("Incorrect arguments"));
	}
	switch (atoi(argv[1]))
	{
	case 1:
	  if (argc != 3)
	  {
		throw(std::invalid_argument("Incorrect arguments count"));
	  }
	  razukrantov::task1(argv[2]);
	  break;
	case 2:
	  if (argc != 3)
	  {
		throw(std::invalid_argument("Incorrect arguments count"));
	  }
	  razukrantov::task2(argv[2]);
	  break;
	case 3:
	  if (argc != 2)
	  {
		throw(std::invalid_argument("Incorrect arguments count"));
	  }
	  razukrantov::task3();
	  break;
	default:
	  throw(std::invalid_argument("incorrect number of task"));
	  break;
	}
  }
  catch (std::exception& err)
  {
	std::cerr << err.what() << "\n";
	return 1;
  }
  return 0;
}
