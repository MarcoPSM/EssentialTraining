// typedef.cpp by Bill Weinman [bw.org]
// updated 2022-06-16
// MarcoPSM 2023-10-15
#include <cstdint>
#include <iostream>

typedef uint32_t points_t;
typedef uint64_t rank_t;
// equal to
// using points_t = uint32_t;
// using rank_t = uint64_t;

struct score {
  points_t p{};
  rank_t r{};
};

int main() {
  score s{5, 1};
  printf("score s had %d points and a rank of %ld\n", s.p, s.r);
}
