#include "DataStruct.h"

bool lysenko::isGreater(const DataStruct& firstOp, const DataStruct& secondOp)
{
  if (firstOp.key1 < secondOp.key1)
  {
    return 1;
  }
  if (firstOp.key1 == secondOp.key1)
  {
    if (firstOp.key2 < secondOp.key2)
    {
      return 1;
    }
    if (firstOp.key2 == secondOp.key2)
    {
      return (firstOp.str.length() < secondOp.str.length());
    }
  }
  return 0;
}