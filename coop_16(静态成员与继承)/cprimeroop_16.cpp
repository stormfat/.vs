#include <iostream>
#include <string>
using namespace std;
/*基类的static成员,在整个继承层次中只有一个实例
在派生类中访问static成员的方法有:
1.基类名::成员名
2.派生类名::成员名
3.对象.成员名
4.指针.成员名
5.成员名*/

class A {
 public:
  static size_t object_count() { return 100; }

 protected:
  static size_t obj_count;
};
size_t A::obj_count = 99;
class B : public A {
 public:
  void f(const B &b, B *b2) {
    cout << A::obj_count << endl;
    cout << B::obj_count << endl;
    cout << b.obj_count << endl;
    cout << obj_count << endl;
    cout << b2->obj_count << endl;

    cout << A::object_count() << endl;
    cout << B::object_count() << endl;
    cout << b.object_count() << endl;
    cout << object_count() << endl;
    cout << b2->object_count() << endl;
  }
};

class C : public B {};
int main() {
  B b;
  b.f(b, &b);
  return 0;
}