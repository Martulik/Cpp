#ifndef ACCESS_HPP
#define ACCESS_HPP

namespace lebedeva
{
  template < typename T >
  struct bracketsAccess
  {
    using Iterator = typename T::size_type;
    using valueType = typename T::value_type;

    static Iterator begin(const T&)
    {
      return 0;
    }
    static Iterator end(const T& vector)
    {
      return vector.size();
    }
    static valueType& get(T& vector, Iterator index)
    {
      return vector[index];
    }
  };

  template < typename T >
  struct atAccess
  {
    using Iterator = typename T::size_type;
    using valueType = typename T::value_type;

    static Iterator begin(const T&)
    {
      return 0;
    }
    static Iterator end(const T& vector)
    {
      return vector.size();
    }
    static valueType& get(T& vector, Iterator index)
    {
      return vector.at(index);
    }
  };

  template < class T >
  struct iteratorAccess
  {
    using Iterator = typename T::iterator;
    using valueType = typename T::value_type;

    static Iterator begin(T& list)
    {
      return list.begin();
    }
    static Iterator end(T& list)
    {
      return list.end();
    }
    static valueType& get(T&, Iterator& iterat)
    {
      return *iterat;
    }
  };
}
#endif
