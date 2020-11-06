#include <iostream>
using namespace std;
/*派生类向基类转换会丢失派生类独有的成员,而基类无法自动转换为派生类,但可以强制转换.*/

class Item_base {
 public:
  Item_base(const string& book = "", double sale_price = 0.0)
      : isbn(book), price(sale_price) {}
  string book() const { return isbn; }
  virtual double net_price(size_t n) const {
    return n * price;
  }  // virtual关键字修饰的虚函数,可以在派生类中重新定义.

 private:
  string isbn;

 protected:  // proteced关键字,其声明成员用来继承.派生类可以使用,基类不可使用.
  double price;
};

class Bulk_item : public Item_base {
 public:
  Bulk_item(const string& book = "", double sale_price = 0.0, size_t qty = 0,
            double disc_rate = 0.0)
      : Item_base(book, sale_price), min_qty(qty), discount(disc_rate) {}

  double net_price(size_t cnt) const {
    if (cnt >= min_qty)
      return cnt * (1 - discount) * price;
    else
      return cnt * price;
  }
  size_t get_Qty() { return min_qty; }

 private:
  size_t min_qty;
  double discount;
};

void print_total_1(ostream& os, const Item_base item, size_t n) {
  os << "ISBN:" << item.book() << "\tnumber sold:" << n << "\ttotal price:\t"
     << item.net_price(n) << endl;
}

void print_total_2(ostream& os, const Item_base* item, size_t n) {
  os << "ISBN:" << item->book() << "\tnumber sold:" << n << "\ttotal price:\t"
     << item->net_price(n) << endl;
}

void print_total_3(ostream& os, const Item_base& item, size_t n) {
  os << "ISBN:" << item.book() << "\tnumber sold:" << n << "\ttotal price:\t"
     << item.net_price(n) << endl;
}

int main() {
  Item_base item("0-12-3456-789", 9.8);
  // cout << item.book() << "," << item.net_price(10) << endl;

  Bulk_item item2("0-12-3456-789", 9.9, 8, 0.12);
  // cout << item2.book() << "," << item2.net_price(10) << endl;
  print_total_1(cout, item, 10);
  print_total_1(cout, item2, 10);  // copy参数传入派生类,调用基类的方法.

  print_total_2(cout, &item2, 10);  //指针参数传入派生类,调用派生类的方法.
  print_total_3(cout, item2, 10);  //引用参数传入派生类,调用派生类的方法.

  Bulk_item* p = static_cast<Bulk_item*>(&item);  //将基类强制转换为派生类.
 
  return 0;
}