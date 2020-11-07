#include "cprimeroop_19.h"

#include <iostream>
using namespace std;

int main() {
  cout << "测试顺序队列" << endl;
  Queue<char> q(8);
  q.Push('a');
  q.Push('b');
  q.Push('c');
  q.Push('d');
  q.Push('e');
  q.Push('f');
  q.Push('g');
  q.Push('h');
  cout << q.Front() << "," << q.Rear() << endl;
  q.Pop();
  cout << q.Front() << "," << q.Rear() << endl;
  return 0;
}