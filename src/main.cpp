/// @file
/// @brief Main program body
#include <mbed.h>

#include "AwaitInterval.hpp"

/// @brief The application entry point.
int main() {
  // put your setup code here, to run once:
  printf("\nsetup\n");
  while(1) {
    // put your main code here, to run repeatedly:
    if(static AwaitInterval<HighResClock> wait; auto elapsed = wait(10ms)) {
      printf("%lld\n", elapsed.count());
    }
  }
}
