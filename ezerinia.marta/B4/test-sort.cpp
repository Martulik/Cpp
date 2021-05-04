#include <boost/test/unit_test.hpp>
#include <vector>
#include <algorithm>
#include "tools.hpp"
#include "dataStruct.hpp"

namespace lab = ezerinia;

const std::string str = "str";

BOOST_AUTO_TEST_SUITE(sort)

  BOOST_AUTO_TEST_CASE(sort_by_key1)
  {
    std::vector< lab::DataStruct > vec{
      {1,  1, str},
      {-3, 4, str},
      {0,  5, str}
    };
    std::sort(vec.begin(), vec.end(), lab::compare);
    for (unsigned long i = 0; i < vec.size() - 1; i++) {
      BOOST_CHECK(vec[i].key1 <= vec[i + 1].key1);
    }
  }

  BOOST_AUTO_TEST_CASE(sort_by_key2)
  {
    std::vector< lab::DataStruct > vec{
      {0, 2,  str},
      {0, 0,  str},
      {0, -3, str},
    };
    std::sort(vec.begin(), vec.end(), lab::compare);
    for (unsigned long i = 0; i < vec.size() - 1; i++) {
      BOOST_CHECK(vec[i].key2 <= vec[i + 1].key2);
    }
  }

  BOOST_AUTO_TEST_CASE(sort_by_str)
  {
    std::vector< lab::DataStruct > vec{
      {0, 0, "1241h3b^&%%$43jn412"},
      {0, 0, "413&^%$ 2jn"},
      {0, 0, "4j32n4j j321n4jk jn213&*^89"},
    };
    std::sort(vec.begin(), vec.end(), lab::compare);
    for (unsigned long i = 0; i < vec.size() - 1; i++) {
      BOOST_CHECK(vec[i].str.length() <= vec[i + 1].str.length());
    }
  }

BOOST_AUTO_TEST_SUITE_END()