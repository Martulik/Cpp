#include "phone-book.hpp"
#include <iostream>
#include "note.hpp"

namespace mur = murzakanov;

mur::PhoneBook::iterator mur::PhoneBook::begin()
{
  return book_.begin();
}

mur::PhoneBook::iterator mur::PhoneBook::end()
{
  return book_.end();
}

void mur::PhoneBook::insertAfter(mur::PhoneBook::iterator it, const mur::note_t& note)
{
  iterator tempIt(it);
  ++tempIt;
  mur::note_t tempNote{note.number, note.name};
  if (tempIt == book_.end())
  {
    book_.push_back(tempNote);
    return;
  }
  book_.insert(tempIt, tempNote);
}

void mur::PhoneBook::insertBefore(mur::PhoneBook::iterator it, const mur::note_t& note)
{
  book_.insert(it, note);
}

void mur::PhoneBook::deleteNote(PhoneBook::iterator it)
{
  book_.erase(it);
}

void mur::PhoneBook::push_back(const mur::note_t& note)
{
  book_.push_back(note);
}

void mur::PhoneBook::replace(mur::PhoneBook::iterator it, const mur::note_t& note)
{
  it->name = note.name;
  it->number = note.number;
}

void mur::PhoneBook::show(std::ostream& out, mur::PhoneBook::iterator it) const
{
  out << it->number << " " << it->name << "\n";
}

size_t mur::PhoneBook::size() const
{
  return book_.size();
}

bool mur::PhoneBook::isEmpty() const
{
  return book_.empty();
}
