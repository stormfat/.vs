#pragma once
#include <iostream>
using namespace std;

template <class T> class MyArray {
public:
  //�вι���
  MyArray(int capacity) {
    this->m_Capacity = capacity;
    this->m_Size = 0;
    this->pAddress = new T[this->m_Capacity];
    cout << "MyArray���вι������" << endl;
  }

  //��������
  MyArray(const MyArray &arr) {
    this->m_Capacity = arr.m_Capacity;
    this->m_Size = arr.m_Size;
    this->pAddress = new T[arr.m_Capacity];
    for (int i = 0; i < this->m_Size; i++) {
      this->pAddress[i] = arr.pAddress[i];
    }
    cout << "MyArray�Ŀ����������" << endl;
  }

  //��ֵ����
  MyArray &operator=(const MyArray &arr) {
    //���ж�ԭ�������Ƿ�������,���������ͷ�
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
    cout << "MyArray�ĸ�ֵ��������" << endl;
    return *this;
  }

  //β�巨
  void Push_Back(const T &val) { //�ж�Ŀǰ�����Ƿ���������������
    if (this->m_Capacity == this->m_Size) {
      cout << "��������" << endl;
      return;
    }
    this->pAddress[this->m_Size] = val;
    this->m_Size++;
  }

  //βɾ��
  void Pop_Back() { //�ж�Ŀǰ�Ƿ�������
    if (this->m_Size == 0)
      cout << "û������" << endl;
    //���û����ʲ������һ������,�߼�ɾ��,������ɾ��
    this->m_Size--;
  }

  //������������
  int getCapacity() { return this->m_Capacity; }

  //���������С
  int getSize() { return this->m_Size; }

  //ͨ���±귽ʽ���������е�Ԫ��
  T& operator[](int num) {
    if (num < this->m_Size)
      return this->pAddress[num];
    else
      cout << "�±�Խ��" << endl;
  }

  ~MyArray() {
    cout << "MyArry��������������" << endl;
    if (this->pAddress != NULL) {
      delete[] this->pAddress;
      this->pAddress = NULL;
    }
  }

private:
  T *pAddress;    //ָ��ָ��������ٵ���ʵ����
  int m_Capacity; //���������
  int m_Size;     //�����С
};