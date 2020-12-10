#include <iostream>
#include <string>
using namespace std;
/*普通函数和函数模板调用规则:
1.如果函数模板和普通函数都可以实现,有限调用普通函数
2.可以通过空模板参数列表来强制调用函数模板
3.函数模板也可以重载
4.如果函数模板可以产生更好的匹配,优先调用函数模板*/


//交换的函数模板
template <typename T> void MySwap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

//排序的函数模板
/*规则:从大到小
  算法:冒泡算法
  测试:char数组,int数组*/

template <typename T> void MySort(T array[], int len) {
  for (int i = 0; i < len; i++) {
    int max = i;
    for (int j = i + 1; j < len; j++) {
      if (array[max] < array[j]) {
        max = j;
      }
    }
    if (max != i)
      MySwap(array[max], array[i]);
  }
}

//打印的函数模板
template <typename T> void PrintArray(T array[], int len) {
  for (int i = 0; i < len-1; i++) {
    cout << "Array[" << i << "]: " << array[i] << endl;
  }
}

//测试char数组
void test01() {
  char charArr[] = "badcfe";
  MySort(charArr, sizeof(charArr));
  PrintArray(charArr, sizeof(charArr));
}

//测试int数组
void test02() {
  int a[] = {7, 8, 4, 52, 13, 0};
  MySort(a, sizeof(a)/sizeof(int));
  PrintArray(a, sizeof(a)/sizeof(int));
}

int main() {
  test01();
  test02();
  system("pause");
  return 0;
}