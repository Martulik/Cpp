#include "task.hpp"
#include <sstream>
#include <stdio.h>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include "data-struct.hpp"
#include "functions.hpp"

void lebedeva::doTask1(std::istream& in, std::ostream& out)
{
  std::string inStr;
  std::vector< DataStruct > data;
  while (std::getline(in, inStr) && !inStr.empty())
  {
    if (in.fail())
    {
      throw std::runtime_error("Input error\n");
    }
    std::string key1, key2;
    DataStruct temp;
    const char delimiter = ',';
    std::stringstream input(inStr);
    
    std::getline(input>> std::ws, key1, delimiter);
    if (!key1.empty() && isNumber(key1))
    {
      temp.key1 = std::stoi(key1);
      if (isAcceplable(temp.key1))
      {
        std::getline(input >> std::ws, key2, delimiter);
        if (!key2.empty() && isNumber(key2))
        {
          temp.key2 = std::stoi(key2);
          if (isAcceplable(temp.key2))
          {
            std::getline(input, temp.str);
            if (!temp.str.empty())
            {
              data.push_back(temp);
            }
            else
            {
              throw std::invalid_argument("Invalid str input\n");
            }
          }
          else
          {
            throw std::invalid_argument("Invalid key2 input\n");
          }
        }
        else
        {
          throw std::invalid_argument("Invalid key2 input\n");
        }
      }
      else
      {
        throw std::invalid_argument("Invalid key1 input\n");
      }
    }
    else
    {
      throw std::invalid_argument("Invalid key1 input\n");
    }
  }
  if (data.size() > 1)
  {
    std::sort(data.begin(), data.end());
  }
  print(data, out);
}
