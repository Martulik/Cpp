#include <iostream>
#include "insert-sort.hpp"
#include "sort-strategies.hpp"

namespace dan = doroshin;

template< typename Strat, dan::Ordering::Way order >
void doSort(typename Strat::container_t values)
{
  dan::insert_sort< int, Strat, dan::Ordering::ordering_op< order > >
      (values, Strat::begin(values), Strat::end(values));
  for(int num: values) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
}

int main(int argc, char* argv[])
{
  if(argc < 2) {
    std::cerr << "Provide the task number\n";
    return 0;
  }
  const int task_num = argv[1][0] - '0';
  switch (task_num)
  {
  case 1:
    {
      if(argc < 3) {
        std::cerr << "Provide a sorting order";
        return 0;
      }
      std::vector< int > values;
      while(!std::cin.eof()) {
        int num;
        std::cin >> num;
        if(std::cin.fail()) {
          std::cerr << "Not a number\n";
          return 0;
        }
        values.push_back(num);
      }
      // std::forward_list< int > l_values(values.begin(), values.end());
      std::string order = argv[1];
      if(order == "ascending") {
        doSort< dan::VectorIndexStrat< int >, dan::Ordering::Way::Ascending >(values);
        doSort< dan::VectorAtStrat< int >, dan::Ordering::Way::Ascending >(values);
        // doSort< dan::ListIterStrat< int >, dan::Ordering::Way::Ascending >(l_values);
      }
    }
    break;

  default:
    std::cerr << "Unknown task\n";
    break;
  }
  return 0;
}
