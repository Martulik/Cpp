#include "phone-book.hpp"

namespace lab = savchuk;

const lab::contact_t& lab::PhoneBook::show(lab::PhoneBook::const_iterator it) const
{
  return *it;
}

lab::PhoneBook::iterator lab::PhoneBook::add(lab::PhoneBook::const_iterator it, const lab::contact_t& contact)
{
  return data_.insert(it, contact);
}

lab::PhoneBook::iterator lab::PhoneBook::replace(lab::PhoneBook::iterator it, const contact_t& contact)
{
  *it = contact;
  return it;
}

lab::PhoneBook::iterator lab::PhoneBook::add(const lab::contact_t& contact)
{
  return add(data_.cend(), contact);
}

lab::PhoneBook::const_iterator lab::PhoneBook::move(lab::PhoneBook::const_iterator it, int steps)
{
  if (steps > 0)
  {
    while (it != --data_.end() && steps != 0)
    {
      ++it;
      --steps;
    }
  }
  else
  {
    while (it != data_.begin() && steps != 0)
    {
      --it;
      ++steps;
    }
  }
  return it;
}

lab::PhoneBook::iterator lab::PhoneBook::remove(lab::PhoneBook::const_iterator it)
{
  return data_.erase(it);
}

bool lab::PhoneBook::empty() const
{
  return data_.empty();
}

size_t lab::PhoneBook::size() const
{
  return data_.size();
}

lab::PhoneBook::iterator lab::PhoneBook::begin()
{
  return data_.begin();
}

lab::PhoneBook::iterator lab::PhoneBook::end()
{
  return data_.end();
}

lab::PhoneBook::const_iterator lab::PhoneBook::cbegin() const
{
  return data_.cbegin();
}

lab::PhoneBook::const_iterator lab::PhoneBook::cend() const
{
  return data_.cend();
}
