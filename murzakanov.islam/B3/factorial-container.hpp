#ifndef FACTORIAL_CONTAINER_HPP
#define FACTORIAL_CONTAINER_HPP

#include <cstddef>
#include <iterator>

namespace murzakanov
{
  class FactorialContainer
  {
  public:
    using value_type = unsigned;
    class Iterator: public std::iterator< std::bidirectional_iterator_tag, value_type >
    {
    public:
      Iterator& operator++();
      Iterator operator++(int);
      Iterator& operator--();
      Iterator operator--(int);

      const value_type& operator*();
      const value_type* operator->();
      bool operator==(const Iterator&) const;
      bool operator!=(const Iterator&) const;

    private:
      friend class FactorialContainer;
      value_type num_;
      value_type value_;

      Iterator();
      Iterator(value_type num, value_type value);
    };

    FactorialContainer() = default;
    Iterator begin() const noexcept;
    Iterator end() const noexcept;
  };
}

#endif
