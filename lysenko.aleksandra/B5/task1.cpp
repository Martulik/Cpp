#include "tasks.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

int lysenko::task1(std::istream& in, std::ostream& out)
{
  std::string nameOfFile;
  in >> nameOfFile;
  std::ifstream inputFile;
  inputFile.open(nameOfFile);
  try
  {
    if (inputFile.is_open())
    {
      std::vector< std::vector< char > > uniqueWords;
      while (!inputFile.eof())
      {
        std::vector< char > word;
        if (!((inputFile.peek() == ' ') || (inputFile.peek() == '\n') || (inputFile.peek() == '\t')))
        {
          char letterOfTheWord = inputFile.get();
          word.push_back(letterOfTheWord);
          char delimiter;
          inputFile >> delimiter;
        }
        else
        {
          for (unsigned long int i = 0; i < uniqueWords.size(); i++)
          {
            if (uniqueWords[i] == word)
            {
              break;
            }
            if (i == uniqueWords.size() - 1)
            {
              uniqueWords.push_back(word);
            }
          }
        }
      }
      for (unsigned long int i = 0; i < uniqueWords.size(); i++)
      {
        for (unsigned long int j = 0; j < uniqueWords[i].size(); j++)
        {
          out << uniqueWords[i][j];
        }
        out << '\n';
      }
    }
    else
    {
      throw std::invalid_argument("Unable to open the file.Check it exists and openable");
    }
  }
  catch (std::invalid_argument& err)
  {
    std::cerr << err.what();
    return 1;
  }
  return 0;
}