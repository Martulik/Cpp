#include "helpFunctions.h"

#include "Contacts.h"

namespace lysenko
{
  Contacts::constIteratorNote goToNextNote(Contacts::constIteratorNote curr)
  {
    return ++curr;
  }

  Contacts::constIteratorNote goToPrevNote(Contacts::constIteratorNote curr)
  {
    return --curr;
  }

  Contacts::constIteratorNote goTo(Contacts::constIteratorNote curr, bool forward, int amount)
  {
    Contacts::constIteratorNote newCurr = curr;
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
