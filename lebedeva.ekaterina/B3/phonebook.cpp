#include "phonebook.hpp"

lebedeva::PhoneBook::constIter lebedeva::PhoneBook::begin() const
{
  return data_.cbegin();
}

lebedeva::PhoneBook::constIter lebedeva::PhoneBook::end() const
{
  return data_.cend();
}

bool lebedeva::PhoneBook::empty() const
{
  return data_.empty();
}

size_t lebedeva::PhoneBook::size() const
{
  return data_.size();
}

void lebedeva::PhoneBook::insertBefore(constIter iter, const record_t& rec)
{
  data_.insert(iter, rec);
}

void lebedeva::PhoneBook::insertAfter(constIter iter, const record_t& rec)
{
  constIter tempIter(iter);
  if (++tempIter == data_.end())
  {
    data_.push_back(rec);
    return;
  }
  data_.insert(tempIter, rec);
}

void lebedeva::PhoneBook::replaceRec(Iterator iter, const record_t& rec)
{
  if (iter == data_.end())
  {
    data_.push_back(rec);
    return;
  }
  iter->name = rec.name;
  iter->phoneNumber = rec.phoneNumber;
}

void lebedeva::PhoneBook::deleteRec(constIter iter)
{
  data_.erase(iter);
}

void lebedeva::PhoneBook::pushBack(const record_t& rec)
{
  data_.push_back(rec);
}
