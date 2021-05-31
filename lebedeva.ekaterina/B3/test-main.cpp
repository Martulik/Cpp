#define BOOST_TEST_MODULE testmain
#include <boost/test/included/unit_test.hpp>
#include "container.hpp"
#include "test-functions.hpp"

namespace lebedeva
{
  void checkEqualAfterMoving(std::unique_ptr< Interface >& src, std::string markname, int n);
}

void lebedeva::checkEqualAfterMoving(std::unique_ptr< Interface >& src, std::string markname, int n)
{
  lebedeva::Interface::constIter temp = src->find(markname);
  std::string temp1 = (*temp->second).phoneNumber + " " + (*temp->second).name;
  BOOST_CHECK_EQUAL(lebedeva::moveMark(src, n), true);
  temp = src->find(lebedeva::cur);
  std::string temp2 = (*temp->second).phoneNumber + " " + (*temp->second).name;
  BOOST_CHECK(temp1 == temp2);
}

BOOST_AUTO_TEST_SUITE(testInterface)

BOOST_AUTO_TEST_CASE(emptyInterface)
{
  std::unique_ptr< lebedeva::Interface > empInt = lebedeva::makeEmptyInterface();
  BOOST_CHECK_EQUAL(empInt->empty(), true);
  BOOST_CHECK_EQUAL(lebedeva::insertRec(empInt), false);
  BOOST_CHECK_EQUAL(empInt->find(lebedeva::markname1) == empInt->end(), true);
  BOOST_CHECK_EQUAL(lebedeva::storeRec(empInt), false);
  BOOST_CHECK_EQUAL(empInt->find(lebedeva::newmarkname1) == empInt->end(), true);
  BOOST_CHECK_EQUAL(lebedeva::moveMark(empInt, lebedeva::posStep), false);
  BOOST_CHECK_EQUAL(empInt->find(lebedeva::markname1) == empInt->end(), true);
  BOOST_CHECK_EQUAL(lebedeva::deleteMark(empInt), false);
  BOOST_CHECK_EQUAL(empInt->empty(), true);
}

BOOST_AUTO_TEST_CASE(oneElementInterface)
{
  std::unique_ptr< lebedeva::Interface > obj = lebedeva::makeEmptyInterface();
  lebedeva::addRec(obj);
  BOOST_CHECK(obj->begin() != obj->end());
  BOOST_CHECK_EQUAL(obj->empty(), false);
  BOOST_CHECK(obj->find(lebedeva::markname1) == obj->end());
  BOOST_CHECK_EQUAL(lebedeva::storeRec(obj), true);
  BOOST_CHECK(obj->find(lebedeva::markname1) != obj->end());
  BOOST_CHECK_EQUAL(lebedeva::moveMark(obj, lebedeva::zeroStep), true);
  BOOST_CHECK(obj->find(lebedeva::markname1) != obj->end());
  BOOST_CHECK_EQUAL(lebedeva::deleteMark(obj), true);
  BOOST_CHECK_EQUAL(obj->empty(), true);
}

BOOST_AUTO_TEST_CASE(twoElementsInterface)
{
  std::unique_ptr< lebedeva::Interface > obj = lebedeva::makeEmptyInterface();
  lebedeva::addRec(obj);
  lebedeva::addRec(obj);
  BOOST_CHECK_EQUAL(lebedeva::storeRec(obj), true);
  BOOST_CHECK_EQUAL(lebedeva::storeRec(obj), true);
  BOOST_CHECK(obj->find(lebedeva::markname2) != obj->end());
  lebedeva::Interface::constIter temp = obj->find(lebedeva::cur);
  BOOST_CHECK_EQUAL(lebedeva::moveMark(obj, lebedeva::posStep), true);
  BOOST_CHECK_EQUAL(lebedeva::moveMark(obj, lebedeva::negStep), true);
  BOOST_CHECK(temp == obj->find(lebedeva::cur));
  lebedeva::checkEqualAfterMoving(obj, lebedeva::markname2, lebedeva::commandLast);
  lebedeva::checkEqualAfterMoving(obj, lebedeva::markname1, lebedeva::commandFirst);
  BOOST_CHECK_EQUAL(lebedeva::deleteMark(obj), true);
  BOOST_CHECK_EQUAL(lebedeva::deleteMark(obj), true);
  BOOST_CHECK_EQUAL(obj->empty(), true);
}

BOOST_AUTO_TEST_CASE(threeElementsInterface)
{
  std::unique_ptr< lebedeva::Interface > obj = lebedeva::makeEmptyInterface();
  lebedeva::addRec(obj);
  BOOST_CHECK_EQUAL(lebedeva::storeRec(obj), true);
  BOOST_CHECK_EQUAL(lebedeva::insertRec(obj), true);
  BOOST_CHECK_EQUAL(lebedeva::storeRec(obj), true);
  BOOST_CHECK_EQUAL(lebedeva::insertRec(obj), true);
  BOOST_CHECK_EQUAL(lebedeva::storeRec(obj), true);
  lebedeva::checkEqualAfterMoving(obj, lebedeva::markname1, lebedeva::commandFirst);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testContainer)
BOOST_AUTO_TEST_CASE(factorialTest)
{
  lebedeva::Container factContainer;
  using Type = lebedeva::Container::valueType;
  using iter = lebedeva::Container::Iterator;
  Type elem = 1;
  Type factorial = 1;

  for (iter i = factContainer.begin(); i != factContainer.end(); i++)
  {
    factorial *= elem++;
    BOOST_CHECK_EQUAL(*i, factorial);
  }
}
BOOST_AUTO_TEST_SUITE_END()
