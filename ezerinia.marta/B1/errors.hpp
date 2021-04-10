#ifndef ERRORS_HPP
#define ERRORS_HPP

namespace ezerinia {
  enum class error: int {
    success,
    task_number,
    number_args,
    sort_mode,
    task_failed,
    input
  };

  bool isNoErrors(const error err);
}
#endif
