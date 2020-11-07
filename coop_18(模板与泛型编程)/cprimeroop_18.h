#pragma once
#include <iomanip>
#include <iostream>

using namespace std;

template <class T>//使用类模板,用T代替类中的成员类型.在调用时可以用确定的类型进行替换.
class Queue {
 public:
  class Node {
   public:
    T a;
    Node* next;
  };
  Queue();
  void push(T b);
  void pop();
  int getlength();
  virtual void print();

 private:
  Node* head;
  Node* rear;
};

template <class T>
void Queue<T>::push(T b) {
  Node* p1 = new Node;
  p1->a = b;
  p1->next = NULL;
  rear->next = p1;
  rear = p1;
  head->a++;
  cout << setw(2) << b << setw(2) << "进入队列" << endl;
}

template <class T>
void Queue<T>::pop() {
  Node* p;
  p = head->next;
  cout << " " << setw(2) << p->a << setw(2) << "出队" << endl;
  head->next = p->next;
  delete p;
  head->a--;
}

template <class T>
int Queue<T>::getlength() {
  return head->a;
}

template <class T>
void Queue<T>::print() {
  Node* p;
  p = head->next;
  cout << "队列中的元素是:" << endl;
  while (p) {
    cout << p->a << "->";
    p = p->next;
  }
  cout << "NULL" << endl;
}

template <class T>
Queue<T>::Queue() {
  rear = head = new Node();
}