#include "UserInterface.hpp"
#include <iostream>
#include <sstream>
#include "record_t.hpp"

namespace lab = ezerinia;

lab::UserInterface::UserInterface(std::ostream &stream):
  book_(),
  stream_(stream)
{
}

std::string lab::UserInterface::getMarkName(std::string markName)
{
  if (markName.empty()) {
    return "";
  }
  for (char i: markName) {
    if ((!std::isalnum(i)) && (i != '-')) {
      return "";
    }
  }
  return markName;
}

void lab::UserInterface::add(std::stringstream &input)
{
  record_t record;
  input >> record;

  if (record.name.empty() || record.number.empty()) {
    invalidCommand(stream_);
  } else {
    book_.add(record);
  }
}

void lab::UserInterface::store(std::stringstream &input)
{
  std::string oldMarkName;
  input >> std::ws >> oldMarkName;
  oldMarkName = getMarkName(oldMarkName);

  std::string newMarkName;
  input >> std::ws >> newMarkName;
  newMarkName = getMarkName(newMarkName);

  if (oldMarkName.empty() || newMarkName.empty() || !book_.containsBookmark(oldMarkName)) {
    invalidCommand(stream_);
  } else {
    book_.store(oldMarkName, newMarkName);
  }
}

void lab::UserInterface::insert(std::stringstream &input)
{
  std::string direction;
  input >> std::ws >> direction;

  std::string markName;
  input >> std::ws >> markName;
  markName = getMarkName(markName);

  record_t record;
  input >> record;

  if (markName.empty() || !book_.containsBookmark(markName) || record.number.empty() || record.name.empty()) {
    invalidCommand(stream_);
  } else {
    if (direction == "before") {
      book_.insert(markName, record, lab::Book::posOfInsert::before);
    } else if (direction == "after") {
      book_.insert(markName, record, lab::Book::posOfInsert::after);
    } else {
      invalidCommand(stream_);
    }
  }
}

void lab::UserInterface::deleteRecord(std::stringstream &input)
{
  std::string markName;
  input >> std::ws >> markName;
  markName = getMarkName(markName);
  if (markName.empty() || !book_.containsBookmark(markName)) {
    invalidCommand(stream_);
  } else {
    book_.deleteRecord(markName);
  }
}

void lab::UserInterface::show(std::stringstream &input)
{
  std::string markName;
  input >> std::ws >> markName;
  markName = getMarkName(markName);
  if (markName.empty()) {
    invalidCommand(stream_);
  } else if (!book_.containsBookmark(markName)) {
    invalidBookmark(stream_);
  } else if (book_.empty()) {
    empty(stream_);
  } else {
    const std::map< std::string, PhoneBook::const_iterator >::const_iterator &iter = book_.findBookmark(markName);
    stream_ << *iter->second;
  }
}

void lab::UserInterface::move(std::stringstream &input)
{
  std::string markName;
  input >> std::ws >> markName;
  markName = getMarkName(markName);
  if (markName.empty() || !book_.containsBookmark(markName)) {
    invalidCommand(stream_);
    return;
  }
  std::string num;
  input >> std::ws >> num;
  if (num == "first") {
    book_.move(markName, lab::Book::posOfMove::first);
  } else if (num == "last") {
    book_.move(markName, lab::Book::posOfMove::last);
  } else {
    try {
      int steps = std::stoi(num);
      book_.move(markName, steps);
    }
    catch (const std::invalid_argument &) {
      invalidStep(stream_);
    }
  }
}

void lab::invalidCommand(std::ostream &out)
{
  out << "<INVALID COMMAND>\n";
}

void lab::invalidBookmark(std::ostream &out)
{
  out << "<INVALID BOOKMARK>\n";
}

void lab::empty(std::ostream &out)
{
  out << "<EMPTY>\n";
}

void lab::invalidStep(std::ostream &out)
{
  out << "<INVALID STEP>\n";
}
