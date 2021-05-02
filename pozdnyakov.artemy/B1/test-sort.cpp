#include <random>
#include <limits>
#include <memory>
#include <algorithm>
#include <boost/test/unit_test.hpp>
#include "test-functions.hpp"
#include "sort.hpp"
#include "strategies.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_CASE(test_sort)
{
  std::vector< size_t > sizes{0, 1, 2, 3, 99};
  const double MIN = std::numeric_limits< double >::min();
  const double MAX = std::numeric_limits< double >::max();
  std::uniform_real_distribution< double > dis(MIN, MAX);
  std::random_device device;
  auto generator = [&dis, &device]()
  {
    return dis(device);
  };

  for (size_t size: sizes)
  {
    {
      std::vector< double > vector(size);
      std::generate(vector.begin(), vector.end(), generator);
      BOOST_TEST_MESSAGE("Testing std::vector< double > on " << size << " size with std::greater< double >: ");
      BOOST_REQUIRE(poz::testVectorSort(vector, std::greater< double >()));
      BOOST_TEST_MESSAGE("Testing std::vector< double > on " << size << " size with std::less< double >: ");
      BOOST_REQUIRE(poz::testVectorSort(vector, std::less< double >()));
    }
    {
      std::forward_list< double > list(size);
      std::generate(list.begin(), list.end(), generator);
      BOOST_TEST_MESSAGE("Testing std::list< double > on " << size << " size with std::greater< double >: ");
      BOOST_REQUIRE(poz::testListSort(list, std::greater< double >()));
      BOOST_TEST_MESSAGE("Testing std::list< double > on " << size << " size with std::less< double >: ");
      BOOST_REQUIRE(poz::testListSort(list, std::less< double >()));
    }
  }
}
