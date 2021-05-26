#include "tasks.hpp"
#include "interface.hpp"

namespace poz = pozdnyakov;

void poz::task1(std::istream& in, std::ostream& out)
{
  std::unique_ptr< poz::Phonebook > bookPtr = std::make_unique< poz::Phonebook >();
  poz::Interface interface(std::move(bookPtr), in, out);
  interface.start();
}
