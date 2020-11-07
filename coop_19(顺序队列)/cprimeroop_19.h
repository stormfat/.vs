#pragma once
#ifndef _cprimeroop_19_H
#define _cprimeroop_19_H
#include <string>
using namespace std;

template <class T>
class Queue {
 public:
  Queue(int queueCapacity = 10);
  bool isEmpty() const;
  T& Front() const;
  T& Rear() const;
  void Push(const T& item);
  void Pop();

 private:
  T* queue;
  int front;
  int rear;
  int capacity;
};

template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity) {
  if (capacity < 1) throw "Queue capacity must be>0";
  queue = new T[capacity];
  front = rear = 0;
}

template <class T>
inline bool Queue<T>::isEmpty() const {
  return front == rear;
}

template <class T>
void Queue<T>::Push(const T& item) {
  if ((rear + 1) % capacity == front)  //检测队列是不是满了
  {
    T* newQueue = new T[2 * capacity];
    int start=(front + 1) % capacity;
    if (start < 2) copy(queue + start, queue + start + capacity - 1, newQueue);
    else {
      copy(queue + start, queue + capacity, newQueue);
      copy(queue, queue + rear + 1, newQueue + capacity -start);
    }
    front = 2 * capacity - 1;
    rear = capacity - 2;
    capacity *= 2;
    delete[] queue;
    queue = newQueue;
  }
  rear =
      (rear + 1) %
      capacity;  //检测是不是到达队尾了,如果已经达到队尾,rear+1和capactiy同值,取余运算后为0,rear指向队首.如果不为零,rear指向下一个位置.
  queue[rear] = item;
}

template <class T>
inline T& Queue<T>::Front() const {
  if (isEmpty()) throw "Queue is empty.No front element.";
  return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear() const {
  if (isEmpty()) throw "Queue is empty.No rear element";
  return queue[rear];
}

template <class T>
void Queue<T>::Pop() {
  if (isEmpty()) throw "Queue is empty.Cannot delete.";
  front = (front + 1) % capacity;
  queue[front].~T();
}
#endif