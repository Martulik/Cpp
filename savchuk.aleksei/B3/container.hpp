#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <cstddef>
#include <algorithm>

namespace savchuk
{
  class Container
  {
    public:
      using valueType = unsigned long long;

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
          unsigned int idx_;
          valueType value_;

          Iterator(unsigned int idx);

          friend class Container;
      };

      Container() = default;

      Iterator begin();
      Iterator end();
  };
}

#endif
