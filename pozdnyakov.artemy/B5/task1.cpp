#include "tasks.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <set>
#include <iterator>
#include <algorithm>

namespace poz = pozdnyakov;

void poz::task1(std::string fileName)
{
  std::ifstream fs;
  fs.open(fileName);
  if (!fs.is_open())
  {
    throw std::invalid_argument("No such file");
  }
  auto eos = std::istream_iterator< std::string >();
  std::set< std::string > textSet(std::istream_iterator< std::string >(fs), eos);
  if (fs.fail())
  {
    throw std::runtime_error("Invalid file");
  }
  std::copy(textSet.cbegin(), textSet.cend(), std::ostream_iterator< std::string >(std::cout, "\n"));
}
