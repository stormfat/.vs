#include "cprimeroop_20.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
  Queue<int> myQ;
  myQ.enqueue(10);
  myQ.enqueue(20);
  cout << myQ.getFront() << endl;
  myQ.dequeue();
  cout << myQ.getFront() << endl;
  for (int j = 0; j < 8; j++) {
    for (int i = 0; i < 8; i++) myQ.enqueue(i);
    while (!myQ.isEmpty()) cout << myQ.dequeue() << endl;
  }
  return 0;
}