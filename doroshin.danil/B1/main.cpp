#include <iostream>
#include "ArgumentParseException.hpp"
#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include "task4.hpp"

namespace dan = doroshin;

std::function< bool(int, int) > getOrder(std::string order)
{
  if(order == "ascending") {
    return std::less< int >();
  }
  else if(order == "descending") {
    return std::greater< int >();
  }
  else {
    throw ArgumentParseException("Invalid sorting order");
  }
}

int main(int argc, char* argv[])
{
  try {
    if(argc < 2) {
      throw ArgumentParseException("No task number");
    }
    const int task_num = argv[1][0] - '0';
    switch (task_num)
    {
    case 1:
      {
        if(argc < 3) {
          throw ArgumentParseException("No sorting order");
        }
        std::function< bool(int, int) > cmp = getOrder(argv[2]);

        std::vector< int > values;
        while(true) {
          int num;
          std::cin >> num;
          if(std::cin.eof())
            break;
          if(std::cin.fail()) {
            throw ArgumentParseException("Not a number");
          }
          values.push_back(num);
        }
        // std::forward_list< int > l_values(values.begin(), values.end());
        dan::doSort< dan::VectorIndexStrat< int > >(values, cmp);
        dan::doSort< dan::VectorAtStrat< int > >(values, cmp);
        // doSort< dan::ListIterStrat< int >, dan::Ordering::Way::Ascending >(l_values);
      }
      break;
    case 2:
      {
        if(argc < 3) {
          throw ArgumentParseException("No filename");
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
          throw ArgumentParseException("No sorting order");
        }
        if(argc < 4) {
          throw ArgumentParseException("No array length");
        }
        size_t size = atoll(argv[3]);
        std::function< bool(int, int) > cmp = getOrder(argv[2]);
        dan::testRandom(size, cmp);
      }
      break;
    default:
      throw ArgumentParseException("Unknown task");
    }
  }
  catch(const ArgumentParseException& parse_e) {
    std::cerr << parse_e.what() << '\n';
    return 1;
  }
  return 0;
}
