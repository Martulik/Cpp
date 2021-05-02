#include "task-random.hpp"
#include <iostream>
#include <memory>
#include "random-tools.hpp"
#include "sort.hpp"
#include "iterator-print.hpp"
#include "compare-function.hpp"
#include "access-strategies.hpp"
#include "string-convert.hpp"

namespace shilyaev {
  int taskRandom(int argc, char *argv[])
  {
    if (argc != 4) {
      std::cerr << "Invalid arguments count";
      return 1;
    }
    using Item = double;
    using Compare = std::function< bool(Item, Item) >;
    boost::optional< Compare > compare = getCompareFunction< Item >(argv[2]);
    boost::optional< int > size = toNatural(argv[3]);
    if (!size || !compare || *size <= 0) {
      std::cerr << "Invalid arguments";
      return 1;
    }
    std::unique_ptr< Item[] > array = std::make_unique< Item[] >(*size);
    fillRandom(array.get(), *size);
    std::vector< Item > vector(array.get(), array.get() + *size);
    print(vector.cbegin(), vector.cend(), std::cout);
    bubbleSort< VectorBracketsStrategy< Item > >(vector, *compare);
    print(vector.cbegin(), vector.cend(), std::cout);
    return 0;
  }
}
