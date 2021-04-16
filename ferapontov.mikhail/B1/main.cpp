#include <iostream>
#include <sstream>

template< typename T >
T readArg(std::string arg)
{
  T res;
  std::stringstream in(arg);
  in >> res;
  return res;
}

int main(int argc, char *argv[])
{
  std::cout << argc  << '\n';
  int TaskNumber = readArg< int >(argv[1]);
  std::string way = readArg< std::string >(argv[2]);
  std::cout << TaskNumber << ' '<< way << '\n';
  return 0;
}
