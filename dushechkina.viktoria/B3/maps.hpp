#ifndef MAPS_HPP
#define MAPS_HPP
#include <unordered_map>
#include <string>
#include <functional>
#include "tasks.hpp"
#include "functions.hpp"
#include "phonebook.hpp"

namespace dushechkina
{
  const std::unordered_map<std::string, std::function<void(std::istream&, std::ostream&)>> taskNumber
  { {"1", dushechkina::task1},
   {"2", dushechkina::task2} };

  using command = std::function<void(dushechkina::Phonebook&, MarkList&, std::istream&, std::ostream&)>;
  const std::unordered_map<std::string, command> commandName
  { {"add", add},
   {"store", store},
   {"insert", insert},
   {"delete", remove},
   {"show", show},
   {"move", move} };
}

#endif
