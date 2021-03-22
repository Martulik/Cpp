#include <iostream>
#include <iomanip>
#include <random>
#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"

namespace dan = doroshin;

void fillRandom(double* array, size_t size)
{
  std::random_device rd;
  std::default_random_engine gen(rd());
  std::uniform_real_distribution< double > dist(-1.0, 1.0);

  for(size_t i = 0; i < size; ++i) {
    array[i] = dist(gen);
  }
}

template< dan::Ordering::Way Order >
void testRandom(const size_t size)
{
  std::unique_ptr< double[] > array = std::make_unique< double[] >(size);
  double* raw_ptr = array.get();
  fillRandom(raw_ptr, size);
  std::cout << std::fixed << std::setprecision(5);
  for(size_t i = 0; i < size; ++i) {
    std::cout << array[i] << ' ';
  }
  std::cout << '\n';
  dan::insert_sort< double, dan::ArrayPtrStrat< double >, dan::Ordering::ordering_op< Order > >
      (raw_ptr, raw_ptr, raw_ptr + size);
  for(size_t i = 0; i < size; ++i) {
    std::cout << array[i] << ' ';
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
      std::vector< int > values;
      do {
        int num;
        std::cin >> num;
        if(std::cin.fail()) {
          std::cerr << "Not a number\n";
          return 0;
        }
        values.push_back(num);
      } while(!std::cin.eof());
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
        testRandom< dan::Ordering::Way::Ascending >(size);
      }
      else if (order == "descending") {
        testRandom< dan::Ordering::Way::Descending >(size);
      }
    }
    break;
  default:
    std::cerr << "Unknown task\n";
    break;
  }
  return 0;
}
