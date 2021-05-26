#include <sstream>
#include <boost/test/unit_test.hpp>
#include "task2.hpp"
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

  BOOST_AUTO_TEST_CASE(testCountVertices)
  {
    iva::Shape square{{12, 36}, {12, 48}, {0, 48}, {0, 36}};
    iva::Shape rectangle{{12, 36}, {12, 48}, {-2, 48}, {-2, 36}};
    iva::Shape triangle{{8, 12}, {3, 56}, {-34, 5}};
    iva::Shape hexagon{{43, 3}, {6, 12}, {8, -3}, {6, 4}, {40, -23}, {3, 15}};
    unsigned int count = 0;
    count = iva::countVertices(count, square);
    BOOST_CHECK_EQUAL(count, 4);
    count = iva::countVertices(count, rectangle);
    BOOST_CHECK_EQUAL(count, 8);
    count = iva::countVertices(count, triangle);
    BOOST_CHECK_EQUAL(count, 11);
    count = iva::countVertices(count, hexagon);
    BOOST_CHECK_EQUAL(count, 17);
  }

  BOOST_AUTO_TEST_CASE(testGetFront)
  {
    iva::Shape square{{12, 36}, {12, 48}, {0, 48}, {0, 36}};
    iva::Point p = iva::getFront(square);
    BOOST_CHECK(p.x == square[0].x);
    BOOST_CHECK(p.y == square[0].y);
  }

BOOST_AUTO_TEST_SUITE_END()
