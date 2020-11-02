#include <algorithm>
#include <iostream>
#include <set>
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

template <typename elementType>
class CMultiply {
 public:
  elementType operator()(const elementType& elem1, const elementType& elem2) {
    return elem1 * elem2;
  }
};

//二元谓词,大小写转换后进行比较,返回要一个bool值.
class CCompareStringNoCase {
 public:
  bool operator()(const string& str1, const string& str2) const {
    string str1LowerCase;
    str1LowerCase.resize(str1.size());
    transform(str1.begin(), str1.end(), str1LowerCase.begin(), tolower);
    string str2LowerCase;
    str2LowerCase.resize(str2.size());
    transform(str2.begin(), str2.end(), str2LowerCase.begin(), tolower);
    return (str1LowerCase < str2LowerCase);
  }
};

int main() {
  vector<int> vecIntegers;
  for (int i = 21; i < 27; ++i) vecIntegers.push_back(i);
  vector<int>::iterator iElement;
  iElement = find_if(
      vecIntegers.begin(), vecIntegers.end(),
      IsMultiple<int>(
          4));  // find_if标准库函数中第三个参数是一个bool类型的函数对象,当其返回真时,find_if返回一个值给迭代器对象
  if (iElement == vecIntegers.end())
    cout << "没有找到能被4整除的数" << endl;
  else
    cout << "第一个能被4整除的数是:\t" << *iElement << endl;

  vector<int> a, b, vecResult;
  for (int i = 0; i < 10; ++i) a.push_back(i);
  for (int j = 100; j < 110; ++j) b.push_back(j);
  vecResult.resize(10);
  // transform算法将两个容器中的元素逐个按参数5的方法做运算,参数1和参数3确定开始的范围,参数2确定结束的范围,参数4时一个接受结果的容器
  transform(a.begin(), a.end(), b.begin(), vecResult.begin(), CMultiply<int>());
  for (size_t nIndex = 0; nIndex < vecResult.size(); nIndex++)
    cout << vecResult[nIndex] << endl;

  set<string,CCompareStringNoCase> names;
  names.insert("Tina");
  names.insert("jim");
  names.insert("Jack");
  names.insert("Sam");
  names.insert("hello");

  set<string,CCompareStringNoCase>::iterator iNameFound = names.find("Jim");
  if (iNameFound != names.end())
    cout << *iNameFound << endl;
  else
    cout << "没有找到" << endl;
  return 0;
}
