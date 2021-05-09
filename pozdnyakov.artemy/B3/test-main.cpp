#define BOOST_TEST_MODULE B1
#include <boost/test/included/unit_test.hpp>

#include "tasks.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_CASE(test_task1)
{
  const std::vector< std::string > commands
  {
    "add 555 Elkinne",
    "show current",
    "insert after current 1488 Islam",
    "show current",
    "move current 1",
    "show current",
    "delete current",
  };
  std::stringstream ss;
  for (std::string com: commands)
  {
    ss << com << '\n';
  }
  poz::task1(ss, std::cout);
}
