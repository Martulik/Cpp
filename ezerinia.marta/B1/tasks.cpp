#include "tasks.hpp"

#include <fstream>
#include <list>
#include <memory>

#include "tools.hpp"

namespace lab = ezerinia;

void task1(std::vector< int > collection_numbers, const int sort_mode)
{
  std::vector< int > index(collection_numbers);
  lab::do_sort< lab::indexVec< int > >(index, sort_mode);

  std::vector< int > at(collection_numbers);
  lab::do_sort< lab::atVec< int > >(at, sort_mode);

  std::list< int > iter(collection_numbers.begin(), collection_numbers.end());
  lab::do_sort< lab::iteratorList< int > >(iter, sort_mode);
}

void task2(const char *input)
{
  std::ifstream file;
  file.open(input);

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

void task3(std::vector< int > vec)
{

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

    lab::print(vec, std::cout);
  }
}

void task4(const int sort_mode, const int size)
{
  std::vector< double > vec(size);
  fillRandom(&vec[0], size);
  lab::print(vec, std::cout);
  lab::do_sort< lab::indexVec< double > >(vec, sort_mode);
}
