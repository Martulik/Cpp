#include "helpFunctions.h"

#include "Contacts.h"

namespace lysenko
{
  Contacts::constIterator goToNextNote(Contacts::constIterator curr)
  {
    return ++curr;
  }

  Contacts::constIterator goToPrevNote(Contacts::constIterator curr)
  {
    return --curr;
  }

  Contacts::constIterator goTo(Contacts::constIterator curr, bool forward, int amount)
  {
    lysenko::Contacts::constIterator newCurr = curr;
    if (forward)
    {
      for (int i = 0; i < amount; ++i)
      {
        newCurr = goToNextNote(newCurr);
      }
    }
    else
    {
      for (int i = 0; i < amount; ++i)
      {
        newCurr = goToPrevNote(newCurr);
      }
    }
    return newCurr;
  }
}
