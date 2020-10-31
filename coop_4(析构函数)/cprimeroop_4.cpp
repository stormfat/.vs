#include <iostream>
#include <string>
using namespace std;

class NoName {
 public:
  NoName() : pstring(new string), i(0), d(0) {
    cout << "构造函数被调用\n" << endl;
  } /*通常在构造函数中打开文件,连接数据库,动态分配内存,然后在析构函数中关闭文件,关闭数据库连接,回收动态分配的内存*/

  NoName(const NoName &other)
      : pstring(new string(*(other.pstring))), i(other.i), d(other.d) {}

  NoName &operator=(const NoName &rhs) {
    pstring = new string;
    *pstring = *(rhs.pstring);
    i = rhs.i;
    d = rhs.d;
    return *this;
  }
  ~NoName();  //通常写了析构函数就要写复制构造函数和赋值操作符重载.
 private:
  string *pstring;
  int i;
  double d;
};

NoName::~NoName() {
  cout << "析构函数被调用了\n" << endl;
  delete pstring;
}  //因为pstring为new分配的指针,所以需要用delete销毁,放在析构函数中,当对象销毁时执行.

int main() {
  NoName a;
  NoName *p = new NoName;
  cout << "hello" << endl;
  delete p;  //删除指针对象时自动调用析构函数.
  return 0;  // return时调用a的析构函数.
}