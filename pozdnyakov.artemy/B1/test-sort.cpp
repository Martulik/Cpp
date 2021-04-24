#include <boost/test/unit_test.hpp>
#include "sort.hpp"
#include "strategies.hpp"
#include "test-functions.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_SUITE(test_sort)

  using dvector = std::vector< double >;
  using dlist = std::list< double >;

  BOOST_AUTO_TEST_CASE(empty_vector)
  {
    BOOST_REQUIRE(poz::testVectorSort(poz::makeRandomContainer< dvector >(0), std::greater< double >()) == true);
    BOOST_REQUIRE(poz::testVectorSort(poz::makeRandomContainer< dvector >(0), std::less< double >()) == true);
  }

  BOOST_AUTO_TEST_CASE(empty_list)
  {
    BOOST_REQUIRE(poz::testListSort(poz::makeRandomContainer< dlist >(0), std::greater< double >()) == true);
    BOOST_REQUIRE(poz::testListSort(poz::makeRandomContainer< dlist >(0), std::less< double >()) == true);
  }

  BOOST_AUTO_TEST_CASE(vector_1_3)
  {
    for (int i = 0; i < 4; i++)
    {
      BOOST_REQUIRE(poz::testVectorSort(poz::makeRandomContainer< dvector >(i), std::greater< double >()) == true);
      BOOST_REQUIRE(poz::testVectorSort(poz::makeRandomContainer< dvector >(i), std::less< double >()) == true);
    }
  }

  BOOST_AUTO_TEST_CASE(list_1_3)
  {
    for (int i = 0; i < 4; i++)
    {
      BOOST_REQUIRE(poz::testListSort(poz::makeRandomContainer< dlist >(i), std::greater< double >()) == true);
      BOOST_REQUIRE(poz::testListSort(poz::makeRandomContainer< dlist >(i), std::less< double >()) == true);
    }
  }
  BOOST_AUTO_TEST_CASE(vector_big)
  {
    BOOST_REQUIRE(poz::testVectorSort(poz::makeRandomContainer< dvector >(99), std::greater< double >()) == true);
    BOOST_REQUIRE(poz::testVectorSort(poz::makeRandomContainer< dvector >(99), std::less< double >()) == true);
  }

  BOOST_AUTO_TEST_CASE(list_big)
  {
    BOOST_REQUIRE(poz::testListSort(poz::makeRandomContainer< dlist >(99), std::greater< double >()) == true);
    BOOST_REQUIRE(poz::testListSort(poz::makeRandomContainer< dlist >(99), std::less< double >()) == true);
  }

BOOST_AUTO_TEST_SUITE_END()
