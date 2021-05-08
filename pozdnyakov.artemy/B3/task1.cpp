#include "tasks.hpp"
#include <iostream>
#include <sstream>
#include <iterator>
#include "interface.hpp"

namespace poz = pozdnyakov;

void poz::task1()
{
  std::cout << "Started task 1" << '\n';
  std::unique_ptr< poz::Phonebook > bookPtr = std::make_unique< poz::Phonebook >();
  poz::Interface interface(std::move(bookPtr), std::cout);
  {
    std::vector< std::string > args;
    std::string buf;
    std::stringstream ssbuf;
    std::istream_iterator< std::string > eos;
    std::istream_iterator< std::string > begin;
    while(!std::cin.eof())
    {
      std::getline(std::cin, buf);
      ssbuf << buf;
      begin = std::istream_iterator< std::string >(ssbuf);
      eos = std::istream_iterator< std::string >();
      args = std::vector< std::string >(begin, eos);
      interface.doCommand(args);
      ssbuf.clear();
    }
  }
}
