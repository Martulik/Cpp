#ifndef HELP_FUNCTIONS_H
#define HELP_FUNCTIONS_H

#include "Contacts.h"

namespace lysenko
{
  Contacts::constIterator goToNextNote(Contacts::constIterator curr);
  Contacts::constIterator goToPrevNote(Contacts::constIterator curr);
  Contacts::constIterator goTo(Contacts::constIterator curr, bool forward, int amount);
}

#endif
