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

template< typename T >
std::vector< T > readUntilEof()
{
  std::vector< T > values;
  while(true) {
    if(std::cin.eof())
      break;

    T next;
    std::cin >> next;
    if(std::cin.fail()) {
      throw ArgumentParseException("Incorrect input");
    }
    values.push_back(next);
  }
  return values;
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

        const std::function< bool(int, int) > cmp = getOrder(argv[2]);
        const std::vector< int > values = readUntilEof< int >();
        const std::forward_list< int > l_values(values.begin(), values.end());

        dan::doSort< dan::VectorIndexStrat< int > >(values, cmp);
        dan::doSort< dan::VectorAtStrat< int > >(values, cmp);
        dan::doSort< dan::ListIterStrat< int > >(l_values, cmp);
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
