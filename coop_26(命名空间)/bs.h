#pragma once
#ifndef _BS_H
#define _BS_H
#include <string>
//头文件不要写using std::string;或using namespace std;

namespace bookStore {
class Sales_item {
 public:
  Sales_item(const std::string &book = "") : isbn(book), units_sold(0), revenue(0) {}
  double avg_price() const;

 private:
  std::string isbn;
  unsigned units_sold;
  double revenue;
};
}  // namespace bookStore
#endif  // !_BS_H
