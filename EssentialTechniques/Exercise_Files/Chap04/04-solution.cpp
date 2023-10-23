// 04-solution.cpp by Bill Weinman [bw.org]
// updated 2022-06-16
// MarcoPSM 2023-10-15
#include <iostream>

struct catalog_card {
  const char *title{};
  const char *author{};
  const char *publisher{};
  const char *subject{};
  const char *isbn{};
  const char *oclc{};
  short int ddc1{};
  short int ddc2{};
  short int year_pub{};
  short int year_acq{};
  short int quantity{};
};

int main() {
  catalog_card lc1{"The CGI Book",
                   "William E. Weinman",
                   "New Riders",
                   "CGI (Computer network protocol)",
                   "1562055712 9781562055714",
                   "477166381",
                   510,
                   78,
                   1996,
                   1997,
                   2};

  std::cout << "Title: " << lc1.title << std::endl;
  std::cout << "Author: " << lc1.author << std::endl;
  std::cout << "Publisher: " << lc1.publisher << std::endl;
  std::cout << "Subject: " << lc1.subject << std::endl;
  std::cout << "ISBN: " << lc1.isbn << std::endl;
  std::cout << "WorldCat (OCLC): " << lc1.oclc << std::endl;
  std::cout << "Dewey Decimal: " << lc1.ddc1 << " " << lc1.ddc2 << std::endl;
  std::cout << "Year published: " << lc1.year_pub << std::endl;
  std::cout << "Year acquired: " << lc1.year_acq << std::endl;
  std::cout << "Quantity: " << lc1.quantity << std::endl;
}
