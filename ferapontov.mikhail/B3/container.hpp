#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>

namespace ferapontov
{
  class Container
  {
    using valueType = unsigned long;
    public:
      Container() = default;

      class Iterator: public std::iterator< std::bidirectional_iterator_tag, valueType >
      {
        public:
          Iterator();

          Iterator& operator+(int num);
          Iterator& operator-(int num);

          Iterator& operator++();
          Iterator& operator--();

          Iterator& operator--(int num);
          Iterator& operator++(int num);

          const value_type& operator*();
          const value_type* operator->();
        private:
          size_t index_;
          valueType value_;

          Iterator(size_t index, unsigned long value);
          friend class Container;
      };
      Iterator begin() const noexcept;
      Iterator end() const noexcept;
};
}

#endif
