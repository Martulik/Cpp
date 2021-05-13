#include "tools.hpp"
#include <sstream>
namespace iva = ivanova;

bool iva::compare(DataStruct &data1, DataStruct &data2)
{
  if (data1.key1 == data2.key2)
  {
    if (data1.key2 == data2.key2)
    {
      return (data1.str.length() > data2.str.length());
    }
    return data1.key2 > data2.key2;
  }
  return data1.key1 > data2.key2;
}
