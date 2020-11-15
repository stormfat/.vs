#include <iostream>
#include "smart_pointer.h"

using namespace std;
class Dog {};

void demo1() {
  double d;
  d = 25.5;
  double *pd = new double;
  *pd = 25.5;
  Dog *pDog = new Dog();
  cout << d << endl;
  cout << *pd << endl;
  delete pd;//防止内存泄漏
  delete pDog;
  return;
}

void demo2() {
  auto_ptr<double> pd(new double);//使用智能指针,可以不写delete.
  *pd = 28.5;
  smart_pointer<Dog> spDog(new Dog());
  cout << *pd << endl;
}
int main() {
  demo1();
  demo2();
  return 0;
}