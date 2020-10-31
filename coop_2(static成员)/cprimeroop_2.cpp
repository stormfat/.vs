#include <iostream>
#include <string>
using namespace std;

class Account {
 public:
  Account(string name, double money) : owner(name), amount(money) {}

  double getAmount() { return this->amount; }
  void deposit(double money) { this->amount += money; }
  void applyint() { amount += amount * interestRate; }
  static double rate() { return interestRate; }
  static void rate(double rate) {
    interestRate = rate;
  }  //静态成员函数可以直接用类名操作.静态成语函数中不能用this指针

 private:
  string owner;  //普通变量,每个对象一个.
  double amount;
  static double
      interestRate;  //静态变量只有一个.类所建对象共享.静态变量不能在类中直接赋值
  static const int period = 30;  //静态常量可以在类中赋值
};

double Account::interestRate = 0.0123;  //静态变量初始化.

int main() {
  Account::rate(0.0013);  //用类直接操作静态成员函数.
  cout << "默认的rate:" << Account::rate() << endl;
  Account a("张三", 1000);
  a.deposit(500);
  Account b("李四", 2000);
  b.deposit(600);
  b.rate(0.015);
  cout << a.rate() << endl;
  b.applyint();
  cout << "b的账户总额:" <<b.getAmount()<<  endl;

  cout << a.getAmount() << endl;
  cout << b.getAmount() << endl;
  return 0;
}