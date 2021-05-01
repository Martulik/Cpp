#include <boost/test/unit_test.hpp>
#include <random>
#include <cstdlib>
#include <algorithm>
#include "sort.hpp"
#include "strategies.hpp"
#include "test-functions.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_SUITE(test_sort)

  using dvector = std::vector< double >;
  using dlist = std::forward_list< double >;

  BOOST_AUTO_TEST_CASE(empty_vector)
  {
    dvector vector(0);
    BOOST_REQUIRE(poz::testVectorSort(vector, std::greater< double >()));
    BOOST_REQUIRE(poz::testVectorSort(vector, std::less< double >()));
  }

  BOOST_AUTO_TEST_CASE(empty_list)
  {
    dlist list(0);
    BOOST_REQUIRE(poz::testListSort(list, std::greater< double >()));
    BOOST_REQUIRE(poz::testListSort(list, std::less< double >()));
  }

  BOOST_AUTO_TEST_CASE(vector_1_3)
  {
    for (int i = 0; i < 4; i++)
    {
      dvector vector(i);
      srand(time(0));
      std::generate(vector.begin(), vector.end(), rand);
      BOOST_REQUIRE(poz::testVectorSort(vector, std::greater< double >()));
      BOOST_REQUIRE(poz::testVectorSort(vector, std::less< double >()));
    }
  }

  BOOST_AUTO_TEST_CASE(list_1_3)
  {
    for (int i = 0; i < 4; i++)
    {
      dlist list(i);
      srand(time(0));
      std::generate(list.begin(), list.end(), rand);
      BOOST_REQUIRE(poz::testListSort(list, std::greater< double >()));
      BOOST_REQUIRE(poz::testListSort(list, std::less< double >()));
    }
  }
  BOOST_AUTO_TEST_CASE(vector_big)
  {
    dvector vector(99);
    srand(time(0));
    std::generate(vector.begin(), vector.end(), rand);
    BOOST_REQUIRE(poz::testVectorSort(vector, std::greater< double >()));
    BOOST_REQUIRE(poz::testVectorSort(vector, std::less< double >()));
  }

  BOOST_AUTO_TEST_CASE(list_big)
  {
    dlist list(99);
    srand(time(0));
    std::generate(list.begin(), list.end(), rand);
    BOOST_REQUIRE(poz::testListSort(list, std::greater< double >()));
    BOOST_REQUIRE(poz::testListSort(list, std::less< double >()));
  }

BOOST_AUTO_TEST_SUITE_END()
