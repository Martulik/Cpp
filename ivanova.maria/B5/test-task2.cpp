#include <sstream>
#include <boost/test/unit_test.hpp>
#include "task2.hpp"
#include <iterator>
#include <algorithm>
#include <numeric>
#include "point.hpp"
namespace iva = ivanova;

BOOST_AUTO_TEST_SUITE(testShapeIn)

  BOOST_AUTO_TEST_CASE(correctInput)
  {
    std::istringstream iss("4  (12; 36)  (3; -2225)  (-435; 8726) (0; -1)");
    iva::Shape shape;
    iss >> shape;
    BOOST_CHECK(shape.size() == 4);
    BOOST_CHECK_EQUAL(shape[0].x, 12);
    BOOST_CHECK_EQUAL(shape[0].y, 36);
    BOOST_CHECK_EQUAL(shape[1].x, 3);
    BOOST_CHECK_EQUAL(shape[1].y, -2225);
    BOOST_CHECK_EQUAL(shape[2].x, -435);
    BOOST_CHECK_EQUAL(shape[2].y, 8726);
    BOOST_CHECK_EQUAL(shape[3].x, 0);
    BOOST_CHECK_EQUAL(shape[3].y, -1);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testShapeOut)

  BOOST_AUTO_TEST_CASE(output)
  {
    std::ostringstream oss;
    iva::Shape shape{{12, 36},  {3, -2225},  {-435, 8726}, {0, -1}};
    oss << shape;
    BOOST_CHECK_EQUAL(oss.str(), "4 (12; 36) (3; -2225) (-435; 8726) (0; -1)");
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testTools)

  BOOST_AUTO_TEST_CASE(testShapes)
  {
    iva::Shape square{{12, 36}, {12, 48}, {0, 48}, {0, 36}};
    iva::Shape rectangle{{12, 36}, {12, 48}, {-2, 48}, {-2, 36}};
    iva::Shape triangle{{8, 12}, {3, 56}, {-34, 5}};
    iva::Shape pentagon{{43, 3}, {6, 12}, {8, -3}, {6, 4}, {40, -23}};
    BOOST_CHECK(iva::isRect(rectangle));
    BOOST_CHECK(iva::isSquare(square));
    BOOST_CHECK(iva::isTriangle(triangle));
    BOOST_CHECK(iva::isPentagon(pentagon));
  }

  BOOST_AUTO_TEST_CASE(testCompare)
  {
    iva::Shape square{{12, 36}, {12, 48}, {0, 48}, {0, 36}};
    iva::Shape rectangle{{12, 36}, {12, 48}, {-2, 48}, {-2, 36}};
    iva::Shape triangle{{8, 12}, {3, 56}, {-34, 5}};
    iva::Shape hexagon{{43, 3}, {6, 12}, {8, -3}, {6, 4}, {40, -23}, {3, 15}};
    BOOST_CHECK(iva::compare(triangle, square));
    BOOST_CHECK(iva::compare(triangle, rectangle));
    BOOST_CHECK(iva::compare(square, rectangle));
    BOOST_CHECK(iva::compare(square, hexagon));
  }

//  BOOST_AUTO_TEST_CASE(testCount)
//  {
//    iva::Shape square{{12, 36}, {12, 48}, {0, 48}, {0, 36}};
//    iva::Shape rectangle{{12, 36}, {12, 48}, {-2, 48}, {-2, 36}};
//    iva::count info;
//    info.countShape(square);
//    info.countShape(rectangle);
//    BOOST_CHECK(info.vertices == 8);
//    BOOST_CHECK(info.squares == 1);
//    BOOST_CHECK(info.rectangles == 2);
//  }

  BOOST_AUTO_TEST_CASE(testDelete)
  {
    std::vector < iva::Shape > vec;
    iva::Shape square{{12, 36}, {12, 48}, {0, 48}, {0, 36}};
    iva::Shape pentagon{{43, 3}, {6, 12}, {8, -3}, {6, 4}, {40, -23}};
    vec.push_back(square);
    vec.push_back(pentagon);
    std::vector < iva::Shape > tmp;
    std::for_each(vec.begin(), vec.end(), [&tmp](const iva::Shape &a){ if (!iva::isPentagon(a)) { tmp.push_back(a);}});
    vec.swap(tmp);
    BOOST_CHECK(vec.size() == 1);
  }

BOOST_AUTO_TEST_SUITE_END()
