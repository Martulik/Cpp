#ifndef STRATEGIES_HPP
#define STRATEGIES_HPP

#include <vector>
#include <list>

template <typename T>
class IndexStrategy
{
public:
  using ContType = std::vector<T>;
  using IterType = T*;
  static T* begin(std::vector<T>& cont);
  static T* end(std::vector<T>& cont);
  static T* getElem(T* iter);
};

template <typename T>
class VectorAtStrategy
{
  using ContType = std::vector<T>;
  using IterType = T*;
public:
  static T* begin(std::vector<T>& cont);
  static T* end(std::vector<T>& cont);
  static T* getElem(T* iter);
};

template <typename T>
class ListStrategy
{
  using ContType = std::list<T>;
  using IterType = typename std::list<T>::iterator;
public:
  static IterType begin(std::list<T>& cont);
  static IterType end(std::list<T>& cont);
  static T* getElem(IterType iter);
};

template <typename T>
T* IndexStrategy<T>::begin(std::vector<T>& cont)
{
  return &cont[0];
}

template <typename T>
T* IndexStrategy<T>::end(std::vector<T>& cont)
{
  return &cont[cont.size() - 1];
}

template <typename T>
T* IndexStrategy<T>::getElem(T* iter)
{
  return iter;
}

template <typename T>
T* VectorAtStrategy<T>::begin(std::vector<T>& cont)
{
  return &cont.at(0);
}

template <typename T>
T* VectorAtStrategy<T>::end(std::vector<T>& cont)
{
  return &cont.at(cont.size() - 1);
}

template <typename T>
T* VectorAtStrategy<T>::getElem(T* iter)
{
  return iter;
}

template <typename T>
typename std::list<T>::iterator ListStrategy<T>::begin(std::list<T>& cont)
{
  return cont.begin();
}

template <typename T>
typename std::list<T>::iterator ListStrategy<T>::end(std::list<T>& cont)
{
  return cont.end();
}

template <typename T>
T* ListStrategy<T>::getElem(typename std::list<T>::iterator iter)
{
  return *iter;
}

#endif
