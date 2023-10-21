// pointer-incr.cpp by Bill Weinman <http://bw.org/>
// updated 2020-05-26
// MarcoPSM 2023-10-19
#include <cstdint>
#include <iostream>

using int_type = uint16_t; // uint8_t uint16_t uint32_t

void printp(const int_type *p) {
  std::cout << "pointer is " << static_cast<const void *>(p) << ", value is "
            << (int)*p << std::endl;
}

int main() {
  int_type arr[]{1, 2, 3, 4, 5};
  int_type *p = arr;
  printp(p++);
  printp(p++);
  printp(p++);
}
