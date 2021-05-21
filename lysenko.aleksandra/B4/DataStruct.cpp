#include "DataStruct.h"

#include <vector>
#include <stdexcept>
#include <sstream>

bool lysenko::operator< (const DataStruct& firstOp, const DataStruct& secondOp)
{
  if (firstOp.key1 < secondOp.key1)
  {
    return true;
  }
  if (firstOp.key1 == secondOp.key1)
  {
    if (firstOp.key2 < secondOp.key2)
    {
      return true;
    }
    if (firstOp.key2 == secondOp.key2)
    {
      return (firstOp.str.length() < secondOp.str.length());
    }
  }
  return false;
}

bool lysenko::operator> (const DataStruct& firstOp, const DataStruct& secondOp)
{
  return (secondOp < firstOp);
}

bool lysenko::operator== (const DataStruct& firstOp, const DataStruct& secondOp)
{
  return (!((firstOp < secondOp) || (secondOp < firstOp)));
}


bool lysenko::operator>= (const DataStruct& firstOp, const DataStruct& secondOp)
{
  return !(firstOp < secondOp);
}

bool lysenko::operator<= (const DataStruct& firstOp, const DataStruct& secondOp)
{
  return !(secondOp < firstOp);
}

bool lysenko::operator!= (const DataStruct& firstOp, const DataStruct& secondOp)
{
  return ((firstOp < secondOp) || (secondOp < firstOp));
}

std::ostream& lysenko::operator<< (std::ostream& out, const lysenko::DataStruct& data)
{
  out << data.key1 << "," << data.key2 << "," << data.str;
  return out;
}

std::istream& lysenko::operator>> (std::istream& in, lysenko::DataStruct& data)
{
  constexpr int MAXABS = 5;
  char delimiter = ',';

  size_t amountOfKeys = 2;
  std::vector< int > keys;

  std::string inpStr;
  getline(in, inpStr);
  std::istringstream inp(inpStr);

  for (size_t i = 0; i < amountOfKeys; i++)
  {
    if (inpStr.empty())
    {
      return in;
    }

    std::string key;
    getline(inp, key, delimiter);

    if (inp.fail())
    {
      throw std::invalid_argument("No or not many enough delimiters\n");
    }

    keys.push_back(std::stoi(key));
  }

  data.key1 = keys[0];
  data.key2 = keys[1];
  inp >> std::ws;
  getline(inp, data.str);

  if (inp.fail() || (std::abs(data.key1) > MAXABS) || (std::abs(data.key2) > MAXABS) || (data.str.empty()))
  {
    throw std::invalid_argument("Illegal input data\n");
  }

  return in;
}
