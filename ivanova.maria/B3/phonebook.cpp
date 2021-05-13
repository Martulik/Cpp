#include "phonebook.hpp"

namespace iva = ivanova;
iva::PhoneBook::iter iva::PhoneBook::begin() const
{
  return list_.begin();
}

iva::PhoneBook::iter iva::PhoneBook::end() const
{
  return list_.end();
}

void iva::PhoneBook::add(const iva::Record &record)
{
  list_.push_back(record);
}

void iva::PhoneBook::insert(const PhoneBook::iter userIt, const iva::Record &record)
{
  list_.insert(userIt, record);
}

void iva::PhoneBook::erase(const PhoneBook::iter iter)
{
  list_.erase(iter);
}

bool iva::PhoneBook::isEmpty() const
{
  return list_.empty();
}

iva::PhoneBook::iter iva::PhoneBook::moveOnStep(PhoneBook::iter iter, int step) const
{
  if (step > 0)
  {
    while ((std::next(iter) != list_.end()) && (step > 0))
    {
      iter = std::next(iter);
      step--;
    }
  }
  else if (step < 0)
  {
    while ((iter != list_.begin()) && (step < 0))
    {
      iter = std::prev(iter);
      step++;
    }
  }
  return iter;
}
