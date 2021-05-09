#include "command-table.hpp"

namespace poz = pozdnyakov;

bool poz::CommandTable::checkCommand(std::vector< std::string > commandStr) const
{
  bool isCorrect = true;
  for (size_t i = 0; i < patterns_.size(); i++)
  {
    if (commandStr.size() != patterns_[i].size())
    {
      continue;
    }
    for (size_t j = 0; j < patterns_[i].size(); j++)
    {
      isCorrect &= fieldHandlersMap_.at(patterns_[i][j])->isField(commandStr[j]);
    }
    if (isCorrect)
    {
      return true;
    }
    isCorrect = true;
  }
  return false;
}

poz::CommandTable::fhMapType poz::CommandTable::fieldHandlersMap_ = genMap();

poz::CommandTable::fhMapType poz::CommandTable::genMap()
{
  poz::CommandTable::fhMapType fhMap;
  fhMap["Command"] = std::make_unique< poz::Command >();
  fhMap["CommandParam"] = std::make_unique< poz::CommandParam >();
  fhMap["PhoneNumber"] = std::make_unique< poz::PhoneNumber >();
  fhMap["Name"] = std::make_unique< poz::Name >();
  fhMap["Int"] = std::make_unique< poz::Int >();
  fhMap["String"] = std::make_unique< poz::String >();
  return fhMap;
};
