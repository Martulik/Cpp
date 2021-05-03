#include <boost/test/unit_test.hpp>
#include "tokenizer.hpp"

BOOST_AUTO_TEST_CASE(Tokenizer)
{
  std::pair< std::string, std::vector< std::string > > pairs[]{
    std::make_pair(R"(add 123 "qwe qwe")", std::vector< std::string >{"add", "123", R"("qwe qwe")"}),
    std::make_pair(R"(add 123 "qwe\" qwe")", std::vector< std::string >{"add", "123", R"("qwe" qwe")"}),
    std::make_pair(R"(add 123 "qwe\\ qwe")", std::vector< std::string >{"add", "123", R"("qwe\ qwe")"}),
  };
  for (auto &&pair: pairs) {
    BOOST_CHECK(shilyaev::tokenize(pair.first) == pair.second);
  }
}
