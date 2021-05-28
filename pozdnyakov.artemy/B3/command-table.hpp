#ifndef COMMAND_TABLE_HPP
#define COMMAND_TABLE_HPP

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <functional>

namespace pozdnyakov
{
  class CommandTable
  {
  public:
    using patternType = std::vector< std::string >;
    using handlerType = std::function< bool(std::string) >;
    using patternsVector = std::vector< patternType >;
    using handlersMap = std::map< std::string, handlerType >;
    CommandTable(patternsVector patterns, handlersMap fhMap);
    bool checkCommand(std::vector< std::string > commandStr) const;
  private:
    const patternsVector patterns_;
    const handlersMap fieldHandlersMap_;
  };
}

#endif
