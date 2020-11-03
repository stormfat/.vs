/*转换函数:
1.必须是成员函数
2.不能指定返回值
3.形参列表必须是空
4.必须显示地返回一个指定类型的值
5.不应该改变被转换对象,通常定义为const*/
#include <iostream>
#include <string>
using namespace std;

class Dog {
public:
  Dog(string n, int a, double w) : name(n), age(a), weight(w) {}
  operator double() const {
    return weight;
  } //将对象转化为需要的类型,并返回一个相应类型的值
  operator int() const { return age; }

private:
  int age;
  double weight;
  string name;
};

int main() {
  int a, b;
  double c;
  a = 10;
  b = a;
  Dog d("bill", 2,
        3.0); //存在转换函数,对象转换成string类型,并将name成员值返回.
  Dog e("jim", 3, 4.0);
  c = d;
  b = e;
  cout << c << endl;
  cout << b << endl;
  return 0;
}