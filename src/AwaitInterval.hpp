#ifndef RCT_AWAIT_INTERVAL_HPP_
#define RCT_AWAIT_INTERVAL_HPP_
/// @file
/// @brief Provides AwaitInterval class.
/// @copyright Copyright (c) 2023 Yoshikawa Teru
/// @license This project is released under the MIT License, see [LICENSE](https://github.com/teruyamato0731/AwaitInterval_test/blob/main/LICENSE).

#include <chrono>

/// @brief Await time intervals in non-blocking and measure the elapsed time.
template<class Clock = std::chrono::steady_clock>
struct AwaitInterval {
  AwaitInterval() : pre_{Clock::now()} {}
  auto operator()(typename Clock::duration wait = {}) {
    auto now = Clock::now();
    auto delta = now - pre_;
    auto elapsed = delta > wait;
    if(elapsed) reset(now);
    return Result{delta, elapsed};
  }
  void reset(typename Clock::time_point init = Clock::now()) {
    pre_ = init;
  }
 private:
  struct Result : Clock::duration {
    constexpr explicit operator bool() const {
      return elapsed;
    }
    bool elapsed;
  };
  typename Clock::time_point pre_;
};

#endif  // RCT_AWAIT_INTERVAL_HPP_
