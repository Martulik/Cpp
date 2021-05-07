#ifndef FACTORIAL_CONTAINER_HPP
#define FACTORIAL_CONTAINER_HPP

#include <cstddef>
#include <iterator>

namespace murzakanov
{
  class FactorialContainer
  {
  public:
    class Iterator: public std::iterator< std::bidirectional_iterator_tag, size_t >
    {
    public:
      Iterator();
      Iterator(size_t num);

      Iterator& operator++();
      Iterator operator++(int);
      Iterator& operator--();
      Iterator operator--(int);

      size_t& operator*();
      size_t* operator->();
      bool operator==(const Iterator&) const;
      bool operator!=(const Iterator&) const;

    private:
      size_t num_;
      size_t value_;
    };

    FactorialContainer() = default;
    Iterator begin() const;
    Iterator end() const;
  };
}

#endif
