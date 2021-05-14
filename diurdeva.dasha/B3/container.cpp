#include "container.hpp"
#include <cassert>

using ValueType = diurdeva::Container::ValueType;

constexpr ValueType MAX_POS = 11;
constexpr ValueType MIN_POS = 1;

constexpr ValueType factorial(ValueType n)
{
  return (n <= 1) ? 1 : (n * factorial(n - 1));
}

constexpr ValueType MIN_VALUE = factorial(MIN_POS);
constexpr ValueType MAX_VALUE = factorial(MAX_POS);

diurdeva::Container::IteratorFact::IteratorFact() :
  value_(0),
  pos_(0)
{}

diurdeva::Container::IteratorFact::IteratorFact(ValueType value, ValueType pos) :
  value_(value),
  pos_(pos)
{}

const ValueType* diurdeva::Container::IteratorFact::operator->() const
{
  return std::addressof(value_);
}

const ValueType& diurdeva::Container::IteratorFact::operator*() const
{
  return value_;
}

diurdeva::Container::IteratorFact& diurdeva::Container::IteratorFact::operator++()
{
  assert(pos_ < MAX_POS);
  value_ *= ++pos_;
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
  assert(pos_ > MIN_POS);
  value_ /= pos_--;
  return *this;

}

diurdeva::Container::IteratorFact diurdeva::Container::IteratorFact::operator--(int)
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


diurdeva::Container::IteratorFact diurdeva::Container::begin() const noexcept
{
  return { MIN_VALUE, MIN_POS };
}

diurdeva::Container::IteratorFact diurdeva::Container::end() const noexcept
{
  return { MAX_VALUE, MAX_POS };
}
