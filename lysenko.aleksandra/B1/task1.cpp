#include "tasks.hpp"

int lysenko::task1(const char* order)
{
  if (std::cin.bad())
  {
    std::cerr << "Input error";
    return 1;
  }

  std::vector< int > myVect(1);
  int member = 0;

  while ((std::cin.good()) && (std::cin >> member))
  {
    if (std::cin.fail() || std::cin.bad())
    {
      std::cerr << "Input error";
      return 1;
    }
    myVect.push_back(member);
  }

  if (!(std::cin.eof()))
  {
    std::cerr << "Invalid input for task 1";
    return 1;
  }

  if (myVect.empty())
  {
    std::cerr << "Input sequence of integers can not be empty";
    return 1;
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

  return 0;
}
