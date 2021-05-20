#include "phone-book.hpp"

namespace raz = razukrantov;

void raz::PhoneBook::insertAfter(constIterator iterator, const note_t& note)
{
  constIterator temp = std::next(iterator);
  if (temp == end())
  {
    pushBack(note);
  }
  else
  {
    recordings_.insert(temp, note);
  }
}

void raz::PhoneBook::insertBefore(constIterator iterator, const note_t& note)
{
  recordings_.insert(iterator, note);
}

void raz::PhoneBook::pushBack(const note_t& note)
{
  recordings_.push_back(note);
}

raz::PhoneBook::constIterator raz::PhoneBook::move(raz::PhoneBook::constIterator it, int steps) const
{
  if (steps > 0)
  {
    while (std::next(it) != recordings_.end() && steps != 0)
    {
      it = std::next(it);
      --steps;
    }
  }
  else
  {
    while (it != recordings_.begin() && (steps != 0))
    {
      it = std::prev(it);
      ++steps;
    }
  }
  return it;
}

void raz::PhoneBook::erase(constIterator iterator)
{
  recordings_.erase(iterator);
}

size_t raz::PhoneBook::size() const
{
  return recordings_.size();
}

bool raz::PhoneBook::empty() const
{
  return recordings_.empty();
}

raz::PhoneBook::constIterator raz::PhoneBook::begin() const
{
  return recordings_.cbegin();
}

raz::PhoneBook::constIterator raz::PhoneBook::end() const
{
  return recordings_.cend();
}
