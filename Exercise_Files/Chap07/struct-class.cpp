// struct-class.cpp by Bill Weinman [bw.org]
// updated 2022-06-02
// MarcoPSM 2023-10-19
#include <iostream>

struct A {
  int ia{};
  int ib{};
  int ic{};
};

int main() {
  A o1{47, 73, 103};
  printf("ia %d, ib %d, ic %d\n", o1.ia, o1.ib, o1.ic);
}
