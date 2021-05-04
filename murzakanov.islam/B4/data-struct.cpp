#include "data-struct.hpp"
#include <iomanip>
#include "tools.hpp"

std::istream& murzakanov::operator >>(std::istream& in, DataStruct& data)
{
  int key1;
  int key2;
  std::string str;
  std::string line;
  if (!getline(in, line))
  {
    return in;
  }
  std::istringstream lin(line);
  char comma = '\0';
  lin >> key1 >> comma;
  if (comma != ',')
  {
    std::cerr << "Missing comma\n";
    std::exit(1);
  }
  comma = '\0';
  lin >> key2 >> comma;
  if (comma != ',')
  {
    std::cerr << "Missing comma\n";
    std::exit(1);
  }
  str = readString(lin);
  if (in && std::abs(key1) <= 5 && std::abs(key2) <= 5)
  {
    data = DataStruct{ key1, key2, str };
  }
  else
  {
    std::cerr << "Keys out of range\n";
    std::exit(1);
  }
  return in;
}

std::ostream& murzakanov::operator <<(std::ostream& out, const DataStruct& data)
{
  out << std::left << data.key1 << ", " << data.key2
      << ", " << data.str << "\n";
  return out;
}



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
