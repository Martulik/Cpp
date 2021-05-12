#ifndef ACCESS_HPP
#define ACCESS_HPP

namespace lebedeva
{
  template < typename T >
  struct bracketsAccess
  {
    using iterator = typename T::size_type;
    using valueType = typename T::value_type;

    static iterator begin(const T&)
    {
      return 0;
    }
    static iterator end(const T& vector)
    {
      return vector.size();
    }
    static valueType& get(T& vector, iterator index)
    {
      return vector[index];
    }
  };

  template < typename T >
  struct atAccess
  {
    using iterator = typename T::size_type;
    using valueType = typename T::value_type;

    static iterator begin(const T&)
    {
      return 0;
    }
    static iterator end(const T& vector)
    {
      return vector.size();
    }
    static valueType& get(T& vector, iterator index)
    {
      return vector.at(index);
    }
  };

  template < typename T >
  struct iteratorAccess
  {
    using iterator = typename T::size_type;
    using valueType = typename T::value_type;

    static iterator begin(T& list)
    {
      return list.begin();
    }
    static iterator end(T& list)
    {
      return list.end();
    }
    static valueType& get(T&, iterator iterat)
    {
      return *iterat;
    }
  };
}
#endif
