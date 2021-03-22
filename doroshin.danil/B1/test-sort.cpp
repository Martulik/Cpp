#include <boost/test/unit_test.hpp>
#include "insert-sort.hpp"
#include "sort-strategies.hpp"

namespace dan = doroshin;

BOOST_AUTO_TEST_SUITE(insert_sort)

BOOST_AUTO_TEST_CASE(vector_ix_empty)
{
  std::vector< int > empty;
  dan::insert_sort< int, dan::VectorIndexStrat< int >, dan::Ordering::ordering_op< dan::Ordering::Way::Ascending > >
      (empty, dan::VectorIndexStrat< int >::begin(empty), dan::VectorIndexStrat< int >::end(empty));
  BOOST_CHECK(empty == std::vector< int >{});
}

BOOST_AUTO_TEST_CASE(vector_ix_asc)
{
  std::vector< int > vec { 5, 7, 6, 1, 4, 3, 2 };
  dan::insert_sort< int, dan::VectorIndexStrat< int >, dan::Ordering::ordering_op< dan::Ordering::Way::Ascending > >
      (vec, dan::VectorIndexStrat< int >::begin(vec), dan::VectorIndexStrat< int >::end(vec));
  BOOST_CHECK(vec == (std::vector< int >{ 1, 2, 3, 4, 5, 6, 7 }));
}

BOOST_AUTO_TEST_CASE(vector_ix_desc)
{
  std::vector< int > vec { 5, 7, 6, 1, 4, 3, 2 };
  dan::insert_sort< int, dan::VectorIndexStrat< int >, dan::Ordering::ordering_op< dan::Ordering::Way::Descending > >
      (vec, dan::VectorIndexStrat< int >::begin(vec), dan::VectorIndexStrat< int >::end(vec));
  BOOST_CHECK(vec == (std::vector< int >{ 7, 6, 5, 4, 3, 2, 1 }));
}

BOOST_AUTO_TEST_CASE(vector_ix_eq)
{
  std::vector< int > vec { 1, 0, 0, 1, 1, 0, 0 };
  dan::insert_sort< int, dan::VectorIndexStrat< int >, dan::Ordering::ordering_op< dan::Ordering::Way::Ascending > >
      (vec, dan::VectorIndexStrat< int >::begin(vec), dan::VectorIndexStrat< int >::end(vec));
  BOOST_CHECK(vec == (std::vector< int >{ 0, 0, 0, 0, 1, 1, 1 }));
}

BOOST_AUTO_TEST_SUITE_END()
