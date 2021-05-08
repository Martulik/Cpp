#include "struct.hpp"
#include "tools.hpp"

std::istream &ivanova::operator >>(std::istream &in, ivanova::DataStruct &data)
{
  std::string str;
  std::getline(in, str);
  {
    if (!str.empty())
    {
      data = getVector(str);
    }
    else
    {
      in.setstate(in.eofbit);
    }
  }
  return in;
}

std::ostream &ivanova::operator <<(std::ostream &out, ivanova::DataStruct &data)
{
  out << data.key1 << "," << data.key2 << "," << data.str << std::endl;
  return out;
}

bool ivanova::empty(ivanova::DataStruct &data)
{
  if (data.str.empty())
  {
    return true;
  }
  return false;
}
