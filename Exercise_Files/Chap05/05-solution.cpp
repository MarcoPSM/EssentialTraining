// 05-solution.cpp by Bill Weinman <http://bw.org/>
// updated 2022-05-26
// MarcoPSM 2023-10-19
#include <iostream>

int main() {
  bool prime_flag{false};

  // outer loop for prime candidates 2-99
  for (auto candidate = 2; candidate < 100; ++candidate) {

    // test candidate for factors
    prime_flag = true;
    for (auto factor = 2; factor < candidate; ++factor) {
      if (candidate % factor == 0) {
        prime_flag = false;
        break;
      }
    }

    // print if it's prime
    if (prime_flag)
      std::cout << candidate << " ";
  }

  // end with a newline
  std::cout << std::endl;
}
