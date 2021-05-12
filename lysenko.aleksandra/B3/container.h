#ifndef CONTAINER_H
#define CONTAINER_H

#include <iterator>

namespace lysenko
{
  class Container
  {
  public:
    class Iterator: public std::iterator<std::bidirectional_iterator_tag, unsigned int>
    {
    public:
      Iterator();
      Iterator(unsigned int index);

      unsigned int &operator*();
      Iterator &operator++();
      Iterator &operator--();
      Iterator operator++(int);
      Iterator operator--(int);
      bool operator ==(const Iterator& other) const;
      bool operator !=(const Iterator& other) const;

    private:
      unsigned int content_;
      unsigned int index_;
    };

    typedef std::reverse_iterator< Iterator > reverse_iterator;

    Container() = default;

    Iterator begin() const;
    Iterator end() const;

    reverse_iterator rbegin() const;
    reverse_iterator rend() const;

    static const size_t MINIMUM_INDEX = 1;
    static const size_t MAXIMUM_INDEX = 11;
  };
}

#endif
