#include "DataStruct.h"

#include <vector>
#include <stdexcept>
#include <sstream>

bool lysenko::operator < (const DataStruct& firstOp, const DataStruct& secondOp)
{
  if (firstOp.key1 < secondOp.key1)
  {
    return 1;
  }
  if (firstOp.key1 == secondOp.key1)
  {
    if (firstOp.key2 < secondOp.key2)
    {
      return 1;
    }
    if (firstOp.key2 == secondOp.key2)
    {
      return (firstOp.str.length() < secondOp.str.length());
    }
  }
  return 0;
}


std::ostream& lysenko::operator << (std::ostream& out, const lysenko::DataStruct& data)
{
  out << data.key1 << "," << data.key2 << "," << data.str << "\n";
  return out;
}

std::istream& lysenko::operator >> (std::istream& in, lysenko::DataStruct& data)
{
  const int MAX = 5;
  const int MIN = -5;
  char delimiter = ',';

  std::string str;
  size_t amountOfKeys = 2;
  std::vector< int > keys;
  std::string inpStr;
  getline(in, inpStr);
  std::istringstream inp(inpStr);

  for (size_t i = 0; i < amountOfKeys;i++)
  {
    if (inpStr.empty())
    {
      throw std::invalid_argument("Invalid input/n");
      return in;
    }

    std::string key;
    getline(inp, key, delimiter);

    if (key.empty())
    {
      throw std::invalid_argument("Invalid key/n");
      return in;
    }
    if (inp.fail())
    {
      throw std::invalid_argument("Invalid input/n");
      return in;
    }
    keys.push_back(std::stoi(key));
  }

  if (inpStr.empty())
  {
    throw std::invalid_argument("Invalid input/n");
    return in;
  }

  inp >> str;

  data.key1 = keys[0];
  data.key2 = keys[1];
  data.str = str;

  if (inp.fail() || data.key1 > MAX || data.key2 > MAX || data.key1 < MIN || data.key2 < MIN)
  {
    throw std::invalid_argument("Invalid input/n");
    return in;
  }

  return in;
}
