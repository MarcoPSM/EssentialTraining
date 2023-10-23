// string.cpp by Bill Weinman [bw.org]
// updated 2022-06-21
// MarcoPSM 2023-10-21
#include <iostream>
#include <string>

int main() {
  std::string s1{"This is a string"};

  // size & length
  printf("length is same as size: %d\n", s1.length());
  printf("size is same as length: %d\n", s1.size());

  // + for concatenation
  std::cout << "concatenated strings: ";
  std::string s2 = s1 + " : " + "this is also a string";
  std::cout << s2;
  std::cout << '\n';

  // compare
  printf("is s1 == s2? %d\n", s1 == s2 ? "yes" : "no");
  std::cout << "copy-assign s2 = s1\n";
  s2 = s1;
  printf("is s1 == s2? %s\n", s1 == s2 ? "yes" : "no");

  std::string otherstr{"other string"};
  printf("is s1 > otherstr? %s\n", s1 > otherstr ? "yes" : "no");
  printf("is s1 < otherstr? %s\n", s1 < otherstr ? "yes" : "no");
  printf("is otherstr > s1? %s\n", otherstr > s1 ? "yes" : "no");
  printf("is otherstr < s1? %s\n", otherstr < s1 ? "yes" : "no");
  std::cout << '\n';

  // iteration
  std::cout << "each character: ";
  for (const auto &c : s1) {
    // printf("%s ", c);
    std::cout << c << " ";
  }
  std::cout << '\n';

  // insert & erase with an iterator
  s1.insert(s1.begin() + 5, 'X');
  printf("s1 after insert: %s\n", s1.c_str());

  s1.erase(s1.begin() + 5);
  printf("s1 after erase: %s\n", s1.c_str());
  std::cout << '\n';

  // replace
  s1.replace(5, 2, "ain't");
  printf("s1 after replace: %s\n", s1.c_str());

  // substr
  printf("substr: %s\n", s1.substr(5, 5).c_str());

  // find
  size_t pos = s1.find("s");
  printf("find first \"s\" in s1 (pos): %d\n", pos);

  // rfind
  pos = s1.rfind("s");
  printf("find last \"s\" in s1 (pos): %d\n", pos);
}
