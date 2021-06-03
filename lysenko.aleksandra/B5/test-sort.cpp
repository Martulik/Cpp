#include <boost/test/unit_test.hpp>

#include <numeric>

#include "Shape.h"
#include "helpFunctionalObjects.h"

namespace lysenko
{
  struct fillVect
  {
    std::vector< Shape > operator()(std::vector< Shape >& results, const Shape& res)
    {
      results.push_back(res);
      return results;
    }
  };
}

BOOST_AUTO_TEST_SUITE(testShapeSort)

BOOST_AUTO_TEST_CASE(testSort)
{
  namespace lab = lysenko;
  using shpVect = std::vector< lab::Shape >;
  shpVect inp = { {{1,1}, {1,2}, {2,1}, {2,2}},
                  {{4,5}, {5,4}, {6,6}, {7,8}, {9,10}, {2,7}},
                  {{9,8}, {3,9}, {3,1}, {3,1}, {3, 7}, {3, 5}, {8, 1}},
                  {{1,1}, {1,2}, {4,1}, {4,2}},
                  {{3,6}, {5,3}, {1,0}} };
  shpVect vect = std::accumulate(inp.begin(), inp.end(), shpVect(), lab::fillVect());
  lab::shapeSort(vect);

  shpVect sorted = { {{3,6}, {5,3}, {1,0}},
                     {{1,1}, {1,2}, {2,1}, {2,2}},
                     {{1,1}, {1,2}, {4,1}, {4,2}},
                     {{4,5}, {5,4}, {6,6}, {7,8}, {9,10}, {2,7}},
                     {{9,8}, {3,9}, {3,1}, {3,1}, {3, 7}, {3, 5}, {8, 1}} };
  BOOST_CHECK_EQUAL_COLLECTIONS(vect.begin(), vect.end(), sorted.begin(), sorted.end());
}

BOOST_AUTO_TEST_SUITE_END()
