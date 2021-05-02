#include <boost/test/unit_test.hpp>
#include "insert-sort.hpp"
#include "sort-strategies.hpp"

namespace dan = doroshin;

BOOST_AUTO_TEST_SUITE(insert_sort)

BOOST_AUTO_TEST_CASE(empty)
{
  std::vector< int > empty;
  dan::insert_sort< int, dan::VectorIndexStrat >(empty);
  BOOST_CHECK(empty == std::vector< int >{});
}

BOOST_AUTO_TEST_CASE(single)
{
  std::vector< int > single { 3 };
  dan::insert_sort< int, dan::VectorIndexStrat >(single);
  BOOST_CHECK(single == std::vector< int >{ 3 });
}

BOOST_AUTO_TEST_CASE(vector_ix_asc)
{
  std::vector< int > vec { 6, 1, 2 };
  dan::insert_sort< int, dan::VectorIndexStrat >(vec);
  BOOST_CHECK(vec == (std::vector< int >{ 1, 2, 6 }));
}

BOOST_AUTO_TEST_CASE(vector_ix_desc)
{
  std::vector< int > vec { 6, 1, 2 };
  dan::insert_sort< int, dan::VectorIndexStrat >(vec, std::greater<>());
  BOOST_CHECK(vec == (std::vector< int >{ 6, 2, 1 }));
}

BOOST_AUTO_TEST_CASE(vector_at_asc)
{
  std::vector< int > vec { 6, 1, 2 };
  dan::insert_sort< int, dan::VectorAtStrat >(vec);
  BOOST_CHECK(vec == (std::vector< int >{ 1, 2, 6 }));
}

BOOST_AUTO_TEST_CASE(list_it_desc)
{
  std::forward_list< int > vec { 6, 1, 2 };
  dan::insert_sort< int, dan::ListIterStrat >(vec, std::greater<>());
  BOOST_CHECK(vec == (std::forward_list< int >{ 6, 2, 1 }));
}

BOOST_AUTO_TEST_SUITE_END()
