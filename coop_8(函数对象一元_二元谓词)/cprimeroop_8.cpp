#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename numberType>
class IsMultiple {
 public:
  IsMultiple(const numberType& divisor) : m_Divisor(divisor) {}
  bool operator()(const numberType& element) const {
    return ((element % m_Divisor) == 0);
  }

 private:
  numberType m_Divisor;
};
int main() {
  vector<int> vecIntegers;
  for (int i = 21; i < 27; ++i) vecIntegers.push_back(i);
  vector<int>::iterator iElement;
  iElement = find_if(
      vecIntegers.begin(), vecIntegers.end(),
      IsMultiple<int>(
          4));  // find_if标准库函数中第三个参数是一个一元谓词,当一元谓词返回真时,find_if返回一个值给迭代器对象
  if (iElement == vecIntegers.end())
    cout << "没有找到能被4整除的数" << endl;
  else
    cout << "第一个能被4整除的数是:\t" << *iElement << endl;

  return 0;
}
