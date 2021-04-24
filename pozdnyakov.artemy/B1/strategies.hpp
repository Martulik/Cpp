#ifndef STRATEGIES_HPP
#define STRATEGIES_HPP

#include <vector>
#include <list>

namespace pozdnyakov
{
  template <typename T>
  class IndexStrategy
  {
  public:
    using ContType = std::vector<T>;
    using IterType = size_t;
    static size_t begin(const std::vector<T>&)
    {
      return 0;
    }
    static size_t end(const std::vector<T>& cont)
    {
      return cont.size();
    }
    static T& getElem(std::vector<T>& cont, size_t iter)
    {
      return cont[iter];
    }
    static size_t getIterPrev(const size_t iter)
    {
      return iter - 1;
    }
  };

  template <typename T>
  class VectorAtStrategy
  {
  public:
    using ContType = std::vector<T>;
    using IterType = size_t;
    static size_t begin(const std::vector<T>&)
    {
      return 0;
    }
    static size_t end(const std::vector<T>& cont)
    {
      return cont.size();
    }
    static T& getElem(std::vector<T>& cont, size_t iter)
    {
      return cont.at(iter);
    }
    static size_t getIterPrev(const size_t iter)
    {
      return iter - 1;
    }
  };

  template <typename T>
  class ListStrategy
  {
  public:
    using ContType = std::list<T>;
    using IterType = typename std::list<T>::iterator;
    static typename std::list<T>::iterator begin(std::list<T>& cont)
    {
      return cont.begin();
    }
    static typename std::list<T>::iterator end(std::list<T>& cont)
    {
      return cont.end();
    }
    static T& getElem(const std::list<T>&, const typename std::list<T>::iterator iter)
    {
      return *iter;
    }
    static typename std::list<T>::iterator getIterPrev(typename std::list<T>::iterator& iter)
    {
      return std::prev(iter);
    }
  };
}

#endif
