#include <iostream>
#include <string>
using namespace std;

class Animal {};              //基类
class Dog : public Animal {}; //派生类
class Cat : public Animal {};

class Item_base {
public:
  Item_base(const string &book = "", double sale_price = 0.0)
      : isbn(book), price(sale_price) {}
  string book() const { return isbn; }
  virtual double net_price(size_t n) const {
    return n * price;
  } // virtual关键字修饰的虚函数,可以在派生类中重新定义.

private:
  string isbn;

protected: // proteced关键字,其声明成员用来继承.派生类可以使用,基类不可使用.
  double price;
};

class Bulk_item : public Item_base {
public:
  Bulk_item(const string &book = "", double sale_price = 0.0, size_t qty = 0,
            double disc_rate = 0.0)
      : Item_base(book, sale_price), min_qty(qty), discount(disc_rate) {}

  double net_price(size_t cnt) const {
    if (cnt >= min_qty)
      return cnt * (1 - discount) * price;
    else
      return cnt * price;
  }

private:
  size_t min_qty;
  double discount;
};

int main() {
  Animal a;
  Dog d;
  Cat c;
  Item_base item("0-12-3456-789", 9.9); //书号,单价
  Bulk_item item2("1-12-2334-565", 9.8, 10, 0.12); //书号,单价,最小折扣数,折扣率
  cout << "计算Item1的总价" << item.net_price(20) << endl;
  cout << "计算Item2的总价" << item2.net_price(20) << endl;
  return 0;
}