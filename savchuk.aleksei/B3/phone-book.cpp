#include "phone-book.hpp"

namespace lab = savchuk;

const lab::contact_t& lab::PhoneBook::show(lab::PhoneBook::iterator it) const
{
  return *it;
}

lab::PhoneBook::iterator lab::PhoneBook::moveNext(lab::PhoneBook::iterator it)
{
  if (it != --data_.cend())
  {
    ++it;
  }
  return it;
}

lab::PhoneBook::iterator lab::PhoneBook::movePrev(lab::PhoneBook::iterator it)
{
  if (it != data_.cbegin())
  {
    --it;
  }
  return it;
}

lab::PhoneBook::iterator lab::PhoneBook::add(lab::PhoneBook::iterator it, const lab::contact_t& src)
{
  return data_.insert(it, src);
}

lab::PhoneBook::iterator lab::PhoneBook::replace(lab::PhoneBook::iterator it, const contact_t& src)
{
  *it = src;
  return it;
}

lab::PhoneBook::iterator lab::PhoneBook::add(const lab::contact_t& src)
{
  data_.push_back(src);
  return --data_.end();
}

lab::PhoneBook::iterator lab::PhoneBook::move(lab::PhoneBook::iterator it, int steps)
{
  if (steps >= 0)
  {
    while (steps != 0)
    {
      if (it == --data_.end())
      {
        return it;
      }
      ++it;
      --steps;
    }
  }
  else
  {
    while (steps != 0)
    {
      if (it == data_.begin())
      {
        return it;
      }
      --it;
      ++steps;
    }
  }
  return it;
}

lab::PhoneBook::iterator lab::PhoneBook::remove(lab::PhoneBook::iterator it)
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
