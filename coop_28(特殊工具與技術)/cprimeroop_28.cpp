#include <iostream>

class Item_base {
 public:
  virtual double net_price(size_t n) const { return n * price; }
  std::string test;

 private:
  std::string isbn;

 protected:
  double price;
};

class Bulk_item : public Item_base {
 public:
  double net_price(size_t cnt) const {
    return cnt > min_qty ? (cnt * (1 - discount) * price) : (cnt * price);
  }

 private:
  size_t min_qty;
  double discount;
};

int main() {
  Item_base *pItem = new Item_base();
  std::allocator<Item_base> a;  //用allocator代替new,只分配内存,不創建對象.
  a.allocate(2);
  Bulk_item *dp = new Bulk_item();
  Item_base *pItem2 = dp;                             //向上轉型
  Bulk_item *dp2 = dynamic_cast<Bulk_item *>(pItem);  // RTTI,運行時動態識別
  std::string Item_base::*p = &Item_base::test;  //定義一個指向類成員的指針
  double (Item_base::*pmf)(size_t) const =
      &Item_base::net_price;  //定義一個指向類方法的指針

  return 0;
}