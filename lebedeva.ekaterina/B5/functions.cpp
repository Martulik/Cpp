#include "functions.hpp"
#include <iterator>
#include <iostream>

std::set< std::string > lebedeva::doInputWords(std::istream& in)
{
  std::istream_iterator< std::string > inIterFirst(in);
  std::istream_iterator< std::string > inIterLast;
  std::set< std::string > words(inIterFirst, inIterLast);
  return words;
}

void lebedeva::doOutputWords(std::ostream& out, std::set< std::string >& words)
{
  std::ostream_iterator< std::string > outIter(out, "\n");
  std::copy(words.begin(), words.end(), outIter);
}

std::vector< lebedeva::Shape > lebedeva::doInputShapes(std::istream& in)
{
  std::istream_iterator< Shape > inIterFirst(in);
  std::istream_iterator< Shape > inIterLast;
  /*if (!in && !in.eof())
  {
    throw std::runtime_error("Stream reading error");
  }*/
  std::vector< Shape > inVec(inIterFirst, inIterLast);
  return inVec;
}

void lebedeva::doSomeOutput(std::ostream& out, std::vector< Shape > shapes)
{
  std::ostream_iterator< Shape > outIter(out, "\n");
  std::copy(shapes.begin(), shapes.end(), outIter);
}
