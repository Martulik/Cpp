#include <boost/test/unit_test.hpp>
#include "insert-sort.hpp"
#include "sort-strategies.hpp"

namespace dan = doroshin;

BOOST_AUTO_TEST_SUITE(insert_sort)

BOOST_AUTO_TEST_CASE(vector_ix_empty)
{
  std::vector< int > empty;
  dan::insert_sort< int, dan::VectorIndexStrat< int > >(empty);
  BOOST_CHECK(empty == std::vector< int >{});
}

BOOST_AUTO_TEST_CASE(vector_ix_asc)
{
  std::vector< int > vec { 5, 7, 6, 1, 4, 3, 2 };
  dan::insert_sort< int, dan::VectorIndexStrat< int > >(vec);
  BOOST_CHECK(vec == (std::vector< int >{ 1, 2, 3, 4, 5, 6, 7 }));
}

BOOST_AUTO_TEST_CASE(vector_ix_desc)
{
  std::vector< int > vec { 5, 7, 6, 1, 4, 3, 2 };
  dan::insert_sort< int, dan::VectorIndexStrat< int > >(vec, std::greater<>());
  BOOST_CHECK(vec == (std::vector< int >{ 7, 6, 5, 4, 3, 2, 1 }));
}

BOOST_AUTO_TEST_CASE(vector_at_asc)
{
  std::vector< int > vec { 5, 7, 6, 1, 4, 3, 2 };
  dan::insert_sort< int, dan::VectorAtStrat< int > >(vec);
  BOOST_CHECK(vec == (std::vector< int >{ 1, 2, 3, 4, 5, 6, 7 }));
}

BOOST_AUTO_TEST_CASE(list_it_asc)
{
  std::forward_list< int > vec { 5, 7, 6, 1, 4, 3, 2 };
  dan::insert_sort< int, dan::ListIterStrat< int > >(vec);
  BOOST_CHECK(vec == (std::forward_list< int >{ 1, 2, 3, 4, 5, 6, 7 }));
}

BOOST_AUTO_TEST_SUITE_END()
