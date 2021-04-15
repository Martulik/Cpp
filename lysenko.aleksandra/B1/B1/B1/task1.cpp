#include "tasks.hpp"

#include <vector>
#include <forward_list>

#include "comparator.hpp"

int lysenko::task1(const char* order)
{
  try
  {
    std::vector< int > myVect;
    int member = 0;

    while ((std::cin.good()) && (std::cin >> member))
    {
      myVect.push_back(member);
    }

    if (!(std::cin.eof()))
    {
      throw std::invalid_argument("Invalid input for task 1");
    }

    if (myVect.empty())
    {
      throw std::invalid_argument("Input sequence of integers can not be empty");
    }

    bool (*comparator)(const int&, const int&) = getComparator< int >(order);
    
    std::forward_list< int > myList(myVect.begin(), myVect.end());
  }
  catch (std::invalid_argument &err)
  {
    std::cerr << err.what();
    return 1;
  }
  return 0;
}