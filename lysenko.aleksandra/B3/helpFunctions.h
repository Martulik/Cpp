#ifndef HELP_FUNCTIONS_H
#define HELP_FUNCTIONS_H

#include "Contacts.h"

namespace lysenko
{
  Contacts::constIteratorNote goToNextNote(Contacts::constIteratorNote curr);
  Contacts::constIteratorNote goToPrevNote(Contacts::constIteratorNote curr);
  Contacts::constIteratorNote goTo(Contacts::constIteratorNote curr, bool forward, int amount);
}

#endif
