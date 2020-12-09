/*函数模板->实例化->函数
模板形参 template<typename T>
template<class T>*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//常规写法,规定了类型,重用性低
int compare(const double &v1, const double &v2) {
  if (v1 < v2)
    return -1;
  if (v1 > v2)
    return 1;
  return 0;
}

//用函数模板的写法
template <typename T> int compare_1(const T &v1, const T &v2) {
  if (v1 < v2)
    return -1;
  if (v1 > v2)
    return 1;
  return 0;
}

template <class T> T absVal(T val) { return val > 0 ? val : -val; }

template <typename T1, typename T2> //函数的两个参数都为模板
T1 &print(T1 &s, T2 val) {
  s << val;
  return s;
}

template <class T> const T &bigger(const T &v1, const T &v2) {
  return v1 > v2 ? v1 : v2;
}

template <typename T> void MySwap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

// 1.自动类型推导,必须推导出一致的数据类型T才能使用.
void test01() {
  int a = 10;
  int b = 20;
  char c = 'c';
  // MySwap(a, c);//错误,推导不出一致的T类型
  MySwap(a, b);
  cout << "a=" << a << "\tb=" << b << endl;
}

// 2.模板必须要确定出T的数据类型,才可以使用
template <typename T> void func() { cout << "func" << endl; }

void test02() { // func();无法被调用,因为无法确定T的类型
  func<int>();  //可以调用,强制给出类型
}

int main() {
  double d1 = -1.23;
  double d2 = 9.56;
  string s1 = "hello";
  string s2 = "world";
  string oristr("this is a test");
  string desstr;
  ostringstream oss(desstr);
  ofstream outFile("result.dat");
  cout << compare(d1, d2) << endl;
  cout << compare_1(s1, s2) << endl;
  cout << absVal(d1) << endl;
  print(cout, s1) << endl;
  print(outFile, oristr);
  outFile.close();
  print(oss, s2);
  cout << oss.str() << endl;
  cout << bigger(d1, d2) << endl;
  cout << bigger(s1, s2) << endl;
  test01();
  return 0;
}