#include "tools.hpp"
namespace iva = ivanova;

bool iva::compare(const DataStruct &data1, const DataStruct &data2)
{
  if (data1.key1 != data2.key1) {
    return data1.key1 < data2.key1;
  } else if (data1.key2 != data2.key2) {
    return data1.key2 < data2.key2;
  } else {
    return data1.str.length() < data2.str.length();
  }
}
