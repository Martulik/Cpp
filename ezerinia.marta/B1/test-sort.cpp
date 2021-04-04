#include <boost/test/unit_test.hpp>
#include "tools.hpp"

namespace lab = ezerinia;

std::vector< int > unsorted_collection{-10, 12, 43, -12, 23, 2, 0, 1, 12};
std::vector< int > ascending_sorted_collection{-12, -10, 0, 1, 2, 12, 12, 23, 43};
std::vector< int > descending_sorted_collection{43, 23, 12, 12, 2, 1, 0, -10, -12};
std::list< int > ascending_sorted_list(ascending_sorted_collection.begin(), ascending_sorted_collection.end());

const int ascending = 0;
const int descending = 1;

BOOST_AUTO_TEST_SUITE(sort)

  BOOST_AUTO_TEST_CASE(sort_vector_by_index)
  {
    std::vector< int > vec(unsorted_collection);
    lab::do_sort< lab::indexVec< int > >(vec, ascending);
    BOOST_CHECK(vec == ascending_sorted_collection);
  }

  BOOST_AUTO_TEST_CASE(sort_vector_by_at)
  {
    std::vector< int > vec(unsorted_collection);
    lab::do_sort< lab::atVec< int > >(vec, descending);
    BOOST_CHECK(vec == descending_sorted_collection);
  }

  BOOST_AUTO_TEST_CASE(sort_list)
  {
    std::list< int > list(unsorted_collection.begin(), unsorted_collection.end());
    lab::do_sort< lab::iteratorList< int > >(list, ascending);
    BOOST_CHECK(list == ascending_sorted_list);
  }

BOOST_AUTO_TEST_SUITE_END()
