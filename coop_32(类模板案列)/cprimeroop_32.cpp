/*案列描述:实现一个通用的数组类
1.可以对内置数据类型以及自定义数据类型的数据进行存储
2.将数组中的数据存储到堆区
3.构造函数中可以传入数组的容量
4.提供对应的拷贝构造函数以及拷贝赋值函数防止浅拷贝
5.提供尾插法和尾删法对数组中的数据进行增加和删除
7.可以通过下标的方式访问数组中的元素
8.可以获取数组中当前元素个数和数组的容量*/
#include "MyArray.hpp"
#include <iostream>
#include <string>
using namespace std;
class Person {
public:
  Person(){};
  Person(string name, int age);
  string getName() { return this->m_Name; }
  int getAge() { return this->m_Age; }

private:
  string m_Name;
  int m_Age;
};

void printIntArray(MyArray<int> &arr) {
  for (int i = 0; i < arr.getSize(); i++)
    cout << arr[i] << endl;
}

void printPersonArray(MyArray<Person> &arr) {
  for (int i = 0; i < arr.getSize(); i++)
    cout << "姓名: " << arr[i].getName() << "\t年龄: " << arr[i].getAge()
         << endl;
}

void test01() {
  MyArray<int> arr1(5); //有参构造函数测试
  for (int i = 0; i < 5; i++)
    arr1.Push_Back(i);
  cout << "arr1的打印输出为: " << endl;
  printIntArray(arr1);
  MyArray<int> arr2(arr1);
  cout << "arr2的打印输出为: " << endl;
  printIntArray(arr2);
  arr2.Pop_Back();
  cout << "arr2已删除一个元素:  " << endl;
  cout << "arr1的打印输出: " << endl;
  printIntArray(arr1);
  cout << "arr2的打印输出: " << endl;
  printIntArray(arr2);
}



Person::Person(string name, int age) : m_Name(name), m_Age(age) {}

void test02() {
  MyArray<Person> arr1(10);
  Person p1("孙悟空", 999);
  Person p2("韩信", 43);
  Person p3("妲己", 20);
  Person p4("赵云", 25);
  Person p5("安其拉", 27);
  //将数据插入到数组中
  arr1.Push_Back(p1);
  arr1.Push_Back(p2);
  arr1.Push_Back(p3);
  arr1.Push_Back(p4);
  arr1.Push_Back(p5);
  printPersonArray(arr1);
}

int main() {
  // test01();
  test02();
  system("pause");
  return 0;
}