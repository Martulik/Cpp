#include "tasks.hpp"
#include "sort.hpp"
#include "strategy.hpp"
#include "functions.hpp"

namespace fer = ferapontov;

template< typename T >
std::function< bool(T, T) > getSortMode(const std::string& mode)
{
  if(mode == "ascending")
  {
    return std::greater< T >();
  }
  if(mode == "descending")
  {
    return std::less< T >();
  }
  return nullptr;
}

void fer::task1(const std::string& mode)
{
  if(mode != "ascending" && mode != "descending")
  {
    std::cerr << "Invalid sorting mode";
    std::exit(-1);
  }

  int number = 0;
  std::vector< int > vec;
  while(std::cin >> number)
  {
    vec.push_back(number);
  }
  if(std::cin.fail() && !(std::cin.eof()))
  {
    std::cerr << "Read Error\n";
    std::exit(-1);
  }
  std::function< bool(int, int) > cmp = getSortMode< int >(mode);
  std::vector< int > second_vec(vec);
  std::forward_list< int > list(vec.begin(), vec.end());
  fer::sort< int, fer::index_access< int > >(vec, cmp);
  fer::sort< int, fer::at_access< int > >(second_vec, cmp);
  fer::sort< int, fer::iterator_access< int > >(list, cmp);
  print(vec);
  print(second_vec);
  print(list);
}