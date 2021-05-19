#include "phonebook.hpp"
#include "factorial.hpp"

dushechkina::Phonebook::iterator dushechkina::Phonebook::begin()
{
  return records_.begin();
}

dushechkina::Phonebook::iterator dushechkina::Phonebook::end()
{
  return records_.end();
}

void dushechkina::Phonebook::insertBeforeCurrentRecord(iterator current, const Record& newRecord)
{
  records_.emplace(current, newRecord);
}

void dushechkina::Phonebook::insertAfterCurrentRecord(iterator current, const Record& newRecord)
{
  records_.emplace(std::next(current), newRecord);
}

void dushechkina::Phonebook::insertAtTheEnd(const Record& newRecord)
{
  records_.emplace_back(newRecord);
}

void dushechkina::Phonebook::removeCurrentRecord(iterator current)
{
  records_.erase(current);
}

bool dushechkina::Phonebook::isEmpty() const
{
  return records_.empty();
}
