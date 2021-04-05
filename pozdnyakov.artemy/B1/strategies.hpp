#ifndef STRATEGIES_HPP
#define STRATEGIES_HPP

#include <vector>
#inclide <list>

template <template <typename T> class Container, template <typename T> class IterType, typename ElemType>
class Strategy
{
public:
  IterType begin(ContType& cont) const = 0;
  IterType end(ContType& cont) const = 0;
  ElemType* getElem(IterType iter) const = 0;
};

template <typename T>
class IndexStrategy: public Strategy<std::vector<T>, T*, T>
{
  using ContType = std::vector<T>;
  using IterType = T*;
public:
  T* begin(std::vector<T>& cont) const override;
  T* end(std::vector<T>& cont) const override;
  T* getElem(T* iter) const override;
};

template <typename T>
class VectorAtStrategy: public Strategy<std::vector<T>, T*, T>
{
  using ContType = std::vector<T>;
  using IterType = T*;
public:
  T* begin(std::vector<T>& cont) const override;
  T* end(std::vector<T>& cont) const override;
  T* getElem(T* iter) const override;
};

template <typename T>
class ListStrategy: public Strategy<std::list<T>, std::list<T>::iterator, T>
{
  using ContType = std::list<T>;
  using IterType = std::list<T>::iterator;
public:
  IterType begin(std::list<T>& cont) const override;
  IterType end(std::list<T>& cont) const override;
  T* getElem(IterType iter) const override;
};

#endif
