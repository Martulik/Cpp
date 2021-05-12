#include "phone-book.hpp"

using PB = pochernin::PhoneBook;

void PB::pushBack(const entry_t& entry)
{
  data_.push_back(entry);
}