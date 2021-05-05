#include <vector>
#include "struct.hpp"
#include "task.hpp"

namespace iva = ivanova;

int main()
{
  std::vector < iva::DataStruct > vector;
  iva::task(vector);
  return 0;
}
