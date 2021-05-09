#include "command-table.hpp"

namespace poz = pozdnyakov;

bool poz::CommandTable::checkCommand(std::vector< std::string > commandStr) const
{
  bool isCorrect = true;
  for (size_t i = 0; i < patterns_.size(); i++)
  {
    if (commandStr.size() != patterns_[i].size())
    {
      break;
    }
    for (size_t j = 0; j < patterns_[i].size(); j++)
    {
      isCorrect &= fieldHandlers_.at(patterns_[i][j])->isField(commandStr[j]);
    }
    if (isCorrect)
    {
      return true;
    }
    isCorrect = true;
  }
  return false;
}

const std::map< std::string, poz::AbsField* > poz::CommandTable::fieldHandlers_
{
  {"Command", new poz::Command()},
  {"CommandParam", new poz::CommandParam()},
  {"PhoneNumber", new poz::PhoneNumber()},
  {"Name", new poz::Name()},
  {"Int", new poz::Int()},
  {"String", new poz::String()}
};
