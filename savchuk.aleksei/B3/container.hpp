#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <cstddef>
#include <algorithm>

namespace savchuk
{
  class Container
  {
    public:
      using valueType = size_t;

      class Iterator: public std::iterator< std::bidirectional_iterator_tag, valueType >
      {
        public:
          Iterator();

          Iterator& operator++();
          Iterator operator++(int);
          Iterator& operator--();
          Iterator operator--(int);
          bool operator==(const Iterator& other) const;
          bool operator!=(const Iterator& other) const;
          valueType& operator*();
          valueType* operator->();

        private:
          size_t idx_;
          valueType value_;

          Iterator(size_t idx);

          friend class Container;
      };

      Container() = default;

      Iterator begin();
      Iterator end();
  };
}

#endif
