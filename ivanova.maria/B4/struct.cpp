#include "struct.hpp"

namespace iva = ivanova;

bool iva::DataStruct::operator >(const DataStruct &data) const
{
  if (this->key1 > data.key1)
  {
    return true;
  }
  else if (this->key1 == data.key1)
  {
    if (this->key2 > data.key2)
    {
      return true;
    }
    else if (this->key2 == data.key2)
    {
      if (this->str.length() > data.str.length())
      {
        return true;
      }
      else return false;
    }
    else return false;
  }
  else return false;
}

