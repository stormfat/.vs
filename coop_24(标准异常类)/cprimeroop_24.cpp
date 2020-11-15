/*bad_alloc异常类:内存耗尽异常*/

#include <iostream>
#include <new>
#include <string>
using namespace std;

class Student {
 public:
  Student(int age) : itsAge(0) {
    if (age < 0 || age > 150) throw out_of_range("年龄不能小于0或大于100");
    this->itsAge = age;
  }

 private:
  int itsAge;
};
class Dog {
 public:
  Dog() { parr = new int[1000000]; }  //

 private:
  int *parr;
};

int main() {
  Dog *pdog;
  try {
    for (int i = 1; i < 100; i++) {
      pdog = new Dog();
      cout << i << ":new Dog成功!" << endl;
    }
    Student st(-2);
  } catch (bad_alloc e) {
    cout << "new Dog失败:" << e.what() << endl;
  } catch (out_of_range e) {
    cout << e.what() << endl;
  }
  return 0;
}