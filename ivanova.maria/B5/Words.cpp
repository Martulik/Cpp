//#include "Words.hpp"
//#include <iostream>
//#include <iterator>
//
//std::istream &ivanova::operator >>(std::istream &in, ivanova::Words &list)
//{
//  std::istream_iterator< std::string > input(in);
//  std::vector< std::string > newVec (input, std::istream_iterator< std::string > ());
//  list.pushback(newVec);
//  return in;
//}
//
//std::ostream &ivanova::operator <<(std::ostream &out, ivanova::Words &str)
//{
//  std::copy(str.begin(), str.end(), std::ostream_iterator< std::string > (out, "\n"));
//  return out;
//}
//
//void ivanova::Words::pushback(std::vector<std::string> vec)
//{
//  this->vector_ = std::move(vec);
//}
//
//std::vector<std::string>::const_iterator ivanova::Words::begin()
//{
//  return this->vector_.begin();
//}
//
//std::vector<std::string>::iterator ivanova::Words::end()
//{
//  return this->vector_.end();
//}
