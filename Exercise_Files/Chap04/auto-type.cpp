// auto-type.cpp by Bill Weinman [bw.org]
// updated 2022-05-25
// MarcoPSM 2023-10-15
#include <iostream>
#include <typeinfo>

int main() {
  std::string s{"This is a string"};
  auto x = s;
  std::cout << "x is " << x << std::endl;
  std::cout << "type of x is " << typeid(x).name() << std::endl;
}
