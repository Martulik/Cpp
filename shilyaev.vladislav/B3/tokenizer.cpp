#include "tokenizer.hpp"

std::vector< std::string > shilyaev::tokenize(const std::string &original)
{
  std::vector< std::string > tokens(1);
  bool isInsideQuotes = false;
  bool doEscapeNext = false;
  for (char character: original) {
    if (std::isspace(character)) {
      if (isInsideQuotes) {
        tokens.back() += character;
      } else {
        tokens.emplace_back();
      }
    } else if (character == '"' && !doEscapeNext) {
      isInsideQuotes = !isInsideQuotes;
      tokens.back() += character;
    } else if (character == '\\' && !doEscapeNext) {
      doEscapeNext = true;
    } else {
      tokens.back() += character;
      doEscapeNext = false;
    }
  }
  return tokens;
}
