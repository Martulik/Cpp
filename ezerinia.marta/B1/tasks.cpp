#include "tasks.hpp"

#include <fstream>
#include <vector>
#include <list>
#include <memory>

#include "tools.hpp"

namespace lab = ezerinia;

template< typename T >
void do_sort(typename T::container_t cont, int mode)
{
  lab::sort< T >(cont, T::begin(cont), T::end(cont), mode);
  lab::print(cont, std::cout);
}

void task1(const int sort_mode)
{
  std::vector< int > collection_numbers;
  int number = 0;
  while (std::cin >> number) {
    collection_numbers.push_back(number);
  }
  if ((std::cin.fail()) && (!std::cin.eof())) {
    std::cerr << "Wrong input";
  }

  std::vector< int > index(collection_numbers);
  do_sort< lab::indexVec< int>>(index, sort_mode);

  std::vector< int > at(collection_numbers);
  do_sort< lab::atVec< int>>(at, sort_mode);

  std::list< int > iter(collection_numbers.begin(), collection_numbers.end());
  do_sort< lab::iteratorList< int>>(iter, sort_mode);

}

void task2(const char *input)
{
  std::ifstream file;
  file.open(input);
  if (!file) {
    std::cerr << "Failure to open a file";
  }

  file.seekg(0, std::ios_base::end);
  int length = file.tellg();
  file.seekg(0);

  if (length == 0) {
    return;
  }

  std::unique_ptr< char[] > array(new char[length]);
  file.read(array.get(), length);
  file.close();

  std::vector< char > vec(array.get(), array.get() + length);
  lab::print(vec, std::cout);
}

void task3()
{
  std::vector< int > vec;
  int n = 1;
  while (n != 0) {
    std::cin >> n;
    if ((std::cin.eof() && !vec.empty()) || (!std::cin)) {
      std::cerr << "Zero not found\n";
      return;
    }
    vec.push_back(n);
  }

  if (!vec.empty()) {
    std::vector< int >::iterator iter = vec.begin();
    vec.pop_back();

    if (vec.back() == 1) {
      while (iter != vec.end()) {
        if (*iter % 2) {
          iter++;
        } else {
          vec.erase(iter);
        }
      }
    } else if (vec.back() == 2) {
      while (iter != vec.end()) {
        if (!(*iter % 3)) {
          iter = vec.insert(++iter, 3, 1);
          iter += 2;
        }
        iter++;
      }
    }
    //iter = vec.begin();

    lab::print(vec, std::cout);
  }
}

void task4(const int sort_mode, const int size)
{
  std::vector< double > vec(size);
  fillRandom(&vec[0], size);
  lab::print(vec, std::cout);
  do_sort< lab::indexVec< double > >(vec, sort_mode);
}
