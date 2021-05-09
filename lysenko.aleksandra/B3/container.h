#ifndef CONTAINER_H
#define CONTAINER_H

#include <iterator>

namespace lysenko
{
  class Container
  {
    class Iterator: public std::iterator<std::bidirectional_iterator_tag, unsigned int>
    {
    public:
      Iterator();
      Iterator(unsigned int index);

    private:
      unsigned int content_;
      unsigned index_;
    };

    Container() = default;

    Iterator begin();
    Iterator end();

    static const size_t MINIMUM_INDEX = 1;
    static const size_t MAXIMUM_INDEX = 10;
  };
}

#endif