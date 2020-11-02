#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

class absInt {
 public:
  int operator()(int val) { return val < 0 ? -val : val; }
};

template <typename elementType>  //普通函数
void FuncDisplayElement(const elementType& element) {
  cout << element << ' ' << endl;
}

template <typename elementType>  //函数对象
class DisplayElement {
 public:
  DisplayElement() : m_nCount(0) {}
  void operator()(const elementType& element) {
    ++m_nCount;
    cout << element << ' ';
  }
  int get_nCount() { return m_nCount; }

 private:
  int m_nCount;
};

int main() {
  int i = -42;
  absInt absObj;  //函数对象
  unsigned int ui = absObj(i);
  cout << ui << endl;
  vector<int> a;
  for (int n = 0; n < 10; ++n) a.push_back(n);
  list<char> b;
  for (char c = 'a'; c < 'k'; ++c) b.push_back(c);

  // STL算法
  DisplayElement<int> mResult;
  mResult =
      for_each(a.begin(), a.end(),
               mResult);  // for_each算法,参数1,2为迭代范围,参数3为显示迭代的值,并将状态返回给对象.
  cout << endl;
  cout << mResult.get_nCount() << endl;
  cout << endl;
  DisplayElement<char> cResult;
  cResult=for_each(b.begin(), b.end(),cResult);
  cout << endl;
  cout << cResult.get_nCount() << endl;
  cout << endl;

  cout << "hello 函数对象!" << endl;
  return 0;
}