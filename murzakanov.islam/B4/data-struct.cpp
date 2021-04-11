#include "data-struct.hpp"

#include <string>
#include <iostream>

#include "tools.hpp"

bool murzakanov::operator <(const DataStruct& data1, const DataStruct& data2)
{
  if (data1.key1 == data2.key1)
  {
    if (data1.key2 == data2.key2)
    {
      return (data1.str.size() < data2.str.size());
    }
    return (data1.key2 < data2.key2);
  }
  return (data1.key1 < data2.key1);
}

std::istream& murzakanov::operator>>(std::istream& in, DataStruct& data)
{
  std::istream::sentry sentry(in);

  if (sentry)
  {
    int key1;
    int key2;
    std::string str;

    in >> key1;
    readDelimiter(in, ',');
    in >> key2;
    readDelimiter(in, ',');
    str = readString(in);

    if (in && key1 > -5 && key1 < 5 && key2 > -5 && key2 < 5)
    {
      data = DataStruct{ key1, key2, str };
    }
  }

  return in;
}

std::ostream& murzakanov::operator<<(std::ostream& out, const DataStruct& data)
{
  out << std::left << data.key1 << " " << data.key2
      << " " << data.str << "\n";
  return out;
}