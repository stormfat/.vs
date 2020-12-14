/*��������:ʵ��һ��ͨ�õ�������
1.���Զ��������������Լ��Զ����������͵����ݽ��д洢
2.�������е����ݴ洢������
3.���캯���п��Դ������������
4.�ṩ��Ӧ�Ŀ������캯���Լ�������ֵ������ֹǳ����
5.�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
7.����ͨ���±�ķ�ʽ���������е�Ԫ��
8.���Ի�ȡ�����е�ǰԪ�ظ��������������*/
#include "MyArray.hpp"
#include <iostream>
#include <string>
using namespace std;
class Person {
public:
  Person(){};
  Person(string name, int age);
  string getName() { return this->m_Name; }
  int getAge() { return this->m_Age; }

private:
  string m_Name;
  int m_Age;
};

void printIntArray(MyArray<int> &arr) {
  for (int i = 0; i < arr.getSize(); i++)
    cout << arr[i] << endl;
}

void printPersonArray(MyArray<Person> &arr) {
  for (int i = 0; i < arr.getSize(); i++)
    cout << "����: " << arr[i].getName() << "\t����: " << arr[i].getAge()
         << endl;
}

void test01() {
  MyArray<int> arr1(5); //�вι��캯������
  for (int i = 0; i < 5; i++)
    arr1.Push_Back(i);
  cout << "arr1�Ĵ�ӡ���Ϊ: " << endl;
  printIntArray(arr1);
  MyArray<int> arr2(arr1);
  cout << "arr2�Ĵ�ӡ���Ϊ: " << endl;
  printIntArray(arr2);
  arr2.Pop_Back();
  cout << "arr2��ɾ��һ��Ԫ��:  " << endl;
  cout << "arr1�Ĵ�ӡ���: " << endl;
  printIntArray(arr1);
  cout << "arr2�Ĵ�ӡ���: " << endl;
  printIntArray(arr2);
}



Person::Person(string name, int age) : m_Name(name), m_Age(age) {}

void test02() {
  MyArray<Person> arr1(10);
  Person p1("�����", 999);
  Person p2("����", 43);
  Person p3("槼�", 20);
  Person p4("����", 25);
  Person p5("������", 27);
  //�����ݲ��뵽������
  arr1.Push_Back(p1);
  arr1.Push_Back(p2);
  arr1.Push_Back(p3);
  arr1.Push_Back(p4);
  arr1.Push_Back(p5);
  printPersonArray(arr1);
}

int main() {
  // test01();
  test02();
  system("pause");
  return 0;
}