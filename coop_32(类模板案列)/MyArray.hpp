#pragma once
#include <iostream>
using namespace std;

template <class T> class MyArray {
public:
  //有参构造
  MyArray(int capacity) {
    this->m_Capacity = capacity;
    this->m_Size = 0;
    this->pAddress = new T[this->m_Capacity];
    cout << "MyArray的有参构造调用" << endl;
  }

  //拷贝构造
  MyArray(const MyArray &arr) {
    this->m_Capacity = arr.m_Capacity;
    this->m_Size = arr.m_Size;
    this->pAddress = new T[arr.m_Capacity];
    for (int i = 0; i < this->m_Size; i++) {
      this->pAddress[i] = arr.pAddress[i];
    }
    cout << "MyArray的拷贝构造调用" << endl;
  }

  //赋值函数
  MyArray &operator=(const MyArray &arr) {
    //先判断原来堆区是否有数据,如有有先释放
    if (this->pAddress != NULL) {
      delete[] this->pAddress;
      this->pAddress = NULL;
      this->m_Capacity = 0;
      this->m_Size = 0;
    }
    this->m_Capacity = arr.m_Capacity;
    this->m_Size = arr.m_Size;
    this->pAddress = new T[arr.m_Capacity];
    for (int i = 0; i < this->m_Size; i++)
      this->pAddress[i] = arr.pAddress[i];
    cout << "MyArray的赋值函数调用" << endl;
    return *this;
  }

  //尾插法
  void Push_Back(const T &val) { //判断目前容量是否等于数组最大容量
    if (this->m_Capacity == this->m_Size) {
      cout << "容量已满" << endl;
      return;
    }
    this->pAddress[this->m_Size] = val;
    this->m_Size++;
  }

  //尾删法
  void Pop_Back() { //判读目前是否有数据
    if (this->m_Size == 0)
      cout << "没有数据" << endl;
    //让用户访问不到最后一个数据,逻辑删除,非物理删除
    this->m_Size--;
  }

  //返回数组容量
  int getCapacity() { return this->m_Capacity; }

  //返回数组大小
  int getSize() { return this->m_Size; }

  //通过下标方式访问数组中的元素
  T& operator[](int num) {
    if (num < this->m_Size)
      return this->pAddress[num];
    else
      cout << "下标越界" << endl;
  }

  ~MyArray() {
    cout << "MyArry的析构函数调用" << endl;
    if (this->pAddress != NULL) {
      delete[] this->pAddress;
      this->pAddress = NULL;
    }
  }

private:
  T *pAddress;    //指针指向堆区开辟的真实数组
  int m_Capacity; //数组的容量
  int m_Size;     //数组大小
};