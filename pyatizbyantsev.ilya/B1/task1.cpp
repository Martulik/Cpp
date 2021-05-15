#include "tasks.hpp"

#include "functions.hpp"
#include "strategies.hpp"

void pyatizbyantsev::taskOne(const char* cmp)
{
  std::vector< int > vectorFirst;

  int data;
  while (std::cin && !(std::cin >> data).eof())
  {
    if (std::cin.fail() || std::cin.bad())
    {
      throw std::invalid_argument("Incorrect input");
    }
    vectorFirst.push_back(data);
  }

  std::vector< int > vectorSecond(vectorFirst);
  std::forward_list< int > forwardList(vectorFirst.begin(), vectorFirst.end());

  sort< strategyIndex< int > >(vectorFirst, sortMode< int >(cmp));
  sort< strategyAt< int > >(vectorSecond, sortMode< int >(cmp));
  sort< strategyIterator< int > >(forwardList, sortMode< int >(cmp));
  print(vectorFirst.begin(), vectorFirst.end(), " ");
  print(vectorSecond.begin(), vectorSecond.end(), " ");
  print(forwardList.begin(), forwardList.end(), " ");
}
