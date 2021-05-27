#ifndef FACTORIAL_CONTAINER_HPP
#define FACTORIAL_CONTAINER_HPP

#include <iterator>

namespace shkurov
{
  class FactorialContainer
  {
    public:
      class Iterator;
      FactorialContainer() = default;
      Iterator begin() const noexcept;
      Iterator end() const noexcept;

      class Iterator: public std::iterator< std::bidirectional_iterator_tag, unsigned long >
      {
        public:
          const unsigned long* operator->() const;
          const unsigned long& operator*() const;
          bool operator==(const Iterator& rhs) const;
          bool operator!=(const Iterator& rhs) const;
          Iterator& operator++();
          Iterator operator++(int);
          Iterator& operator--();
          Iterator operator--(int);
        private:
          friend Iterator FactorialContainer::begin() const noexcept;
          friend Iterator FactorialContainer::end() const noexcept;
          Iterator(unsigned long value, size_t index);
          Iterator();

          unsigned long value_;
          size_t index_;
      };
  };
}


#endif
