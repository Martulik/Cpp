#include "tasks.hpp"

int lysenko::task1(const char* order)
{
  std::vector< int > myVect;
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
