#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void ofs_test() {
  ofstream ofs; //创建输出流对象
  ofs.open("test.txt", ios::out);
  ofs << "姓名:张华山" << endl;
  ofs << "性别:男" << endl;
  ofs << "年龄:20" << endl;
  ofs.close();
}

void ifs_test_1() {
  ifstream ifs;
  ifs.open("test.txt", ios::in);
  if (!ifs.is_open()) {
    cout << "文件打开失败" << endl;
    return;
  }
  char buf[1024] = {0};
  while (ifs >> buf) {
    cout << buf << endl;
  }
  ifs.close();
}

void ifs_test_2() {
  ifstream ifs;
  ifs.open("test.txt", ios::in);
  char buf[1024] = {0};
  while (ifs.getline(buf, sizeof(buf))) {
    cout << buf << endl;
  }
  ifs.close();
}
void ifs_test_3() {
  ifstream ifs;
  ifs.open("test.txt", ios::in);
  string buf;
  while (getline(ifs, buf)) {
    cout << buf << endl;
  }
  ifs.close();
}

void ifs_test_4() {
  ifstream ifs;
  ifs.open("test.txt", ios::in);
  char c;
  while ((c = ifs.get()) != EOF) {
    cout << c;
  } // EOF=end of file,ifs.get()为一个字节一个字节读取.
  ifs.close();
}

int main() {
  ofs_test();
  cout << "第一种文件输入方式:\n";
  ifs_test_1();
  cout << endl;
  cout << "第二种文件输入方式:\n";
  ifs_test_2();
  cout << endl;
  cout << "第三种文件输入方式:\n";
  ifs_test_3();
  cout << endl;
  cout << "第四种文件输入方式:\n";
  ifs_test_4();
  cout << endl;
  return 0;
}