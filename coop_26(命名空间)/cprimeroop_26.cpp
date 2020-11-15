/*C++会将分散在不同文件的相同名称空间进行自动整合
名称空间的优点,可以在不同名称空间内声明和定义相同名字的类或方法.
名称空间也可以嵌套.
所有东西都在名称空间中,因为存在全局名称空间.*/

#include <iostream>
#include "bs.h"
using std::cout;//c++建议的名称空间引入的写法,避免一次将名称空间内所有内容都引入.
using std::endl;

namespace Myapp {
void processTrans() {}
}  // namespace Myapp

int main() {
  using namespace Myapp;
  namespace bs=bookStore;//名称空间别名的声明
  bs::Sales_item si;
  processTrans();
  cout << "测试通过" << endl;
  return 0;
}