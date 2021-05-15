#include "phone-book.hpp"
#include "note.hpp"

namespace mur = murzakanov;

mur::PhoneBook::const_iterator mur::PhoneBook::begin()
{
  return book_.cbegin();
}

mur::PhoneBook::const_iterator mur::PhoneBook::end()
{
  return book_.cend();
}

void mur::PhoneBook::insertAfter(mur::PhoneBook::const_iterator it, const mur::note_t& note)
{
  const_iterator tempIt(it);
  ++tempIt;
  mur::note_t tempNote{note.number, note.name};
  if (tempIt == book_.end())
  {
    book_.push_back(tempNote);
    return;
  }
  book_.insert(tempIt, tempNote);
}

void mur::PhoneBook::insertBefore(mur::PhoneBook::const_iterator it, const mur::note_t& note)
{
  book_.insert(it, note);
}

void mur::PhoneBook::deleteNote(PhoneBook::const_iterator it)
{
  book_.erase(it);
}

void mur::PhoneBook::push_back(const mur::note_t& note)
{
  book_.push_back(note);
}

size_t mur::PhoneBook::size() const
{
  return book_.size();
}

bool mur::PhoneBook::isEmpty() const
{
  return book_.empty();
}
