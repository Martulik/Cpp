#include "test-functions.hpp"

std::unique_ptr< lebedeva::Interface > lebedeva::makeEmptyInterface()
{
  return std::make_unique< Interface >();
}

void lebedeva::addRec(std::unique_ptr< Interface >& src)
{
  if (src->empty())
  {
    src->add(rec1);
  }
  else
  {
    src->add(rec2);
  }
}

bool lebedeva::storeRec(std::unique_ptr< Interface >& src)
{
  bool bResult = false;
  if (src->find(markname1) != src->end())
  {
    if (src->find(markname2) == src->end())
    {
      src->move(cur, posStep);
      if (src->find(cur) != src->end())
      {
        src->store(cur, markname2);
        bResult = true;
      }
      src->move(cur, first);
    }
    else if (src->find(markname3) == src->end())
    {
      src->move(cur, posStep);
      src->store(cur, markname3);
      bResult = true;
    }
  }
  else if(!src->empty())
  {
    src->store(cur, markname1);
    bResult = true;
  }
  else
  {
    src->store(markname1, newmarkname1);
  }
  return bResult;
}

bool lebedeva::insertRec(std::unique_ptr< Interface >& src)
{
  bool bResult = false;
  if (!src->empty())
  {
    if (src->find(markname2) == src->end())
    {
      src->insert(aft, markname1, rec2);
      bResult = true;
    }
    else if (src->find(markname3) == src->end())
    {
      src->move(cur, last);
      src->insert(bef, markname2, rec3);
      bResult = true;
    }
  }
  else
  {
    src->insert(aft, markname1, rec2);
  }
  return bResult;
}

bool lebedeva::moveMark(std::unique_ptr< Interface >& src, int n)
{
  bool bResult = false;
  if (!src->empty())
  {
    if (n == posStep)
    {
      src->move(cur, posStep);
      bResult = true;
    }
    if (n == negStep)
    {
      src->move(cur, negStep);
      bResult = true;
    }
    if (n == zeroStep)
    {
      src->move(cur, zeroStep);
      bResult = true;
    }
    if (n == commandFirst)
    {
      src->move(cur, first);
      bResult = true;
    }
    if (n == commandLast)
    {
      src->move(cur, last);
      bResult = true;
    }
  }
  else
  {
    src->move(markname1, n);
    src->move(markname1, first);
  }
  return bResult;
}

bool lebedeva::deleteMark(std::unique_ptr< Interface >& src)
{
  bool bResult = false;
  if (!src->empty())
  {
    if (src->find(markname1) != src->end())
    {
      src->deleteRec(markname1);
      bResult = true;
    }
    else if (src->find(markname2) != src->end())
    {
      src->deleteRec(markname2);
      bResult = true;
    }
    else if (src->find(markname3) != src->end())
    {
      src->deleteRec(markname3);
      bResult = true;
    }
  }
  else
  {
    src->deleteRec(markname1);
  }
  return bResult;
}
