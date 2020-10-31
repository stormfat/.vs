#include <iostream>
#include <string>

#include "plain-ptr.h"  //浅复制头文件
#include "smart-ptr.h"  //智能指针头文件
#include "value-ptr.h"  //深复制头文件
using namespace std;

void test_AHasPtr() {
  int i = 42;
  AHasPtr p1(&i, 42);
  AHasPtr p2 = p1;
  cout << "修改P1.val前,p2.ptr指向的值:" << p2.get_ptr_val() << endl;
  p1.set_ptr_val(
      0);  //浅复制导致修改p1.ptr指向的值,会同时影响到p2.ptr,因为两个对象ptr指向的是同一地址.
  cout << "修改P1.val后,p2.ptr指向的值:" << p2.get_ptr_val() << endl;

  int *ip = new int(42);
  AHasPtr p3(ip, 10);
  cout << "p3.ptr的值:" << p3.get_ptr_val() << endl;
  delete ip;  //因为ip指针的地址和p3.ptr共享,当ip被删除后,p3.ptr变成了悬垂指针.里面的值不确定.
  cout << "删除ip后,p3.ptr的值:" << p3.get_ptr_val() << endl;

  int l = 52;
  AHasPtr_value p4(&l, 52);
  AHasPtr_value p5 = p4;
}

void test_AHasPtr_value() {
  int obj = 0;
  AHasPtr_value vptr1(&obj, 42);
  AHasPtr_value vptr2(vptr1);
  cout << "修改以前:" << vptr1.get_vptr_val() << "," << vptr1.getv_val()
       << endl;
  vptr2.set_vptr_val(6);
  vptr2.setv_int(48);
  cout << "修改以后:" << vptr1.get_vptr_val() << "," << vptr1.getv_val()
       << endl;  //因为是深复制所以当vptr2的指针值改变后,不影响vptr1指针的值.
}

void test_BHasPtr() {
  int obj = 0;
  BHasPtr ptr1(&obj, 42);
  BHasPtr ptr2(ptr1);
  cout << "ptr1指针的值:" << ptr1.get_ptr_val() << "," << ptr1.get_int()
       << endl;
  cout << "ptr2指针的值:" << ptr2.get_ptr_val() << "," << ptr2.get_int()
       << endl;
  cout << "修改ptr2指针所指的值后" << endl;
  ptr2.set_ptr_val(2);
  ptr2.set_int(55);
  cout << "ptr1指针的值:" << ptr1.get_ptr_val() << "," << ptr1.get_int()
       << endl;
  cout << "ptr2指针的值:" << ptr2.get_ptr_val() << "," << ptr2.get_int()
       << endl;
}

int main() {
  cout << "常规指针:" << endl;
  test_AHasPtr();
  cout << "\n" << endl;
  cout << "值型类:" << endl;
  test_AHasPtr_value();
  cout << "\n" << endl;
  cout << "智能指针:" << endl;
  test_BHasPtr();
  return 0;
}
