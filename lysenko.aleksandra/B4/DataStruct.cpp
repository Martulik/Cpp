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

std::istream& lysenko::operator >> (std::istream& in, lysenko::DataStruct& data)
{
  char delimiter = ',';

  std::string str;
  size_t amountOfKeys = 2;
  std::vector< int > keys;
  std::string inpStr;
  getline(in, inpStr);

  std::istringstream inp(inpStr);

  if (inpStr.empty())
  {
    return in;
  }
  for (size_t i = 0; i < amountOfKeys;i++)
  {
    std::string key;
    getline(inp, key, delimiter);
    if (key.empty())
    {
      return in;
    }
    if (inp.fail())
    {
      throw std::invalid_argument("Invalid input/n");
    }
    keys.push_back(std::stoi(key));
  }

  inp >> str;

  data.key1 = keys[0];
  data.key2 = keys[1];
  data.str = str;

  return in;
}
