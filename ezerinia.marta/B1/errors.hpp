#ifndef ERRORS_HPP
#define ERRORS_HPP

namespace ezerinia {
  enum class error: int {
    success,
    taskNumber,
    numberArgs,
    sortMode,
    taskFailed,
    input
  };

  bool isNoErrors(const error &err);
}
#endif
