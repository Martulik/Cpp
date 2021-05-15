#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <cstddef>
#include <iterator>

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
          const valueType& operator*() const;
          const valueType* operator->() const;

        private:
          unsigned int idx_;
          valueType value_;

          Iterator(unsigned int idx, unsigned long long value);

          friend class Container;
      };

      Container() = default;

      Iterator begin() const noexcept;
      Iterator end() const noexcept;
  };
}

#endif
