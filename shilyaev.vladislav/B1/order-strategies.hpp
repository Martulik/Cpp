#ifndef ORDER_STRATEGIES_HPP
#define ORDER_STRATEGIES_HPP

namespace shilyaev {

  struct AscendingOrder {
    template < typename T >
    static bool isOrdered(T a, T b);
  };

  struct DescendingOrder {
    template < typename T >
    static bool isOrdered(T a, T b);
  };

  template < typename T >
  bool AscendingOrder::isOrdered(T a, T b)
  {
    return a <= b;
  }

  template < typename T >
  bool DescendingOrder::isOrdered(T a, T b)
  {
    return a >= b;
  }

}

#endif
