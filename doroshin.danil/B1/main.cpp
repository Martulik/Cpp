#include <iostream>
#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include "task4.hpp"

namespace dan = doroshin;

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
      std::vector< int > values;
      while(true) {
        int num;
        std::cin >> num;
        if(std::cin.eof())
          break;
        if(std::cin.fail()) {
          std::cerr << "Not a number\n";
          return 0;
        }
        values.push_back(num);
      }
      // std::forward_list< int > l_values(values.begin(), values.end());
      if(argc < 3) {
        std::cerr << "Provide a sorting order";
        return 0;
      }
      std::string order = argv[2];
      if(order == "ascending") {
        dan::doSort< dan::VectorIndexStrat< int >, dan::Ordering::Way::Ascending >(values);
        dan::doSort< dan::VectorAtStrat< int >, dan::Ordering::Way::Ascending >(values);
        // doSort< dan::ListIterStrat< int >, dan::Ordering::Way::Ascending >(l_values);
      }
      else if(order == "descending") {
        dan::doSort< dan::VectorIndexStrat< int >, dan::Ordering::Way::Descending >(values);
        dan::doSort< dan::VectorAtStrat< int >, dan::Ordering::Way::Descending >(values);
        // doSort< dan::ListIterStrat< int >, dan::Ordering::Way::Descending >(l_values);
      }
    }
    break;
  case 2:
    {
      if(argc < 3) {
        std::cerr << "Provide a filename";
        return 0;
      }
      std::string filename = argv[2];
      dan::readFile(filename);
    }
    break;
  case 3:
    dan::filterInput();
    break;
  case 4:
    {
      if(argc < 3) {
        std::cerr << "Provide a sorting order";
        return 0;
      }
      std::string order = argv[2];
      if(argc < 4) {
        std::cerr << "Provide an array length";
        return 0;
      }
      size_t size = atoll(argv[3]);
      if(order == "ascending") {
        dan::testRandom< dan::Ordering::Way::Ascending >(size);
      }
      else if (order == "descending") {
        dan::testRandom< dan::Ordering::Way::Descending >(size);
      }
    }
    break;
  default:
    std::cerr << "Unknown task\n";
    break;
  }
  return 0;
}
