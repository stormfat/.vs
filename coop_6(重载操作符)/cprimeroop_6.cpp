//不可重载的操作符:: .* . ?:

#include <iostream>
#include <string>

using namespace std;
class Sales_item {
  friend ostream& operator<<(ostream&, const Sales_item&);
  friend istream& operator>>(istream& in, Sales_item& s);

 public:
  Sales_item(const string& book, unsigned units, double price)
      : isbn(book), units_sold(units), revenue(price * units) {}
  Sales_item() : units_sold(0), revenue(0.0) {}
  Sales_item& operator+=(const Sales_item&);
  Sales_item& operator-=(const Sales_item&);
  double get_rev() { return this->revenue; }

 private:
  string isbn;
  unsigned units_sold;
  double revenue;
};

Sales_item& Sales_item::operator+=(const Sales_item& rhs)  //重载+=操作符
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_item& Sales_item::operator-=(const Sales_item& rhs)  //重载-=操作符
{
  units_sold -= rhs.units_sold;
  revenue -= rhs.revenue;
  return *this;
}

Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs) {
  Sales_item ret(lhs);
  ret += rhs;
  return ret;
}

ostream& operator<<(ostream& out, const Sales_item& s)  //重载输出操作符
{
  out << s.isbn << "\t" << s.units_sold << "\t" << s.revenue;
  return out;
}

istream& operator>>(istream& in, Sales_item& s)  //重载输入操作符
{
  double price;
  in >> s.isbn >> s.units_sold >> price;
  if (in)
    s.revenue = s.units_sold * price;
  else  //如果输入流输入错误,则生成一个新的对象.
    s = Sales_item();
  return in;
}

int main() {
  cout << "hello" << endl;
  Sales_item item(string("0-201-78345-X"), 11, 21.0);
  cout << item << endl;
  // cin >> item;
  // cout << item << endl;
  Sales_item item1(string("0-301-35235-B"), 12, 32.0);

  item1 += item;
  cout << item1.get_rev() << endl;
  Sales_item item3 = item + item1;
  cout << item3<< endl;
  item3 -= item1;
  cout << item3 << endl;

  return 0;
}