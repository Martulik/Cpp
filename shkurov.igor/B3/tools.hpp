#include <string>
#include <utility>

using node_t = std::pair< std::string, std::string >;

namespace shkurov
{
  std::string nameCorrection(std::string str);
  bool isNumber(const std::string& str);
  bool isCorrectBookmarkName(const std::string& str);
  void printNode(std::ostream& out, const node_t& pair);
}
