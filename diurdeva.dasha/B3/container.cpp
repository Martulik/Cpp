#include "container.hpp"

diurdeva::Container::IteratorFact::IteratorFact(size_t pos) :
  pos_(pos),
  value_(factor(pos))
{}

const size_t& diurdeva::Container::IteratorFact::operator*() const
{
  return value_;
}

diurdeva::Container::IteratorFact& diurdeva::Container::IteratorFact::operator++()
{
  if (pos_ < MAX_POS)
  {
    ++pos_;
    value_ *= pos_;
  }
  return *this;
}

diurdeva::Container::IteratorFact diurdeva::Container::IteratorFact::operator++(int)
{
  IteratorFact temp = *this;
  ++(*this);
  return temp;
}

diurdeva::Container::IteratorFact& diurdeva::Container::IteratorFact::operator--()
{
  if (pos_ > MIN_POS)
  {
    value_ /= pos_;
    --pos_;
  }
  return *this;
}

diurdeva::Container ::IteratorFact diurdeva::Container::IteratorFact::operator--(int)
{
  IteratorFact temp = *this;
  --(*this);
  return temp;
}

bool diurdeva::Container::IteratorFact::operator==(const Container::IteratorFact& rhs) const
{
  return (pos_ == rhs.pos_);
}

bool diurdeva::Container::IteratorFact::operator!=(const Container::IteratorFact& rhs) const
{
  return !(*this == rhs);
}

inline size_t diurdeva::Container::IteratorFact::factor(size_t number)
{
  size_t result = 1;
  for (size_t i = 1; i <= number; ++i)
  {
    result *= i;
  }
  return result;
}

diurdeva::Container::IteratorFact diurdeva::Container::begin()
{
  return IteratorFact(IteratorFact::MIN_POS);
}

diurdeva::Container ::IteratorFact diurdeva::Container::end()
{
  return IteratorFact(IteratorFact::MAX_POS);
}
