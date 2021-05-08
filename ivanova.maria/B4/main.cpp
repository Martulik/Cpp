#include <iostream>
#include <vector>
#include "struct.hpp"
#include "task.hpp"

namespace iva = ivanova;

int main()
{
  std::vector < iva::DataStruct > vector;
  return iva::task(vector);
}
