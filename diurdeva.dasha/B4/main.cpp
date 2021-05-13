#include "dataStruct.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

int main()
{
  try
  {
    std::vector< diurdeva::DataStruct > vector;
    std::string string;
    diurdeva::DataStruct data;

    while (std::getline(std::cin, string))
    {
      if (std::cin.fail() && !std::cin.eof())
      {
        throw std::ios_base::failure("Reading failed\n");
      }

      std::stringstream stringStream(string);
      stringStream >> data;
      vector.push_back(data);
    }

    sort(vector.begin(), vector.end(), diurdeva::compare);
    std::copy(vector.begin(), vector.end(), std::ostream_iterator< diurdeva::DataStruct >(std::cout));
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}
