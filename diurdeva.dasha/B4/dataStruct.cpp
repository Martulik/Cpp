#include "dataStruct.hpp"
#include <iostream>

std::istream& diurdeva::operator>>(std::istream& in, DataStruct& dataStruct)
{
  char separator;
  int key1_;
  in >> key1_;
  in >> separator;

  if (separator != ',')
  {
    throw std::invalid_argument("Invalid first separator\n");
  }

  int key2_;
  in >> key2_;
  in >> separator;

  if (separator != ',')
  {
    throw std::invalid_argument("Invalid second separator\n");
  }

  std::string str_;
  getline(in, str_);

  if (str_.empty())
  {
    throw std::invalid_argument("Third argument is empty\n");
  }

  if ((abs(key1_) > 5) || (abs(key2_) > 5))
  {
    throw std::out_of_range("Values out of range\n");
  }

  dataStruct = DataStruct{ key1_, key2_, str_ };

  return in;
}

std::ostream& diurdeva::operator<<(std::ostream& cout, const DataStruct& data)
{
  cout << data.key1 << "," << data.key2 << "," << data.str << "\n";
  return cout;
}

bool diurdeva::compare(DataStruct& lhs, DataStruct& rhs)
{
  if (lhs.key1 != rhs.key1)
  {
    return lhs.key1 < rhs.key1;
  }
  if (lhs.key2 != rhs.key2)
  {
    return lhs.key2 < rhs.key2;
  }
  return lhs.str.size() < rhs.str.size();
}
