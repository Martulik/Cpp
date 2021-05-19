#include "test-tools.hpp"

#include <sstream>

#include <boost/test/unit_test.hpp>

#include "data-struct.hpp"

namespace lab = savchuk;

void lab::checkCorrectInput(std::istringstream& ss, const char* data)
{
  DataStruct ds;
  ss.str(data);
  BOOST_CHECK(ss >> ds);
}

void lab::checkIncorrectInput(std::istringstream& ss, const char* data)
{
  DataStruct ds;
  ss.clear();
  ss.str(data);
  BOOST_CHECK(!(ss >> ds));
}

void lab::checkInvalidKey(std::istringstream& ss, const char* data)
{
  DataStruct ds;
  ss.clear();
  ss.str(data);
  BOOST_CHECK(!(ss >> ds));
}
