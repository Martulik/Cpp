#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>

namespace ferapontov
{
  class Container
  {
    public:
      using valueType = unsigned long;
      Container() = default;

      class Iterator: public std::iterator< std::bidirectional_iterator_tag, valueType >
      {
        public:
          Iterator();

          Iterator& operator++();
          Iterator& operator--();

          Iterator operator--(int);
          Iterator operator++(int);

          const value_type& operator*();
          const value_type* operator->();

          bool operator==(const Iterator& it);
          bool operator!=(const Iterator& it);
        private:
          size_t index_;
          valueType value_;

          Iterator(size_t index, valueType value);
          friend class Container;
      };
      Iterator begin() const noexcept;
      Iterator end() const noexcept;
  };
}

#endif
