#include "cprimeroop_18.h"

#include <iostream>

using namespace std;

int main() {
  Queue<char> q;//指定类模板的具体类型
  q.push('a');
  q.push('b');
  q.push('c');
  q.print();
  return 0;
}