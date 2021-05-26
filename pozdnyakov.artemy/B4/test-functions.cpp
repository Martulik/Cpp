#include "test-functions.hpp"
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include "data-struct.hpp"

namespace poz = pozdnyakov;

bool poz::testOut()
{
  std::vector< poz::DataStruct > vector
  {
    {1, 2, "weewee"},
    {4, 5, "wiqufnqe"},
    {-3, 1, "elkqweiogoiu"}
  };
  std::stringstream ss;
  std::ostream_iterator< poz::DataStruct > out(ss, "\n");
  std::copy(vector.begin(), vector.end(), out);
  std::vector< std::string > exp
  {
    "1,2,weewee",
    "4,5,wiqufnqe",
    "-3,1,elkqweiogoiu"
  };
  std::istream_iterator< std::string > begin(ss);
  std::istream_iterator< std::string > eos;
  std::vector< std::string > got(begin, eos);
  return got == exp;
}
