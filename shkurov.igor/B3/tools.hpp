#include <string>
#include <utility>

using number_t = unsigned long long;
using node_t = std::pair< std::string, number_t >;

namespace shkurov
{
  number_t stringToNumber(const std::string& str);
  std::string nameCorrection(std::string str);
  bool isNumber(const std::string& str);
  bool isCorrectBookmarkName(const std::string& str);
  void printNode(std::ostream& out, const node_t& pair);
}
