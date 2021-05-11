#include "phonebook.hpp"


void diurdeva::Phonebook::pushBack(const record_t& rec)
{
  return list_.push_back(rec);
}

bool diurdeva::Phonebook::empty() const
{
  return list_.empty();
}

diurdeva::Phonebook::const_iterator diurdeva::Phonebook::begin() const
{
  return list_.begin();
}

diurdeva::Phonebook::const_iterator diurdeva::Phonebook::end() const
{
  return list_.end();
}

diurdeva::Phonebook::const_iterator diurdeva::Phonebook::insert(const_iterator iter, const record_t& rec)
{
  return list_.insert(iter, rec);
}

diurdeva::Phonebook::const_iterator diurdeva::Phonebook::remove(const_iterator iter)
{
  return list_.erase(iter);
}

diurdeva::Phonebook::const_iterator diurdeva::Phonebook::move(const_iterator iter, const int n)
{
  int count = 0;
  if (n >= 0)
  {
    while (std::next(iter) != list_.end() && (count != n))
    {
      ++iter;
      ++count;
    }
  }
  else
  {
    while (iter != list_.begin() && (count != n))
    {
      --iter;
      --count;
    }
  }
  return iter;
}
