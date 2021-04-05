#include <iostream>
#include "lab-exception.hpp"
#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include "task4.hpp"

namespace dan = doroshin;

template< typename T >
std::function< bool(T, T) > getOrder(std::string order)
{
  if(order == "ascending") {
    return std::less< T >();
  }
  else if(order == "descending") {
    return std::greater< T >();
  }
  else {
    throw dan::LabException("Invalid sorting order");
  }
}

template< typename T >
T readArg(std::string arg)
{
  T res;
  std::istringstream in (arg);
  in >> res;
  if(in.fail()) {
    throw dan::LabException("Invalid read");
  }
  in.get();
  if(!in.eof()) {
    throw dan::LabException("Extra symbols");
  }
  return res;
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
    if(std::cin.eof())
      break;
    if(std::cin.fail()) {
      throw dan::LabException("Incorrect input");
    }
    values.push_back(next);
  }
  return values;
}

int main(int argc, char* argv[])
{
  try {
    if(argc < 2) {
      throw dan::LabException("No task number");
    }
    const int task_num = readArg< int >(argv[1]);
    switch (task_num)
    {
    case 1:
      {
        if(argc < 3) {
          throw dan::LabException("No sorting order");
        }

        const std::function< bool(int, int) > cmp = getOrder< int >(argv[2]);
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
          throw dan::LabException("No filename");
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
          throw dan::LabException("No sorting order");
        }
        if(argc < 4) {
          throw dan::LabException("No array length");
        }
        const size_t size = readArg< size_t >(argv[3]);
        std::function< bool(double, double) > cmp = getOrder< double >(argv[2]);
        dan::testRandom(size, cmp);
      }
      break;
    default:
      throw dan::LabException("Unknown task");
    }
  }
  catch(const dan::LabException& e) {
    if(e.fatal()) {
      std::cerr << e.what() << '\n';
    }
    return e.fatal();
  }
  return 0;
}
