#include "errors.hpp"

namespace lab = ezerinia;

bool lab::isNoErrors(const error &err)
{
  return err == lab::error::success;
}
