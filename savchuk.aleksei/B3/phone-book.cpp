#include "phone-book.hpp"

#include <iterator>

namespace lab = savchuk;

const lab::contact_t& lab::PhoneBook::show(lab::PhoneBook::const_iterator it) const
{
  return *it;
}

lab::PhoneBook::const_iterator lab::PhoneBook::add(lab::PhoneBook::const_iterator it, const lab::contact_t& contact)
{
  return data_.insert(it, contact);
}

lab::PhoneBook::const_iterator lab::PhoneBook::replace(lab::PhoneBook::const_iterator it, const contact_t& contact)
{
  iterator iter = data_.begin();
  std::advance(iter, std::distance(data_.cbegin(), it));
  *iter = contact;
  return iter;
}

lab::PhoneBook::const_iterator lab::PhoneBook::add(const lab::contact_t& contact)
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

lab::PhoneBook::const_iterator lab::PhoneBook::cbegin() const
{
  return data_.cbegin();
}

lab::PhoneBook::const_iterator lab::PhoneBook::cend() const
{
  return data_.cend();
}
