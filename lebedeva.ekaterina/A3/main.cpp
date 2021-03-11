#include <iostream>
#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

namespace l = lebedeva;

int main()
{
  std::cout << "Hello my new asspain!\n";
  l::CompositeShape collection;
  collection.push( std::make_shared< l::Rectangle >(l::point_t({0, 0}), 12, 3) );
  collection.push( std::make_shared< l::Circle >(l::point_t({ 9, 12 }), 3));
  collection.move({5, 5});
  collection.move(-6, 3);
  collection.scale(2);
  return 0;
}