#include "helpFunctions.h"

#include <iostream>

#include "DataStruct.h"

namespace lysenko
{
  void fillVector(std::vector< DataStruct > &myVect)
  {
    while (!std::cin.eof())
    {
      std::string line;
      std::getline(std::cin, line);
      DataStruct newData = splitLineOnTheLineAndGetDataStruct(line);
      myVect.push_back(newData);
    }
  }

  DataStruct splitLineOnTheLineAndGetDataStruct(std::string line)
  {
    std::vector< int >keys;
    std::string str;

    int keysAmount = 2;

    char delim = ',';

    for (int i = 0; i < keysAmount; i++)
    {
      int delimPos = line.find(delim);
      std::string keyStr;

      keyStr = line.substr(0, delimPos);
      line = line.substr(delimPos + 1);

      keys.push_back(std::stoi(keyStr));
    }
     
    str = line;
    return { keys[0], keys[1], str };
  }

  void sortVector(std::vector< DataStruct >& myVect)
  {
    for (int i = 0; i < myVect.size(); i++)
    {
      for (int j = i; j < myVect.size(); j++)
      {
        if (!isGreater(myVect[i], myVect[j]))
        {
          std::swap(myVect[i], myVect[j]);
        }
      }
    }
  }

  void printVector(const std::vector< DataStruct >& myVect, std::ostream& out)
  {
    for (int i = 0; i < myVect.size(); i++)
    {
      out << myVect[i].key1 << "," << myVect[i].key2 << "," << myVect[i].str << "\n";
    }
  }
}