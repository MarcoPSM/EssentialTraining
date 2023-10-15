// float-types.cpp by Bill Weinman [bw.org]
// updated 2022-06-16
// MarcoPSM 2023-10-15
#include <iostream>

// a byte is 8 bits
const size_t byte{8};

int main() {
  float f{};
  double df{};
  long double ldf{};

  std::cout << "size of float f is " << sizeof(f) * byte << " bits"
            << std::endl;
  printf("size of float f is %lu bits\n", sizeof(f) * byte);
  printf("size of double df is %lu bits\n", sizeof(df) * byte);
  printf("size of long double ldf is %lu bits\n", sizeof(ldf) * byte);

  f = .1 + .1 + .1;

  std::cout << ((f == 0.3) ? "true" : "false") << std::endl;

  df = .1 + .1 + .1;
  printf("value of double df is %.20f \n", df);
}
