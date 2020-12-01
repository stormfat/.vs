#include <fstream>
#include <iostream>
using namespace std;

class Person {
public:
  char m_Name[64];
  int m_Age;
};

void ofs_test() {
  ofstream ofs;
  ofs.open("person.txt", ios::out | ios::binary); //用二进制方式写文件
  Person p = {"张三", 18};
  ofs.write((const char *)&p, sizeof(Person));
  ofs.close();
}

void ifs_test() {
  ifstream ifs("person.txt", ios::in | ios::binary);
  if (!ifs.is_open()) {
    cout << "文件打开失败" << endl;
    return;
  }
  Person p;
  ifs.read((char *)&p, sizeof(Person));
  cout << "name:" << p.m_Name << "\tage:" << p.m_Age << endl;
  ifs.close();
}

int main() {
  ofs_test();
  ifs_test();
  return 0;
}