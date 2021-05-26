#include "command-table.hpp"

namespace poz = pozdnyakov;

poz::CommandTable::CommandTable(poz::CommandTable::patternsVector patterns, poz::CommandTable::handlersMap fhMap):
  patterns_(patterns),
  fieldHandlersMap_(fhMap)
{}

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
      isCorrect &= fieldHandlersMap_.at(patterns_[i][j])(commandStr[j]);
    }
    if (isCorrect)
    {
      return true;
    }
    isCorrect = true;
  }
  return false;
}
