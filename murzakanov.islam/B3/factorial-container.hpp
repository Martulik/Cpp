#ifndef FACTORIAL_CONTAINER_HPP
#define FACTORIAL_CONTAINER_HPP

#include <cstddef>
#include <iterator>

namespace murzakanov
{
  class FactorialContainer
  {
  public:
    class Iterator: public std::iterator< std::bidirectional_iterator_tag, unsigned >
    {
    public:
      Iterator& operator++();
      Iterator operator++(int);
      Iterator& operator--();
      Iterator operator--(int);

      unsigned& operator*();
      unsigned* operator->();
      bool operator==(const Iterator&) const;
      bool operator!=(const Iterator&) const;

    private:
      friend class FactorialContainer;
      unsigned num_;
      unsigned value_;

      Iterator();
      Iterator(unsigned num, unsigned value);
    };

    FactorialContainer() = default;
    Iterator begin() const;
    Iterator end() const;
  };
}

#endif
