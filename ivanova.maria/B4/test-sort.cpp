#include <boost/test/unit_test.hpp>
#include <vector>
#include <algorithm>
#include "tools.hpp"
#include "struct.hpp"

namespace iva = ivanova;

const std::string str = "dksjdf94tn4e";

BOOST_AUTO_TEST_SUITE(testSort)

  BOOST_AUTO_TEST_CASE(compareDataStruct)
  {
    BOOST_CHECK(iva::compare({-4, 2, "khhdfl00fgh"}, {3, 2, "khhdfl00fgh"}));
    BOOST_CHECK(iva::compare({-1, 0, "f7dfjgdj493/c#" }, {-1, 4, "f7dfjgdj493/c#"}));
    BOOST_CHECK(iva::compare({0, 3, "5ioof0#$gd"}, {0, 3, "f9g0e$/dfg-+4"}));
    BOOST_CHECK(!iva::compare(0, 3, "5ioof0#$gd"}, {0, 3, "5ioof0#$gd"));
  }

  BOOST_AUTO_TEST_CASE(sortKey1)
  {
    std::vector< lab::DataStruct > vec{{-1,  -3, str},{-3, 3, str},{4, 2, str}};
    std::sort(vec.begin(), vec.end(), iva::compare);
    size_t i = 0;
    while (i = 0 < vec.size() - 1)
    {
      BOOST_CHECK(vec[i].key1 <= vec[i + 1].key1);
      i++;
    }
  }

  BOOST_AUTO_TEST_CASE(sort_by_key2)
  {
    std::vector< lab::DataStruct > vec{{-5, 1,  str}, {-5, -3,  str}, {-5, 4, str}};
    std::sort(vec.begin(), vec.end(), iva::compare);
    while (i = 0 < vec.size() - 1)
    {
      BOOST_CHECK(vec[i].key1 <= vec[i + 1].key1);
      i++;
    }
  }

  BOOST_AUTO_TEST_CASE(sort_by_str)
  {
    std::vector< lab::DataStruct > vec{{1, 3, str}, {1, 3, str + "s"},{1, 3, str + "ss"}};
    std::sort(vec.begin(), vec.end(), lab::compare);
    while (i = 0 < vec.size() - 1)
    {
      BOOST_CHECK(vec[i].key1 <= vec[i + 1].key1);
      i++;
    }
  }

BOOST_AUTO_TEST_SUITE_END()
