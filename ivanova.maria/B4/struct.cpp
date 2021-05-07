#include "struct.hpp"
#include "tools.hpp"

std::istream &ivanova::operator >>(std::istream &in, ivanova::DataStruct &data)
{
  std::string str;
  in >> str;
  size_t i = 0;
  std::string key1;
  while (str.at(i) != ',')
  {
    key1 += str.at(i);
    i++;
  }

  i++;

}

std::ostream &ivanova::operator<<(std::ostream &out, ivanova::DataStruct &data)
{
  out << data.key1 << "," << data.key2 << "," << data.str << std::endl;
  return out;
}
