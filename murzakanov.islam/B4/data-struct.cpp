#include "data-struct.hpp"

std::istream& murzakanov::operator>>(std::istream& in, DataStruct& data)
{
  std::istream::sentry sentry(in);

  if (sentry)
  {
    int key1;
    int key2;
    std::string str;

    {
      in >> key1;
      readDelimiter(in, ',');
      in >> key2;
      readDelimiter(in, ',');
      str = readString(in);
    }

    if (in)
    {
      data = DataStruct{ key1, key2, str };
    }
  }

  return in;
}

std::ostream& murzakanov::operator<<(std::ostream& out, const DataStruct& data)
{


  return out;
}

static bool murzakanov::readDelimiter(std::istream& in, char delimiter)
{
  in >> std::ws;
  if (in.peek() != delimiter)
  {
    in.setstate(std::istream::failbit);
    return false;
  }
  char c;
  in >> c;
  return true;
}

static std::string murzakanov::readString(std::istream& in)
{
  std::string result;
  getline(in, result, '\n');
  return result;
}