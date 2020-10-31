/*当数据成员中有指针时,需要自己写复制构造函数和赋值操作符重载,因为默认的
复制构造函数和赋值操作符只是简单的复制了指针而没有对指针的内容进行操作*/

/*自动生成的构造函数在存在指针数据的情况下,直接复制指针,形成浅copy,多个
对象的指针数据共享一个地址,会造成对象间的数据修改.通过自己写的复制构造函
数,取出指针对应的内容,再把内容给调用对象指针数据,达到深复制.*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NoName {
 public:
  NoName() : pstring(new string), i(0), d(0) {}

  //复制构造函数,因为数据成员有指针,所以不能使用默认提供的复制构造函数,需要自己写.将传入对象的pstring中的字符串拿出后建立一个新的字符串对象,然后给调用对象的pstring.
  NoName(NoName &nm) : pstring(new string(*(nm.pstring))), i(nm.i), d(nm.d) {}

  //赋值操作符
  NoName &operator=(const NoName &rhs) {
    pstring = new string;
    *pstring = *(rhs.pstring);
    i = rhs.i;
    d = rhs.d;
    return *this;
  }

 private:
  string *pstring;
  int i;
  double d;
};
class Sales_item {
 public:
  Sales_item() : units_sold(0), revenue(0) { cout << "默认的构造函数" << endl; }
  Sales_item(const string &book) : isbn(book), units_sold(0), revenue(0.0) {
    cout << "Sale_item(const string &book)被调用" << endl;
  }

  //复制构造函数,在建立对象时将构造函数实参的值复制给新对象.简单说就是建立一个和参数相同的对象.
  Sales_item(const Sales_item &orig)
      : isbn(orig.isbn), units_sold(orig.units_sold), revenue(orig.revenue) {
    cout << "复制构造函数被调用" << endl;
  }

  //赋值操作符,将传入的对象的每个数据成员对新对象进行复制,并返回一个新对象.
  Sales_item &operator=(const Sales_item &rhs) {
    isbn = rhs.isbn;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    cout << "赋值操作符被调用了" << endl;
    return *this;
  }

 private:
  string isbn;
  unsigned units_sold;
  double revenue;
};

Sales_item foo(Sales_item item) {
  Sales_item temp;
  temp = item;
  return temp;
}

int main() {
  NoName d;
  NoName e;
  NoName f(d);
  Sales_item a;
  Sales_item b("0-201-78345-X");
  Sales_item c(b);
  a = b;

  Sales_item item = string("9-999-99999-9");

  cout << endl << "foo结果:" << endl;
  Sales_item ret;
  ret = foo(a);

  cout << endl << "vector结果" << endl;
  vector<Sales_item> svec(5);

  cout << endl << "数组的结果" << endl;
  Sales_item primer_eds[] = {string("0-210-123456-7"), string("0-210-123454-9"),
                             string("0-210-123223-6"), Sales_item()};

  return 0;
}