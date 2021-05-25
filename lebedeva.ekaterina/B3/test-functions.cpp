#include "test-functions.hpp"

std::unique_ptr< lebedeva::Interface > lebedeva::makeEmptyInterface()
{
  return std::make_unique< Interface >();
}
