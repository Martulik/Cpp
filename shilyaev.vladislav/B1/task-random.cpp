#include "task-random.hpp"
#include <iostream>
#include <random>
#include "sort.hpp"
#include "iterator-print.hpp"
#include "compare-function.hpp"
#include "access-strategies.hpp"
#include "string-convert.hpp"

namespace shilyaev {

  void fillRandom(double *array, int size)
  {
    std::uniform_real_distribution< double > distribution(-1.0, 1.0);
    std::random_device randomDevice;
    for (int i = 0; i < size; i++) {
      array[i] = distribution(randomDevice);
    }
  }

  int taskRandom(int argc, char *argv[])
  {
    if (argc != 4) {
      std::cerr << "Invalid arguments count";
      return 1;
    }
    using Item = double;
    using Compare = std::function< bool(Item, Item) >;
    boost::optional< Compare > compare = getCompareFunction< Item >(argv[2]);
    boost::optional< unsigned long > size = toNatural(argv[3]);
    if (!size || !compare || *size == 0) {
      std::cerr << "Invalid arguments";
      return 1;
    }
    Item array[*size];
    fillRandom(array, *size);
    std::vector< Item > vector(array, array + *size);
    print(vector.cbegin(), vector.cend());
    bubbleSort< VectorBracketsStrategy< Item > >(vector, *compare);
    print(vector.cbegin(), vector.cend());
    return 0;
  }

}
