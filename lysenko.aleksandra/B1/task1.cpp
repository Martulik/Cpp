#include "tasks.hpp"

int lysenko::task1(const char* order)
{
  try
  {
    std::vector< int > myVect;
    int member = 0;

    while ((std::cin.good()) && (std::cin >> member))
    {
      if (std::cin.fail() || std::cin.bad())
      {
        throw std::invalid_argument("Input error");
      }
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
    std::vector< int > myVectCopy(myVect.begin(), myVect.end());

    lysenko::sortBubble< lysenko::strategyForIndex, std::vector< int > >(myVect, comparator);
    lysenko::sortBubble< lysenko::strategyForAt, std::vector< int > >(myVectCopy, comparator);
    lysenko::sortBubble< lysenko::strategyForIterator, std::forward_list< int > >(myList, comparator);

    lysenko::print< lysenko::strategyForIndex, std::vector< int > >(myVect, 1);
    lysenko::print< lysenko::strategyForAt, std::vector< int > >(myVectCopy, 1);
    lysenko::print< lysenko::strategyForIterator, std::forward_list< int > >(myList, 1);
  }

  catch (std::invalid_argument &err)
  {
    std::cerr << err.what();
    return 1;
  }

  return 0;
}
